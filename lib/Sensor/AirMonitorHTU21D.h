//
// Created by Zhenyi Ye on 4/15/21.
//

#ifndef AIRMONITOR_AIRMONITORHTU21D_H
#define AIRMONITOR_AIRMONITORHTU21D_H

#include "GeneralSensor.h"
#include <Adafruit_HTU21DF.h>

class AirMonitorHTU21D: public GeneralSensor {
public:
    explicit AirMonitorHTU21D(uint8_t slaveAddr=0x40) : GeneralSensor(slaveAddr) {}
    void begin() override;
    bool read_sensor() override;

    friend class SensorHub;

private:
    Adafruit_HTU21DF _htu21Df;

    using GeneralSensor::setSps;

};


#endif //AIRMONITOR_AIRMONITORHTU21D_H
