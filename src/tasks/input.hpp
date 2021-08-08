#ifndef FILM_PROCESSOR_MINIMAL_INPUT_HPP
#define FILM_PROCESSOR_MINIMAL_INPUT_HPP

#include "../core.hpp"
#include <semphr.h>

/**
 * Handle user input.
 */
namespace user_input {

    void task(void* pvParameters);

    void interruptHandler();

    void handleInput(State* state);

    static const char* name = "InputTask";
    static const uint8_t priority = 3;

    static SemaphoreHandle_t semaphore = xSemaphoreCreateBinary();
}

#endif //FILM_PROCESSOR_MINIMAL_INPUT_HPP
