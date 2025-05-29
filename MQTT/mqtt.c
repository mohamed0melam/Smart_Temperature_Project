#include <Arduino.h>
#include "globals.h"
#include "mqtt_client.h"

void setupMQTT() {
  client.setServer(server_.c_str(), 1883);
  client.setCallback(mqttCallback);
}

void mqttLoop() {
  if (!client.connected()) {
    while (!client.connect(clientId.c_str(), username_.c_str(), serverpassword.c_str())) {
      delay(1000);
      Serial.println("Connecting to MQTT...");
    }

    client.subscribe(tcalTopic.c_str());
    client.subscribe(hcalTopic.c_str());
    client.subscribe(resetEspTopic.c_str());
    client.subscribe(resetWifiTopic.c_str());
    client.subscribe(resetDHTTopic.c_str());
  }

  client.loop();
}

void mqttCallback(char* topic, byte* payload, unsigned int length) {
  String topicStr = String(topic);
  String value = "";
  for (int i = 0; i < length; i++) {
    value += (char)payload[i];
  }

  if (topicStr == tcalTopic) tcalibrate = value;
  else if (topicStr == hcalTopic) hcalibrate = value;
  else if (topicStr == resetEspTopic) resetEsp = value;
  else if (topicStr == resetWifiTopic) resetWifi = value;
  else if (topicStr == resetDHTTopic) resetDHT = value;
}
