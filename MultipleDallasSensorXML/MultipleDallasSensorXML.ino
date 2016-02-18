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
DeviceAddress sensor;

int val = 0;
int id = 0;
int count = 0;
String buf;

void setup(void)
{
  // start serial port
  Serial.begin(9600);

  // Start up the library
  sensors.begin();
}

void loop(void)
{ 
  if (Serial.available() > 0){
      val = Serial.read();
      switch(val){
        case 48: {
          displaySensorsData();
          break;
        }
      }
    }
}

void displaySensorsData(){
      count = sensors.getDeviceCount();
      sensors.requestTemperatures();
      buf="<?xml version=\"1.0\" encoding=\"utf-8\"?><data>";
      for(int i=0;i<count;i++){
        printTemperature(i);
      }
      buf = buf + "</data>";
      Serial.println(buf);
}

void printTemperature(int id){
  sensors.getAddress(sensor,id);
  String sensorAddr="";
  for (uint8_t i = 0; i < 8; i++)
  {
    // zero pad the address if necessary
    if (sensor[i] < 16) sensorAddr=sensorAddr+"0";
    sensorAddr = sensorAddr + String(sensor[i],HEX);
  }
  buf = buf + "<sensor id='";
  buf = buf + id;
  buf = buf + "' adr='";
  buf = buf + sensorAddr;
  buf = buf + "' temp='";
  buf = buf + sensors.getTempCByIndex(id);
  buf = buf + "' />";
}

