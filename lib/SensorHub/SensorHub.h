//
// Created by Zhenyi Ye on 3/12/21.
//

#ifndef AIRMONITOR_SENSORHUB_H
#define AIRMONITOR_SENSORHUB_H

#include <map>
#include <ccs811.h>
#include "config.h"

class SensorHub {

    public:
        SensorHub()= default;
        ~SensorHub()= default;

        void begin();
        void readCCS811();

#ifdef ENABLE_CCS811
        CCS811 ccs811 = CCS811();
#endif



};

#endif //AIRMONITOR_SENSORHUB_H
