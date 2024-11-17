#include <Wire.h>

void setup() {
  Wire.begin(8);
  Wire.onReceive(recibirDatos);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void recibirDatos(int bytes){
  while(Wire.available()>0){
    char c = Wire.read(); 
    Serial.print(c);
  }
  //Serial.println();
}