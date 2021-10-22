#include <DHT.h>
#include <DHT_U.h>
#include <SoftwareSerial.h>

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
          
    BTSerial.print("h: ");
    BTSerial.println(h);

    BTSerial.print("t: ");
    BTSerial.println(t);
    delay(1000);
  }
  
}
