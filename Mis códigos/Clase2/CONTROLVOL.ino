#include <EEPROM.h>
#define BOTONMAS 3
#define BOTONMENOS 2
#define BAUDRATE 9600
#define VOLMAX 20
#define VOLMIN 0
#define CELDA 0
unsigned short volumen;
volatile unsigned long lasttime = 0;
volatile unsigned long debounceDelay = 50;

void setup(){
    pinMode(BOTONMAS,INPUT_PULLUP);
    pinMode(BOTONMENOS,INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(BOTONMAS,aumentar,RISING));
    attachInterrupt(digitalPinToInterrupt(BOTONMENOS,disminuir,RISING));
    EEPROM.read(CELDA);
    Serial.begin(BAUDRATE);
}

void loop(){
    Serial.print("Volumen: ");
    Serial.print(volumen);
    Serial.println(".");
}

void aumentar(){
    if(millis() - lasttime > debounceDelay){
        if(volumen<VOLMAX){
            volumen++;
            EEPROM.write(CELDA,volumen);
        }
    lasttime = millis();
    }
}

void disminuir(){
    if(millis() - lasttime > debounceDelay){
        if(volumen>VOLMIN){
            volumen=volumen-1;
            EEPROM.write(CELDA,volumen);
        }
    lasttime = millis();
    }
}