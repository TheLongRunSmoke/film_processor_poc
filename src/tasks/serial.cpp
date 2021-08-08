#include "serial.hpp"

void serial::task(void* pvParameters) {
    auto* state = (State*) pvParameters;
    // Init Arduino serial
    Serial.begin(9600);
    // Wait for serial port to connect. Needed for native USB, on LEONARDO, MICRO, YUN, and other 32u4 based boards.
    while (!Serial) {
        vTaskDelay(1);
    }
    // Extract the latest message and send it to serial port.
    for (;;) {
        char message[8];
        if (xQueueReceive(state->messageQueue, message, (TickType_t) 10) != pdPASS) continue;
        Serial.println(message);
    }
}
