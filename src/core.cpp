#include "core.hpp"
#include "../config.h"
#include "tasks/input.hpp"
#include "tasks/indication.hpp"
#include "tasks/serial.hpp"
#include "tasks/motorcontroller.hpp"

// This object represents current system state.
State state{};

// Run system.
void setup() {
    // Check CPU speed.
    configASSERT(F_CPU == 16000000L);

    xTaskCreate(indication::task,
                indication::name,
                128,
                (void*) &state,
                configMAX_PRIORITIES - 2,
                nullptr);

    xTaskCreate(user_input::task,
                user_input::name,
                128,
                (void*) &state,
                configMAX_PRIORITIES - 2,
                nullptr);

    xTaskCreate(serial::task,
                serial::name,
                128,
                (void*) &state,
                configMAX_PRIORITIES - 2,
                nullptr);

    xTaskCreate(motor_controller::controlTask,
                motor_controller::controlTaskName,
                128,
                (void*) &state,
                configMAX_PRIORITIES - 2,
                nullptr);

}

void loop() {
    // Nothing to do here.
}
