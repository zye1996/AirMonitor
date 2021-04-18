//
// Created by Zhenyi Ye on 4/15/21.
//

#ifndef AIRMONITOR_AIRMONITORMICS6814_H
#define AIRMONITOR_AIRMONITORMICS6814_H

#include <Arduino.h>
#include "GeneralSensor.h"
#include "Adafruit_ADS1X15.h"

enum analog_sensor_mode{
    MODE_RAW,
    MODE_VOLTAGE,
    MODE_RESISTANCE
};

class AirMonitorMICS6814: public GeneralSensor {
public:
    explicit AirMonitorMICS6814(Adafruit_ADS1115 &ads1115, uint8_t heater_pin) :
        GeneralSensor(0x48), _ads1115(ads1115), _heater_pin(heater_pin){}
    void begin() override;
    bool read_sensor() override;
    bool setSps(uint16_t sps) override;

    void set_heater(bool);

    friend class SensorHub;

private:
    Adafruit_ADS1115 _ads1115;
    uint8_t _heater_pin;
    uint8_t _mode;

};


#endif //AIRMONITOR_AIRMONITORMICS6814_H
