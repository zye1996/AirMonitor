//
// Created by Zhenyi Ye on 4/15/21.
//

#include "AirMonitorMICS6814.h"

void AirMonitorMICS6814::begin() {
    pinMode(_heater_pin, OUTPUT);
    set_heater(true);
}

void AirMonitorMICS6814::set_heater(bool state) {
    if (state)
        digitalWrite(_heater_pin, HIGH);
    else
        digitalWrite(_heater_pin, LOW);
}

bool AirMonitorMICS6814::read_sensor() {
    if (_sensor_data.empty()){
        _sensor_data.insert(std::make_pair("MICS6814_NO2", _ads1115.computeVolts(_ads1115.readADC_SingleEnded(0))));
        _sensor_data.insert(std::make_pair("MICS6814_CO", _ads1115.computeVolts(_ads1115.readADC_SingleEnded(1))));
        _sensor_data.insert(std::make_pair("MICS6814_NH3", _ads1115.computeVolts(_ads1115.readADC_SingleEnded(2))));
    }
    else{
        auto it = _sensor_data.find("MICS6814_NO2");
        it->second = _ads1115.computeVolts(_ads1115.readADC_SingleEnded(0));
        it = _sensor_data.find("MICS6814_CO");
        it->second = _ads1115.computeVolts(_ads1115.readADC_SingleEnded(1));
        it = _sensor_data.find("MICS6814_NH3");
        it->second = _ads1115.computeVolts(_ads1115.readADC_SingleEnded(2));
    }

    return true;
}

bool AirMonitorMICS6814::setSps(uint16_t sps) {
    _ads1115.setDataRate(sps);
}