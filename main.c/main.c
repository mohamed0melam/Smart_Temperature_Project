#include <Arduino.h>
#include "globals.h"
#include "mqtt.h"
#include "wifi_manager.h"
#include "sensor.h"
#include "ota.h"
#include "eeprom_config.h"

void setup() {
    Serial.begin(115200);
    setupEEPROM();
    pinConfig();
    setupWiFi();
    topicPath();
    MQTT_Connection();
    setupOTA();
    macAddress = String(WiFi.macAddress());
    ip = IpAddressToString(WiFi.localIP());
    publishedData = buildingValue + "," + floorValue + "," + room + "," + deviceType + "," + macAddress + "," + ip + "," + parentTopicNew + "," + clientName + "," + serialNumber;
    sensorSetup();
}

void loop() {
    if (!client.connected()) {
        MQTT_reconnect();
    } else {
        webServer.begin();
        readSensor();
        publishMessage(assetTopic.c_str(), publishedData, true);
        publishMessage(connectionTopic.c_str(), String(true), true);
        publishMessage(tempTopic.c_str(), String(fireTemp), true);
        publishMessage(humdTopic.c_str(), String(fireHumid), true);
        publishMessage(lightTopic.c_str(), String(lightReading), true);
        client.loop();
    }
}
