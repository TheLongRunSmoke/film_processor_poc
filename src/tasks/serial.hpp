#ifndef FILM_PROCESSOR_MINIMAL_SERIAL_HPP
#define FILM_PROCESSOR_MINIMAL_SERIAL_HPP

#include "../core.hpp"

namespace serial {

    void task(void* pvParameters);

    static const char* name = "Serial";
}

#endif //FILM_PROCESSOR_MINIMAL_SERIAL_HPP
