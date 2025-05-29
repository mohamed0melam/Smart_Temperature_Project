#ifndef MQTT_CLIENT_H
#define MQTT_CLIENT_H

void setupMQTT();
void mqttLoop();
void mqttCallback(char* topic, byte* payload, unsigned int length);

#endif
