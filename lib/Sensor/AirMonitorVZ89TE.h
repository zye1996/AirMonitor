//
// Created by Zhenyi Ye on 4/15/21.
//

#ifndef AIRMONITOR_AIRMONITORVZ89TE_H
#define AIRMONITOR_AIRMONITORVZ89TE_H

#include "GeneralSensor.h"

#define MICS_VZ_89TE_ADDR_CMD_GETSTATUS	0x0C	// This command is used to read the VZ89 status coded with 6 bytes:
#define MICS_VZ_89TE_DATE_CODE 0x0D

class AirMonitorVZ89TE : public GeneralSensor{
public:
    explicit AirMonitorVZ89TE(uint8_t slaveAddr=0x70) : GeneralSensor(slaveAddr) {}
    void begin() override;
    bool read_sensor() override;

    friend class SensorHub;

private:
    using GeneralSensor::setSps;
};


#endif //AIRMONITOR_AIRMONITORVZ89TE_H
