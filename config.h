#ifndef FILM_PROCESSOR_MINIMAL_CONFIG_H
#define FILM_PROCESSOR_MINIMAL_CONFIG_H

/**
 * Rotation mode.
 *
 * Main working mode, start/stop on action button press.
 * Rotate development tank with specified speed by specified number of turn in one direction than alternate.
 *
 * RATIO - number of motor steps to one rotation of development tank, see calibration section fore details.
 * SPEED - number of turns per minute for tank.
 * TURNS - number of turns in one direction.
 */
#define RATIO 855
#define RPM 60
#define TURNS 3

/**
 * Buttons configuration.
 *
 * POC has only one TTP223 button, active level high.
 */
#define ACTION_BUTTON_PIN 2
#define ACTION_BUTTON_ACTIVE_LEVEL HIGH

/**
 * Stepper motor configuration.
 *
 * STEP_PIN use PWM output! Do not touch it, unless you know what you doing.
 */
#define STEP_PIN 9
#define DIRECTION_PIN 7
#define ENABLE_PIN 6
#define MICROSTEP_MODE 2

/**
 * S-curve config.
 *
 * System use sigmoid function to accelerate and decelerate stepper.
 * If you have problems with chattering try to adjust motor current first.
 *
 * ELASTIC how fast motor accelerate, normally it must be between 4.0 and 6.0. Decrease to prevent chattering.
 * RAMP how long motor accelerate. Part of one turn. Increase to prevent chattering.
 */
#define ELASTIC 4.0
#define RAMP 0.25


#endif //FILM_PROCESSOR_MINIMAL_CONFIG_H
