//
// Created by Zhenyi Ye on 4/15/21.
//

#include "AirMonitorHTU21D.h"

void AirMonitorHTU21D::begin() {
    _htu21Df.begin();
}

bool AirMonitorHTU21D::read_sensor() {
    float temp = _htu21Df.readTemperature();
    float humidity = _htu21Df.readHumidity();

    if(_sensor_data.empty()){
        _sensor_data.insert(std::make_pair("HTU21D_TEMP", temp));
        _sensor_data.insert(std::make_pair("HTU21D_HUMI", humidity));
    }
    else{
        auto it = _sensor_data.find("HTU21D_TEMP");
        it->second = temp;

        it = _sensor_data.find("HTU21D_HUMI");
        it->second = humidity;
    }

    return true;
}

