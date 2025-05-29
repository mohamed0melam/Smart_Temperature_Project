#include "globals.h"

// MQTT Data
String tempTopic, humdTopic, rainTopic, connectionTopic, assetTopic;
String tcalTopic, hcalTopic, resetEspTopic, lightTopic;
String resetWifiTopic, resetDHTTopic, fireTemp, fireHumid;

// Static Info
String buildingValue = "Building1";
String floorValue = "2nd Floor";
String room = "Room5";
String deviceType = "TEMPERATURE";
String serialNumber = "ESP32-001";
String clientName = "i4Technology";
String parentTopicNew = "i4/sensors";

// Credentials
String server_ = "192.168.1.100";
String username_ = "user";
String serverpassword = "pass";
String clientId = "ESP32Sensor";

// Runtime
int temperature_ = 0;
int humidity_ = 0;
int lightReading = 0;
int tempCounter = 0;
String tcalibrate = "";
String hcalibrate = "";
String resetEsp = "";
String resetWifi = "";
String resetDHT = "";
String publishedData = "";
String macAddress = "";
String ip = "";

// Hardware
DHT_Unified dht(DHTPIN, DHTTYPE);
AsyncWebServer webServer(80);
DNSServer dnsServer;
WiFiClient espClient;
PubSubClient client(espClient);
