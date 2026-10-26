/*
  ESP32 + DHT22 -> ThingSpeak
  Student: Najih Hashayka
  University ID: 12324171
  DHT22 DATA pin: GPIO 15
*/
#include <WiFi.h>
#include <HTTPClient.h>
#include "DHT.h"

#define DHTPIN 15          // DATA pin -> GPIO 15
#define DHTTYPE DHT22

const char* ssid     = "Wokwi-GUEST";   // Wokwi virtual WiFi
const char* password = "";

String apiKey = "YOUR_WRITE_API_KEY";   // Replace with your ThingSpeak Write API Key
String universityID = "12324171";
String studentName  = "Najih Hashayka";

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();

  Serial.print("Connecting to WiFi");
  WiFi.begin(ssid, password, 6);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected!");
}

void loop() {
  float temp = dht.readTemperature();
  float hum  = dht.readHumidity();

  if (isnan(temp) || isnan(hum)) {
    Serial.println("Failed to read from DHT sensor!");
    delay(2000);
    return;
  }

  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String url = "http://api.thingspeak.com/update?api_key=" + apiKey +
                 "&field1=" + String(temp) +
                 "&field2=" + String(hum) +
                 "&status=" + universityID;

    http.begin(url);
    int code = http.GET();

    Serial.println("-----------------------------");
    Serial.println("Student: " + studentName);
    Serial.println("University ID: " + universityID);
    Serial.println("Temp: " + String(temp) + " C");
    Serial.println("Humidity: " + String(hum) + " %");
    Serial.println("HTTP code: " + String(code));
    http.end();
  }

  delay(20000);   // every 20 seconds
}
