// Intended to make NodeMCU ESP8266 to send data values of temperature retrieved from                   //
// Arduino (Connected with DHT-11) to a HTML file stored online over GitHub Pages                       //
// In the code, all the lines with comments must be changed accordingly with the Wi-Fi and Webpage used //

#include <ESP8266WiFi.h>

const char* ssid = "Your_SSID"; //SSID must be on 2.4 Ghz
const char* password = "Your_PASSWORD"; //PASSWORD
const char* host = "g33tansh.github.io/arduinology/"; 

void setup() {
  Serial.begin(9600);
  delay(10);
  Serial.println('\n');

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");
}

void loop() {
  
}

void handleRoot() {
  WiFiClient client;

  if (!client.connect(host, 443)) { 
    Serial.println("Connection failed!");
    return;
  }

  String url = "/arduinology/temperature.html"; 
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Connection: close\r\n\r\n");

  Serial.println("Request sent to GitHub Pages");
  delay(1000);
}

