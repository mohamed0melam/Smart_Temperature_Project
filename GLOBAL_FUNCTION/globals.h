#ifndef GLOBALS_H
#define GLOBALS_H

#include <Arduino.h>
#include <WiFi.h>                    
#include <DHT_U.h>
#include <ESPAsyncWebServer.h>
#include <DNSServer.h>
#include <PubSubClient.h>
#include <WiFiClient.h>

// GPIO
#define DHTPIN 4
#define DHTTYPE DHT11
#define light 34 // Use a valid ADC pin for ESP32

// MQTT Topics
extern String tempTopic, humdTopic, rainTopic, connectionTopic, assetTopic;
extern String tcalTopic, hcalTopic, resetEspTopic, lightTopic;
extern String resetWifiTopic, resetDHTTopic, fireTemp, fireHumid;

// Static Info
extern String buildingValue, floorValue, room, deviceType;
extern String serialNumber, clientName, parentTopicNew;
extern String server_, username_, serverpassword, clientId;

// Runtime Variables
extern int temperature_, humidity_, lightReading, tempCounter;
extern String tcalibrate, hcalibrate, resetEsp, resetWifi, resetDHT;
extern String publishedData;
extern String macAddress, ip;

// Objects
extern DHT_Unified dht;
extern AsyncWebServer webServer;
extern DNSServer dnsServer;
extern WiFiClient espClient;
extern PubSubClient client;

#endif
