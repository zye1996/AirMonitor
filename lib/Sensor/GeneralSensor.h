//
// Created by Zhenyi Ye on 4/14/21.
//

#ifndef AIRMONITOR_GENERALSENSOR_H
#define AIRMONITOR_GENERALSENSOR_H

#include <Arduino.h>
#include <map>

class GeneralSensor{

public:
    explicit GeneralSensor(uint8_t slave_addr):_slave_addr(slave_addr){};
    ~GeneralSensor() = default;

    virtual void begin() = 0;
    virtual bool read_sensor() = 0;
    virtual bool setSps(uint16_t sps) {return false;};
    void print(HardwareSerial &serial){
        for(auto &p : _sensor_data)
            serial.printf("%s: %f\n", p.first.c_str(), p.second);
    };

protected:
    std::map<String, float> _sensor_data;
    uint8_t _slave_addr;

};

#endif //AIRMONITOR_GENERALSENSOR_H
