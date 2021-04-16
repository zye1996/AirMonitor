//
// Created by Zhenyi Ye on 4/14/21.
//

#ifndef AIRMONITOR_AIRMONITORCCS811_H
#define AIRMONITOR_AIRMONITORCCS811_H

#include "GeneralSensor.h"
#include "SensorHub.h"
#include <Adafruit_CCS811.h>

class AirMonitorCCS811: public GeneralSensor {
public:
    explicit AirMonitorCCS811(uint8_t slaveAddr) : GeneralSensor(slaveAddr) {}
    void begin() override;
    bool read_sensor() override;
    bool setSps(uint16_t sps) override;
    void print(HardwareSerial &serial) override;

    friend class SensorHub;

private:
    Adafruit_CCS811 _ccs811;
    uint16_t _raw, _eco2, _etvoc;
};


#endif //AIRMONITOR_AIRMONITORCCS811_H
