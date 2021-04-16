//
// Created by Zhenyi Ye on 4/14/21.
//

#include "AirMonitorCCS811.h"

void AirMonitorCCS811::begin(){
    _ccs811.begin(_slave_addr);
    _ccs811.setDriveMode(CCS811_DRIVE_MODE_1SEC);
}

bool AirMonitorCCS811::read_sensor() {

    bool ret = _ccs811.readData();

    if(ret == 0){
        if(_sensor_data.empty()){
            _sensor_data.insert(std::make_pair("CCS811_ETVOC", _ccs811.getTVOC()));
            _sensor_data.insert(std::make_pair("CCS811_ECO2", _ccs811.geteCO2()));
            _sensor_data.insert(std::make_pair("CCS811_RAW", _ccs811.getRawADCreading()));
        }
        else{
            auto it = _sensor_data.find("CCS811_ETVOC");
            it->second = _ccs811.getTVOC();
            it = _sensor_data.find("CCS811_ECO2");
            it->second = _ccs811.geteCO2();
            it = _sensor_data.find("CCS811_RAW");
            it->second = _ccs811.getRawADCreading();
        }
    }
    return true;
}

bool AirMonitorCCS811::setSps(uint16_t sps) {
    if(sps != CCS811_DRIVE_MODE_1SEC &&
        sps != CCS811_DRIVE_MODE_10SEC &&
        sps != CCS811_DRIVE_MODE_60SEC)
        return false;
    else{
        _ccs811.setDriveMode(sps);
    }
}

void AirMonitorCCS811::print(HardwareSerial &serial) {
    for(auto &p : _sensor_data)
        serial.printf("%s: %f\n", p.first.c_str(), p.second);
}