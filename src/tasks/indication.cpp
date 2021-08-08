#include "indication.hpp"

void indication::task(void* pvParameters) {
    auto* state = (State*) pvParameters;
    pinMode(LED_BUILTIN, OUTPUT);
    for (;;) {
        if (digitalRead(LED_BUILTIN) != state->isRunning) {
            digitalWrite(LED_BUILTIN, state->isRunning);
        }
        vTaskDelay(50 / portTICK_PERIOD_MS);
    }
}
