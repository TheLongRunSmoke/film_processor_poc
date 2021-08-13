#ifndef FILM_PROCESSOR_MINIMAL_CORE_HPP
#define FILM_PROCESSOR_MINIMAL_CORE_HPP

#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <queue.h>

/**
 * System state storage.
 *
 * Map it statically and provide to tasks as pointer.
 */
struct State {
    /**
     * Run motor or not.
     */
    bool isRunning = false;
    /**
     * Messages. Serial task get them one by one and send to the port.
     */
    QueueHandle_t messageQueue = xQueueCreate(4, sizeof(char[8]));
};

#endif //FILM_PROCESSOR_MINIMAL_CORE_HPP