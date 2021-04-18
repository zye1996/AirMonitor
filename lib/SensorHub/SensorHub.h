//
// Created by Zhenyi Ye on 3/12/21.
//

#ifndef AIRMONITOR_SENSORHUB_H
#define AIRMONITOR_SENSORHUB_H

#include <vector>
#include "GeneralSensor.h"
#include "config.h"

class SensorHub {

public:
    SensorHub()= default;
    ~SensorHub()= default;

    void begin();
    void readCCS811();

private:
    std::vector<>


};

#endif //AIRMONITOR_SENSORHUB_H
