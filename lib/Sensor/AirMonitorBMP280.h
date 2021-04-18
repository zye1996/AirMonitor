//
// Created by Zhenyi Ye on 4/15/21.
//

#ifndef AIRMONITOR_AIRMONITORBMP280_H
#define AIRMONITOR_AIRMONITORBMP280_H

#include "GeneralSensor.h"
#include <Adafruit_BMP280.h>

class AirMonitorBMP280: public GeneralSensor {

public:
    explicit AirMonitorBMP280(uint8_t slaveAddr) : GeneralSensor(slaveAddr) {}
    void begin() override;
    bool read_sensor() override;
    bool setSps(uint16_t sps) override;

    friend class SensorHub;

private:
    Adafruit_BMP280 _bmp280;

};


#endif //AIRMONITOR_AIRMONITORBMP280_H
