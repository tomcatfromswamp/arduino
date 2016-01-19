#include "DHT.h"

#define DHTPIN 8

//DHT dht(DHTPIN, DHT22);

DHT dht(DHTPIN, DHT11);

void setup() {

Serial.begin(9600);

dht.begin();

}

void loop() {


delay(1000);


float h = dht.readHumidity();


float t = dht.readTemperature();


if (isnan(h) || isnan(t)) {

Serial.println("I can`t read data from adruino!");

return;

}

Serial.print(t);
Serial.print(",");
Serial.println(h);

}

