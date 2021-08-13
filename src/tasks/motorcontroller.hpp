#ifndef FILM_PROCESSOR_MINIMAL_STEPPER_HPP
#define FILM_PROCESSOR_MINIMAL_STEPPER_HPP

#include "../core.hpp"
#include "../../config.h"

/**
 * Handle all tasks that need to make stepper rotate in proper way.
 */
namespace motor_controller {

    /**
     * Control cycle task.
     *
     * Start and stop reciprocatingSCurveTask() as system state change.
     *
     * @param pvParameters pointer on State instance.
     */
    void controlTask(void* pvParameters);

    /**
     * Run motor as configured.
     *
     * Make given number of turn with given speed, than alternate direction.
     *
     * @param pvParameters nothing.
     */
    void reciprocatingSCurveTask(void* pvParameters);

    /**
     * Run in calibration mode instead of controlTask().
     *
     * Rotate motor until user hold action button and write step count to serial console.
     *
     * @param pvParameters pointer on State instance.
     */
    void calibrationTask(void* pvParameters);

    /**
     * Call in timer overflow interrupt.
     */
    void handlePwmCycle();

    /**
     * Control motor acceleration and deceleration by sigmoid curve.
     *
     * Calculate and set current PWM frequency and duty cycle.
     */
    void sCurve();

    /**
     * Bring all hardware to safe state.
     */
    void clear();

    /**
     * Prepare outputs and setup PWM mode.
     */
    void config();

    /**
     * Current step from last direction alteration.
     */
    static volatile unsigned long currentStep = 0;
    /**
     * Minimal frequency where motor start.
     */
    static const uint16_t minFreq = 1000;
    /**
     * Sigmoid coefficient, typically between -4 and -6.
     */
    static float elastic = -ELASTIC;
    /**
     * How many steps must be doing before alternate direction of rotation.
     */
    static unsigned long targetStepNumber = 0;
    /**
     * Frequency to go, to achieve RPM from config.
     */
    static float targetFreq = 0;
    /**
     * Cache frequency delta, that used in sigmoid formula.
     */
    static float freqDelta = 0;
    /**
     * Acceleration and deceleration length in motor steps.
     */
    static float accelRamp = floor(RATIO * (float) RAMP);

    /**
     * Human-readable names for tasks.
     */
    static const char* controlTaskName = "MotorController";
    static const char* reciprocatingSCurveTaskName = "ReciprocatingSCurve";
    static const char* calibrationTaskName = "CalibrationTask";
}

#endif //FILM_PROCESSOR_MINIMAL_STEPPER_HPP
