#include "input.hpp"
#include "../../config.h"

void user_input::task(void* pvParameters) {
    // Receive pointer on object that represent system state.
    auto* state = (State*) pvParameters;
    // Prepare inputs.
    pinMode(ACTION_BUTTON_PIN, (ACTION_BUTTON_ACTIVE_LEVEL == HIGH) ? INPUT : INPUT_PULLUP);
    // Attach interrupt for Arduino digital pin
    attachInterrupt(digitalPinToInterrupt(ACTION_BUTTON_PIN), interruptHandler, CHANGE);
    for (;;) {
        handleInput(state);
        // 50 ms delay for debounce.
        vTaskDelay(50 / portTICK_PERIOD_MS);
    }
}

void user_input::interruptHandler() {
    xSemaphoreGiveFromISR(semaphore, NULL);
}

void user_input::handleInput(State* state) {
    if (xSemaphoreTake(semaphore, portMAX_DELAY) != pdPASS) return;
    bool buttonState = digitalRead(ACTION_BUTTON_PIN);
    if (buttonState != ACTION_BUTTON_ACTIVE_LEVEL) return;
    state->isRunning = !state->isRunning;
    xQueueSend(state->messageQueue, state->isRunning ? "start" : "stop", portMAX_DELAY);
}
