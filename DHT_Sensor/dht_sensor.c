#include "globals.h"
#include "mqtt_client.h"

void setupDHT() {
  dht.begin();
}

void readAndPublishDHT() {
  sensors_event_t event;

  dht.temperature().getEvent(&event);
  if (!isnan(event.temperature)) {
    temperature_ = event.temperature + tcalibrate.toInt();
    fireTemp = String(temperature_) + "°C";
    client.publish(tempTopic.c_str(), fireTemp.c_str(), true);
  }

  dht.humidity().getEvent(&event);
  if (!isnan(event.relative_humidity)) {
    humidity_ = event.relative_humidity + hcalibrate.toInt();
    fireHumid = String(humidity_) + "%";
    client.publish(humdTopic.c_str(), fireHumid.c_str(), true);
  }

  lightReading = analogRead(light);
  client.publish(lightTopic.c_str(), String(lightReading).c_str(), true);
}
