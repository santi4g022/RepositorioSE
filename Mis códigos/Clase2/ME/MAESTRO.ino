#include <Wire.h>
void setup(){
  Wire.begin(); 
  Serial.begin(9600);
}
void loop() {
  Wire.beginTransmission(8);
  if(Serial.available()>1){
    Wire.write(Serial.read());
    Serial.println("Mensaje enviado al Esclavo");
  }
  Wire.endTransmission();
}