#include <DHT.h>

#define DHTPIN 2 
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(2000); 
  float temperature = dht.readTemperature();
  Serial.println(temperature); //Supposed to send the Temperature Value over Serial Communication (ESP8266 in this case) 
}

