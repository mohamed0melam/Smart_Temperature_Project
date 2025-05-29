#include <WiFi.h>
#include "globals.h"

void setupWiFi() {
  WiFi.begin("I4TECH", "I4TECH@2023");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected");
}
