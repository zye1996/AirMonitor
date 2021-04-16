#include <sdkconfig.h>
#include <Wire.h>
#include <WiFi.h>
#include <WiFiManager.h>
#include "AirMonitorCCS811.h"

AirMonitorCCS811 ccs811(0x5B);


void setup() {
    Wire.begin(25, 21, 10000);
    Serial.begin(115200);
    ccs811.begin();
}

void loop() {
    ccs811.read_sensor();
    ccs811.print(Serial);
    delay(1000);
}