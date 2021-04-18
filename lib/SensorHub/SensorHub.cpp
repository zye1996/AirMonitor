//
// Created by Zhenyi Ye on 3/12/21.
//

#include "SensorHub.h"

void SensorHub::begin() {
    auto it = _sensor.begin();

#ifdef ENABLE_CCS811
    it = _sensor.insert(it, sensor_t(new AirMonitorCCS811()));
#endif

#ifdef ENABLE_BMP280
    it = _sensor.insert(it, sensor_t(new AirMonitorBMP280(0x77)));
#endif

#ifdef ENABLE_HTU21D
    it = _sensor.insert(it, sensor_t(new AirMonitorHTU21D));
#endif

#ifdef ENABLE_VZ89TE
    it = _sensor.insert(it, sensor_t(new AirMonitorVZ89TE()));
#endif

#ifdef ENAGLE_MICS6814
    ads1115.begin();
    it = _sensor.insert(it, sensor_t(new AirMonitorMICS6814(ads1115, 19)));
#endif

    for (auto &p : _sensor){
        p->begin();
    }
}

void SensorHub::update() {
    for (auto &p : _sensor){
        p->read_sensor();
    }
}

void SensorHub::print(HardwareSerial &serial){
    for (auto &p : _sensor){
        p->print(serial);
    }
}



