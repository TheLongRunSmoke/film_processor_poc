#ifndef FILM_PROCESSOR_MINIMAL_INPUT_HPP
#define FILM_PROCESSOR_MINIMAL_INPUT_HPP

#include "../core.hpp"
#include <semphr.h>

/**
 * Handle user input.
 */
namespace user_input {

    /**
     * Configure inputs and endlessly looping to process inputs.
     *
     * @param pvParameters castable to pointer on State instance.
     */
    void task(void* pvParameters);

    /**
     * Set semaphore on interrupt.
     */
    void interruptHandler();

    /**
     * If interrupt fire, poling inputs and modified State.
     *
     * @param state pointer to State instance.
     */
    void handleInput(State* state);

    /**
     * Human-readable name for task.
     */
    static const char* name = "InputTask";

    /**
     * Interrupt semaphore.
     */
    static SemaphoreHandle_t semaphore = xSemaphoreCreateBinary();
}

#endif //FILM_PROCESSOR_MINIMAL_INPUT_HPP
