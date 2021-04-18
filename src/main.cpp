#include <sdkconfig.h>
#include <Wire.h>
#include <WiFi.h>
#include <WiFiManager.h>
#include "AirMonitorCCS811.h"
#include "AirMonitorBMP280.h"
#include "AirMonitorHTU21D.h"
#include "AirMonitorVZ89TE.h"

AirMonitorCCS811 ccs811(0x5B);
AirMonitorBMP280 bmp280(0x77);
AirMonitorHTU21D htu21d;
AirMonitorVZ89TE vz89Te;

void setup() {
    Wire.begin(25, 21);
    Serial.begin(115200);
    ccs811.begin();
    bmp280.begin();
    htu21d.begin();
    vz89Te.begin();
}

void loop() {
    ccs811.read_sensor();
    bmp280.read_sensor();
    htu21d.read_sensor();
    vz89Te.read_sensor();
    ccs811.print(Serial);
    bmp280.print(Serial);
    htu21d.print(Serial);
    vz89Te.print(Serial);
    delay(1000);
}