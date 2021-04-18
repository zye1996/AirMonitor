//
// Created by Zhenyi Ye on 4/15/21.
//

#include "AirMonitorBMP280.h"

void AirMonitorBMP280::begin() {
    _bmp280.begin(_slave_addr);
}

bool AirMonitorBMP280::read_sensor() {
    float temp = _bmp280.readTemperature();
    float pressure = _bmp280.readPressure();

    if(_sensor_data.empty()){
        _sensor_data.insert(std::make_pair("BMP280_TEMP", temp));
        _sensor_data.insert(std::make_pair("BMP280_PRES", pressure));
    }
    else{
        auto it = _sensor_data.find("BMP280_TEMP");
        it->second = temp;

        it = _sensor_data.find("BMP280_PRES");
        it->second = pressure;
    }

    return true;
}

bool AirMonitorBMP280::setSps(uint16_t sps) {
    if(sps <= 5 && sps >= 0)
        _bmp280.setSampling(Adafruit_BMP280::MODE_NORMAL,
                            static_cast<Adafruit_BMP280::sensor_sampling>(sps),
                            static_cast<Adafruit_BMP280::sensor_sampling>(sps),
                            Adafruit_BMP280::FILTER_OFF,
                            Adafruit_BMP280::STANDBY_MS_1);
}