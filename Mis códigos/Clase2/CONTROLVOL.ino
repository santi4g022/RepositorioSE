#include <EEPROM.h>
#define BOTONMAS 3
#define BOTONMENOS 2
#define BAUDRATE 9600
#define VOLMAX 20
#define VOLMIN 0
#define CELDA 0
#define TIME 5000
uint8_t volumen = EEPROM.read(CELDA);
volatile unsigned long lasttime = 0;
volatile unsigned long debounceDelay = 60;

void setup(){
    pinMode(BOTONMAS,INPUT_PULLUP);
    pinMode(BOTONMENOS,INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(BOTONMAS),aumentar,FALLING);
    attachInterrupt(digitalPinToInterrupt(BOTONMENOS),disminuir,FALLING);
    Serial.begin(BAUDRATE);
}

void loop(){
    delay(TIME);
}

void aumentar(){
    if(millis() - lasttime > debounceDelay){
        if(volumen<VOLMAX){
            volumen++;
            Serial.print("Volumen: ");
            Serial.print(volumen);
            Serial.println(".");
            EEPROM.write(CELDA,volumen);
        }
        lasttime = millis();
    }
}

void disminuir(){
    if(millis() - lasttime > debounceDelay){
        if(volumen>VOLMIN){
            volumen--;
            Serial.print("Volumen: ");
            Serial.print(volumen);
            Serial.println(".");
            EEPROM.write(CELDA,volumen);
        }
        lasttime = millis();
    }
}