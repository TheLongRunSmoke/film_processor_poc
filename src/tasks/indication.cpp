#include "indication.hpp"

void indication::task(void* pvParameters) {
    auto* state = (State*) pvParameters;
    pinMode(LED_BUILTIN, OUTPUT);
    for (;;) {
        // Check that status LED state is equivalent to current state.
        if (digitalRead(LED_BUILTIN) != state->isRunning) {
            digitalWrite(LED_BUILTIN, state->isRunning);
        }
        // Sleep for around 50ms.
        vTaskDelay(50 / portTICK_PERIOD_MS);
    }
}
