// Include the libraries we need
#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 2
#define TEMPERATURE_PRECISION 9

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

// arrays to hold device addresses
DeviceAddress sensor0, sensor1, sensor2, sensor3, sensor4;

int val = 0;
int id = 0;

void setup(void)
{
  // start serial port
  Serial.begin(9600);

  // Start up the library
  sensors.begin();

  sensors.getAddress(sensor0, 0);
  sensors.getAddress(sensor1, 1);
  sensors.getAddress(sensor2, 2);
  sensors.getAddress(sensor3, 3);
  sensors.getAddress(sensor4, 4);

/*
  if (!sensors.getAddress(sensor0, 0)) Serial.println("Unable to find address for Device 0"); 
  if (!sensors.getAddress(sensor1, 1)) Serial.println("Unable to find address for Device 1"); 
  if (!sensors.getAddress(sensor2, 2)) Serial.println("Unable to find address for Device 2"); 
  if (!sensors.getAddress(sensor3, 3)) Serial.println("Unable to find address for Device 3"); 
  if (!sensors.getAddress(sensor4, 4)) Serial.println("Unable to find address for Device 4"); 
*/

  // set the resolution to 9 bit per device
  sensors.setResolution(sensor0, TEMPERATURE_PRECISION);
  sensors.setResolution(sensor1, TEMPERATURE_PRECISION);
  sensors.setResolution(sensor2, TEMPERATURE_PRECISION);
  sensors.setResolution(sensor3, TEMPERATURE_PRECISION);
  sensors.setResolution(sensor4, TEMPERATURE_PRECISION);
 
}

void loop(void)
{ 
  if (Serial.available() > 0){
      val = Serial.read();
      displaySensorsData(val);
  }
}

void displaySensorsData(int x){
  sensors.requestTemperatures();
  switch(x){
    case 48: { 
      printTemperature(sensor0,0);
      break;
    }
    case 49: { 
      printTemperature(sensor1,1);
      break;
    }
    case 50: { 
      printTemperature(sensor2,2);
      break;
    }
    case 51: { 
      printTemperature(sensor3,3);
      break;
    }
    case 52: { 
      printTemperature(sensor4,4);
      break;
    }
  }
}

void printTemperature(DeviceAddress deviceAddress, int id){
  float tempC = sensors.getTempC(deviceAddress);
  Serial.print(id);
  Serial.print(",");
  Serial.println(tempC);
}

