#include "TimeManager.h"

TimeManager::TimeManager()
{
    startingTime = millis();
    loopTime = startingTime;
    loopCount = 0;
    loopMinDuration = 1000;
    loopMaxDuration = 0;
}

void TimeManager::updateLoopTime()
{
    previousLoopTime = loopTime;
    loopTime = millis();
    loopCount++;
    if (loopMinDuration > (loopTime - previousLoopTime))
    {
        loopMinDuration = (loopTime - previousLoopTime);
    }
    if (loopMaxDuration < (loopTime - previousLoopTime))
    {
        loopMaxDuration = (loopTime - previousLoopTime);
    }
}

unsigned long TimeManager::getLoopTime()
{
    return loopTime;
}

float TimeManager::getLoopAverageDuration()
{
    return (millis() - startingTime) / loopCount;
}