#include <DHT.h>
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <ESP8266HTTPClient.h>

void sendData(float temperature, float humidity);

#define DHTPIN 4        // DHT11 data pin
#define DHTTYPE DHT11   // DHT 11

const char* ssid = "*-*.";
const char* password = "cloudy777";
const char* serverUrl = "http://192.168.43.181:8080/weather";

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  delay(1000);

  WiFi.begin(ssid, password);
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());
  dht.begin();
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    // Read temperature and humidity from the DHT11
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" Humidity: ");
    Serial.println(humidity);

    // Send data to the Node.js server
    sendData(temperature, humidity);

    delay(10000); // Wait for 5 seconds before sending the next request
  }
}

void sendData(float temperature, float humidity) {
  String payload = "{\"temperature\":" + String(temperature) + ",\"humidity\":" + String(humidity) + "}";

  // Send payload to the Node.js server
  WiFiClient client;
  HTTPClient http;
  http.begin(client, serverUrl);
  http.addHeader("Content-Type", "application/json");

  int httpCode = http.POST(payload);
  String response = http.getString();

  Serial.print("HTTP response code: ");
  Serial.println(httpCode);
  Serial.print("Response: ");
  Serial.println(response);

  http.end();
}
