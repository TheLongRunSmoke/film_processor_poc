#include "motorcontroller.hpp"

void motor_controller::controlTask(void* pvParameters) {
    auto* state = (State*) pvParameters;

    TaskHandle_t motorTask = nullptr;

    for (;;) {
        if (state->isRunning && motorTask == nullptr) {
            xTaskCreate(motor_controller::reciprocatingSCurveTask,
                        motor_controller::reciprocatingSCurveTaskName,
                        128,
                        nullptr,
                        configMAX_PRIORITIES - 2,
                        &motorTask);
        } else if (!state->isRunning && motorTask != nullptr) {
            vTaskDelete(motorTask);
            motorTask = nullptr;
            clear();
        }
        vTaskDelay(50 / portTICK_PERIOD_MS);
    }
}

ISR(TIMER1_OVF_vect){
        motor_controller::handlePwmCycle();
}

void motor_controller::handlePwmCycle() {
    noInterrupts();
    currentStep++;
    sCurve();
    if (currentStep > targetStepNumber) {
        currentStep = 0;
        digitalWrite(DIRECTION_PIN, !digitalRead(DIRECTION_PIN));
    }
    interrupts();
}

void motor_controller::reciprocatingSCurveTask(void* pvParameters) {
    (void) pvParameters;
    config();
    currentStep = 0;
    // Compute all const parameters.
    targetStepNumber = RATIO * TURNS * MICROSTEP_MODE;
    targetFreq = (RPM / 60.0 * RATIO) * MICROSTEP_MODE;
    freqDelta = targetFreq - minFreq;
    // We have nothing to do here, so let scheduler visit this task less often.
    for (;;) {
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}

void motor_controller::sCurve() {
    elastic = -ELASTIC;
    unsigned long step = currentStep;
    if (currentStep > targetStepNumber - (long) (accelRamp * 2)) {
        elastic = -elastic;
        step = currentStep - (targetStepNumber - (long) (accelRamp * 2));
    }
    uint16_t currentFreq = minFreq + freqDelta / (1 + exp(elastic * (step - accelRamp) / accelRamp));
    ICR1 = F_CPU / currentFreq;
    // Pololu compatible driver typically need ~2us impulse to generate a step.
    float dutyCycle = 2e-6 / (1.0 / currentFreq);
    OCR1A = ICR1 * dutyCycle + 1;
}

void motor_controller::clear() {
    noInterrupts();
    digitalWrite(ENABLE_PIN, HIGH);
    digitalWrite(DIRECTION_PIN, LOW);
    TCCR1A = 0;
    TCCR1B = 0;
    TIMSK1 = 0;
    TCNT1 = 0;
    digitalWrite(STEP_PIN, LOW);
    interrupts();
}

void motor_controller::calibrationTask(void* pvParameters) {
    auto* state = (State*) pvParameters;
    // Omitted for now.
}

void motor_controller::config() {
    noInterrupts();
    // Configure output pins.
    pinMode(ENABLE_PIN, OUTPUT);
    pinMode(DIRECTION_PIN, OUTPUT);
    digitalWrite(DIRECTION_PIN, LOW);
    pinMode(STEP_PIN, OUTPUT);
    // Reset and configure timer.
    TCCR1A = 0;
    TCCR1B = 0;
    TIMSK1 = 0;
    TCNT1 = 0;
    // On Atmega 328 it's mode 14, no prescaling.
    TCCR1A = (1 << COM1A1) | (1 << WGM11);
    TCCR1B = (1 << WGM12) | (1 << WGM13) | (1 << CS10);
    // ICR1 now is timer top, set it to max.
    ICR1 = 0xFFFF;
    // OCR1A set to small safe value.
    OCR1A = ICR1 * 0.02;
    // Enable overflow interrupt.
    TIMSK1 = (1 << TOIE1);
    // Power driver output. Set this to HIGH if you need to test something without motor moving.
    digitalWrite(ENABLE_PIN, LOW);
    interrupts();
}
