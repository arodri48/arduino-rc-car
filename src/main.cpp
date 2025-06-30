#include <Arduino.h>
#include "TimeManager.h"
#include "RadarManager.h"
#include "MpuManager.h"
#include "MotorManager.h"
#include "CarControlManager.h"

TimeManager *timeManager;
RadarManager *radarManager;
MpuManager *mpuManager;
MotorManager *motorManager;
CarControlManager *carControlManger;


void setup() {
  timeManager = new TimeManager();
  radarManager = new RadarManager();
  mpuManager = new MpuManager();
  motorManager = new MotorManager();
  carControlManger = new CarControlManager(radarManager, motorManager, mpuManager, timeManager);
}

void loop() {
    timeManager->updateLoopTime();
    carControlManger->updateCarMotion();
}