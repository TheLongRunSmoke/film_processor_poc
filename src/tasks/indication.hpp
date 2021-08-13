#ifndef FILM_PROCESSOR_MINIMAL_INDICATION_HPP
#define FILM_PROCESSOR_MINIMAL_INDICATION_HPP

#include "../core.hpp"

/**
 * Indication task.
 */
namespace indication {

    /**
     * Configure outputs and endlessly looping to poling State and show it.
     *
     * @param pvParameters castable to pointer on State instance.
     */
    void task(void* pvParameters);

    /**
     * Human-readable name for task.
     */
    static const char* name = "Indication";
}

#endif //FILM_PROCESSOR_MINIMAL_INDICATION_HPP
