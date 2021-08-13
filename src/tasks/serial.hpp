#ifndef FILM_PROCESSOR_MINIMAL_SERIAL_HPP
#define FILM_PROCESSOR_MINIMAL_SERIAL_HPP

#include "../core.hpp"

/**
 * Handle messages queue in State object and print them to serial port.
 */
namespace serial {

    /**
    * Configure serial port and endlessly try to get element put of queue, when succeed send it to the port.
    *
    * @param pvParameters castable to pointer on State instance.
    */
    void task(void* pvParameters);

    /**
     * Human-readable name for task.
     */
    static const char* name = "Serial";
}

#endif //FILM_PROCESSOR_MINIMAL_SERIAL_HPP
