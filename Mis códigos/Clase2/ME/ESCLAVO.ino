#include <Wire.h>
#define LED 7
bool bandera = false;
String comparador = "";
String mensaje;

void setup() {
  pinMode(LED,OUTPUT);
  Wire.begin(8);
  Wire.onReceive(recibirDatos);
  Serial.begin(9600);
}

void loop() {
  mensaje.remove(0,0);
  if(mensaje != comparador && mensaje != ""){
    mensaje.remove(0,1);
    Serial.println(mensaje);
    if(mensaje == "ENCENDER"){
      digitalWrite(LED, 1);
      Serial.println("LED ENCENDIDO");
    }else if(mensaje == "APAGAR"){
      digitalWrite(LED, 0);
      Serial.println("LED APAGADO");
    }
    comparador = mensaje;
  }
  mensaje = '\0';
  delay(900);
}

void recibirDatos(int bytes){
  while(Wire.available()){
    char c = Wire.read(); 
    mensaje = mensaje + c;
    Serial.println(mensaje);
  }
  Serial.println("hola");
}