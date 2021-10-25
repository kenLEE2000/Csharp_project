#include <DHT.h>
#include <DHT_U.h>
#include <SoftwareSerial.h>

//var name can change
#define DHTPIN 7
#define DHTTYPE DHT11

SoftwareSerial BTSerial(10, 11);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  BTSerial.begin(9600);
  dht.begin();
}

void loop() {
  if (!Serial.available())   {
    float h = dht.readHumidity(),
          t = dht.readTemperature();
    
    
    //function A's String type can change
          
    BTSerial.print("h: ");
    BTSerial.println(h);

    BTSerial.print("t: ");
    BTSerial.println(t);
    
    //delay's time value can change
    delay(1000);
  }
  
}
