#include "RadarManager.h"

RadarManager::RadarManager()
{
    ultrasonic = new Ultrasonic(TRIG_PIN, ECHO_PIN);
}

uint16_t RadarManager::getDistance()
{
    return (uint16_t)ultrasonic->read();
}
