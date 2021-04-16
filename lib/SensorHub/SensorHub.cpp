//
// Created by Zhenyi Ye on 3/12/21.
//

#include "SensorHub.h"

void SensorHub::begin() {
#ifdef ENABLE_CCS811
    ccs811.begin();
#endif
}

void SensorHub::readCCS811() {

}


