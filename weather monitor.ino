#include <SoftwareSerial.h>
SoftwareSerial bt(8, 9); // TX, RX

#include "dht.h"
#define dataPin A0
dht DHT;

int temp;
int hum;

void setup() {
 
 Serial.begin(9600); 
 bt.begin(9600); 
 Serial.println("Ready");
 pinMode(5,OUTPUT); 
}

void loop(){
  int readData = DHT.read11(dataPin);

  hum = DHT.humidity;
  temp = DHT.temperature;
 
if (temp > 25 || hum >= 95){
  digitalWrite(5,HIGH);
}
else{
  digitalWrite(5,LOW);
}
Serial.println(temp);
Serial.println(hum);
bt.print(temp); //send distance to our App
bt.print(";");
bt.print(hum); //send distance to our App 
bt.println(";");

  delay(1000);
}
