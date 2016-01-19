#include "DHT.h"

#define DHTPIN 8

//DHT dht(DHTPIN, DHT22);
DHT dht(DHTPIN, DHT11);
int val = '0';

void setup() {

Serial.begin(9600);

dht.begin();

}

void loop() {
  if (Serial.available() > 0){
    val = Serial.read();
    displaySensorsData(val);
  }
} 

void displaySensorsData(int x){
  switch(x){
    case 49: {
     float t = dht.readTemperature();
     if (isnan(t)) {
        Serial.println("I can`t read data from adruino!");
        return;
      } else {
        Serial.println(t);
      }
      break;
   }
    
    case 50: {
      float h = dht.readHumidity();
      if (isnan(h)) {
        Serial.println("I can`t read data from adruino!");
        return;
      } else {
        Serial.println(h);
      }
      break;
    }
    
    case 51: { 
      float t = dht.readTemperature();
      float h = dht.readHumidity();
      if (isnan(t) || isnan(h)) {
        Serial.println("I can`t read data from adruino!");
        return;
      } else {
        Serial.print(t);
        Serial.print(",");
        Serial.println(h);
      }
      break;
    }
  }
}

