#include "funciones.h"
#include <Arduino.h>

void pines(){
  pinMode(LED1, OUTPUT);
}

void serialInit(){
    Serial.begin(UART0);
    Serial.print(" ");
} 

void leer(){
    if(Serial.available()>0){
    char entrada = Serial.read();
    if(entrada == '1'){
      digitalWrite(LED1, 1);
  	}else if(entrada == '0'){
      digitalWrite(LED1, 0);
    }
  }
  delay(TIMEDELAY);
}