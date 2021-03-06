#include <Arduino.h>
#include "base.hpp"

using namespace sakurajin::unit_system::base;
using namespace sakurajin::unit_system::base::literals;

const int LED = 25;
time_si delta_t = 500_ms;

void setup() {
    pinMode(LED, OUTPUT);
}

void loop() {
    digitalWrite(LED, HIGH);
    delay(delta_t.value);

    digitalWrite(LED, LOW);
    delay(delta_t.value);
}
