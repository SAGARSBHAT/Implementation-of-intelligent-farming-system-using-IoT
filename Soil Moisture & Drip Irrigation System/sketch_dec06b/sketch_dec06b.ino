#include <SoftwareSerial.h>
SoftwareSerial espSerial(5, 6);
int Relay=13;
int sensor=8;
int vol;
String str;
void setup() {
  pinMode(13,OUTPUT);
  pinMode(8,INPUT);
 pinMode(A0,INPUT);
 Serial.begin(115200);
espSerial.begin(115200);
delay(1000);
}

void loop() {
  int soil=analogRead(A0);
  Serial.println(soil);
  Serial.print("Moisture Content: ");
  Serial.print(soil);
  vol=digitalRead(8);
   if(vol==LOW){
    digitalWrite(13,HIGH);
  }
  else{
    digitalWrite(13,LOW);
  }
str =String("value is: ")+String(soil);
espSerial.println(str);
delay(1000);
  }
