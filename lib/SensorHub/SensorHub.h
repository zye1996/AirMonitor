//
// Created by Zhenyi Ye on 3/12/21.
//

#ifndef AIRMONITOR_SENSORHUB_H
#define AIRMONITOR_SENSORHUB_H

#include <vector>
#include <memory>
#include <Adafruit_ADS1X15.h>
#include "AirMonitorCCS811.h"
#include "AirMonitorBMP280.h"
#include "AirMonitorHTU21D.h"
#include "AirMonitorVZ89TE.h"
#include "AirMonitorMICS6814.h"
#include "config.h"

class SensorHub {

public:
    typedef std::unique_ptr<GeneralSensor> sensor_t;

    SensorHub()= default;
    ~SensorHub()= default;

    void begin();
    void update();
    void print(HardwareSerial &serial);

private:
    Adafruit_ADS1115 ads1115;
    std::vector<sensor_t> _sensor;


};

#endif //AIRMONITOR_SENSORHUB_H
