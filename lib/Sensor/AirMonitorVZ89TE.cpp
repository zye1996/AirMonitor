//
// Created by Zhenyi Ye on 4/15/21.
//

#include "AirMonitorVZ89TE.h"
#include <Wire.h>

void AirMonitorVZ89TE::begin() {

}


bool AirMonitorVZ89TE::read_sensor() {

    static uint8_t data[7];

    uint8_t i =0;
    Wire.beginTransmission((uint8_t)_slave_addr);
    Wire.write((uint8_t)MICS_VZ_89TE_ADDR_CMD_GETSTATUS); //This send the command to get data
    Wire.write(0x0);
    Wire.write(0x0);
    Wire.write(0x0);
    Wire.write(0x0);
    Wire.write(0x0);
    Wire.endTransmission();

    Wire.beginTransmission(0xE1);
    Wire.endTransmission();

    Wire.requestFrom((uint8_t)_slave_addr, (byte)7);
    for (i=0; i<7; i++) {
        data[i] = Wire.read();
    }

    uint8_t status = data[5];

    float co2 = (data[1] - 13) * (1600.0 / 229) + 400; // ppm: 400 .. 2000
    float voc = (data[0] - 13) * (1000.0/229); // ppb: 0 .. 1000

    if(_sensor_data.empty()){
        _sensor_data.insert(std::make_pair("VZ89TE_ETVOC", voc));
        _sensor_data.insert(std::make_pair("VZ89TE_ECO2", co2));
    }
    else{
        auto it = _sensor_data.find("VZ89TE_ETVOC");
        it->second = voc;
        it = _sensor_data.find("VZ89TE_ECO2");
        it->second = co2;
    }

}

