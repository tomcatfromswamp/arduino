#include "DHT.h"

#define DHTPIN2 2
#define DHTPIN3 3
#define DHTPIN4 4
#define DHTPIN5 5
#define DHTPIN6 6
#define DHTPIN7 7

//DHT dht(DHTPIN, DHT11);

DHT dht2(DHTPIN2, DHT22);
DHT dht3(DHTPIN3, DHT22);
DHT dht4(DHTPIN4, DHT22);
DHT dht5(DHTPIN5, DHT22);
DHT dht6(DHTPIN6, DHT22);
DHT dht7(DHTPIN7, DHT22);

int val = '0';

void setup() {

Serial.begin(9600);

dht2.begin();
dht3.begin();
dht4.begin();
dht5.begin();
dht6.begin();
dht7.begin();

}

void loop() {
  if (Serial.available() > 0){
    val = Serial.read();
    displaySensorsData(val);
  }
} 

void displaySensorsData(int x){
  float t = 0.0;
  float h = 0.0;
  int id = 0;
  switch(x){
    case 50: { 
      t = dht2.readTemperature();
      h = dht2.readHumidity();
      id = 2;
      break;
    }
    case 51: { 
      t = dht3.readTemperature();
      h = dht3.readHumidity();
      id = 3;
      break;
    }
    case 52: { 
      t = dht4.readTemperature();
      h = dht4.readHumidity();
      id = 4;
      break;
    }
    case 53: { 
      t = dht5.readTemperature();
      h = dht5.readHumidity();
      id = 5;
      break;
    }
    case 54: { 
      t = dht6.readTemperature();
      h = dht6.readHumidity();
      id = 6;
      break;
    }
    case 55: { 
      t = dht7.readTemperature();
      h = dht7.readHumidity();
      id = 7;
      break;
    }
  }
      if (isnan(t) || isnan(h)) {
        Serial.print(id);
        Serial.println(",0.0,0.0");
        return;
      } else {
        Serial.print(id);
        Serial.print(",");
        Serial.print(t);
        Serial.print(",");
        Serial.println(h);
    }
}

