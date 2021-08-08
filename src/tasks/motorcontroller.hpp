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
     * Accelerate and decelerate motor by sigmoid curve.
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

    static volatile unsigned long currentStep = 0;

    static const uint16_t minFreq = 1000;
    static float elastic = -ELASTIC;
    static unsigned long targetStepNumber = 0;
    static float targetFreq = 0;
    static float freqDelta = 0;
    static float accelRamp = floor(RATIO * (float) RAMP);

    // Debug names for tasks.
    static const char* controlTaskName = "MotorController";
    static const char* reciprocatingSCurveTaskName = "ReciprocatingSCurve";
    static const char* calibrationTaskName = "CalibrationTask";
}

#endif //FILM_PROCESSOR_MINIMAL_STEPPER_HPP
