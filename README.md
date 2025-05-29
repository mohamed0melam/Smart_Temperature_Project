# Smart Temperature & Humidity Monitor (ESP8266 + MQTT + OTA)

A modular project for ESP8266 that reads temperature and humidity from a DHT11 sensor, connects to Wi-Fi via WiFiManager, and publishes the readings to an MQTT broker. It also supports OTA updates and stores configuration (MQTT credentials, calibration values) in EEPROM.

## 📦 Features

- ✅ WiFiManager portal for dynamic configuration
- ✅ MQTT publish/subscribe
- ✅ OTA (Over-The-Air) firmware updates
- ✅ EEPROM storage for persistent config
- ✅ Modular C driver structure
- ✅ Status LED indicator
- ✅ Calibration support for temperature

## 🛠️ Hardware

- ESP8266 (e.g., NodeMCU or Wemos D1 mini)
- DHT11 Temperature and Humidity Sensor
- Optional: Status LED

## 🔧 Configuration

1. On first boot, ESP8266 will create a WiFi hotspot.
2. Connect to it and open the captive portal.
3. Enter WiFi credentials and MQTT server info.
4. Device reboots and stores the config in EEPROM.

## 🧪 MQTT Topics

Assuming:
- `serialNumber = "DHT001"`
- `deviceType = "ESP8266"`

| Action         | Topic                                  |
|----------------|----------------------------------------|
| Publish Temp   | `ESP8266/DHT001/temp`                  |
| Publish Humid  | `ESP8266/DHT001/humid`                 |
| Subscribe Cal  | `ESP8266/DHT001/calibration/temp`      |

## 🧰 Libraries Used

```ini
- DHT sensor library
- PubSubClient
- EEPROM
- WiFiManager
- AsyncElegantOTA
- ESP8266WiFi
```

## ▶️ How to Run

1. Open with [PlatformIO](https://platformio.org/)
2. Connect your ESP8266 to USB
3. Upload code with the `Upload` button
4. Monitor output with `Monitor` button

## 📂 Project Structure

```
Smart_Temperature_Project/
├── include/         # Header files
├── src/             # Source C files
├── .vscode/         # VS Code settings
├── platformio.ini   # PlatformIO configuration
└── README.md
```

---

## 🙌 Author

Developed by [Your Name]  
Based on ESP8266 + MQTT + OTA architecture with modular C design.
