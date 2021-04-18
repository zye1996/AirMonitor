#include <sdkconfig.h>
#include <Wire.h>
#include <WiFi.h>
#include <WiFiManager.h>
#include "SensorHub.h"

WiFiManager wifiManager;
SensorHub sensorHub;

void setup() {

    wifiManager.autoConnect("AirMonitor");

    Wire.begin(25, 21);
    Serial.begin(115200);
    sensorHub.begin();
}

void loop() {
    sensorHub.update();
    sensorHub.print(Serial);
    delay(1000);
}