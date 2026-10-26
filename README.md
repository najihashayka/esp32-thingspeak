# ESP32 → ThingSpeak: Temperature & Humidity Monitor

## Student Information
- **Name:** Najih Hashayka
- **University ID:** 12324171

## Project Description
This project uses an ESP32 and a DHT22 sensor (simulated on Wokwi) to measure temperature and humidity and send the readings to ThingSpeak over Wi-Fi every 20 seconds. ThingSpeak displays the data as live charts through a public channel view.

The University ID (`12324171`) is included in every HTTP request as the `status` parameter, and it is also printed in the Serial Monitor log.

## Links
- **ThingSpeak Public URL:** https://thingspeak.mathworks.com/channels/3551894
- **Wokwi Simulation:** https://wokwi.com/projects/478976302354909185

## ThingSpeak Channel
- **Channel name:** Najih_Hashayka_12324171
- **Field 1:** Temperature (°C)
- **Field 2:** Humidity (%)
- **Status:** University ID

## Hardware / Wiring
| DHT22 Pin  | ESP32 Pin |
|------------|-----------|
| VCC        | 3V3       |
| SDA (DATA) | GPIO 15   |
| GND        | GND       |

The Wokwi schematic is in `diagram.json` and in the screenshot below.

![Wiring and Serial Monitor](screenshots/wokwi_wiring_and_serial.png)

## How It Works
1. The ESP32 connects to the Wokwi virtual Wi-Fi (`Wokwi-GUEST`).
2. It reads temperature and humidity from the DHT22.
3. It sends an HTTP GET request to ThingSpeak:
   ```
   http://api.thingspeak.com/update?api_key=XXXX&field1=<temp>&field2=<hum>&status=12324171
   ```
4. It repeats every 20 seconds (the ThingSpeak free tier requires at least 15 seconds between updates).

## How to Run
1. Open the Wokwi link above, or create a new ESP32 project and paste `sketch.ino` and `diagram.json`.
2. Install the library **DHT sensor library** (Adafruit).
3. Replace `YOUR_WRITE_API_KEY` in `sketch.ino` with your ThingSpeak Write API Key.
4. Press **Play** and watch the Serial Monitor for `HTTP code: 200`.

## Screenshots
### ThingSpeak Live Charts (Temperature & Humidity)
![ThingSpeak Charts](screenshots/thingspeak_charts.png)

### Channel Status Log (University ID per update)
![Status Log](screenshots/thingspeak_status_log.png)

### Wiring + Serial Monitor
![Serial Monitor](screenshots/wokwi_wiring_and_serial.png)

## Files
- `sketch.ino`: ESP32 source code
- `diagram.json`: Wokwi circuit schematic
- `screenshots/`: Screenshots of the charts, wiring and serial output
