#include "DHT.h"

#define DHTPIN6 6
#define DHTPIN7 7

DHT dht6(DHTPIN6, DHT22);
DHT dht7(DHTPIN7, DHT22);

//DHT dht(DHTPIN, DHT11);

void setup() {

Serial.begin(9600);

//dht6.begin();
dht7.begin();

}

void loop() {


delay(1000);


//float h6 = dht6.readHumidity();
//float t6 = dht6.readTemperature();
float h7 = dht7.readHumidity();
float t7 = dht7.readTemperature();

if (isnan(h7) || isnan(t7)) {

Serial.println("I can`t read data from adruino!");

return;

}

//Serial.print(t6);
//Serial.print(",");
//Serial.print(h6);
//Serial.print("#");
Serial.print(t7);
Serial.print(",");
Serial.println(h7);

}

