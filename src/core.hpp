#ifndef FILM_PROCESSOR_MINIMAL_CORE_HPP
#define FILM_PROCESSOR_MINIMAL_CORE_HPP

#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <queue.h>

struct State {
    bool isRunning = false;
    bool isActionButtonPressed = false;
    QueueHandle_t messageQueue = xQueueCreate(4, sizeof(char[8]));
};

#endif //FILM_PROCESSOR_MINIMAL_CORE_HPP