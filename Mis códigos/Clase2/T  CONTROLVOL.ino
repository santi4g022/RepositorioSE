//DEFINICIÓN DE MACROS
#include <EEPROM.h>
#define BOTONMAS 3
#define BOTONMENOS 2
#define BAUDRATE 9600
#define VOLMAX 20
#define VOLMIN 0
#define CELDA 0
#define TIME 5000
#define TIMESEP 50
//DEFINICIÓN DE VARIABLES
uint8_t volumen = EEPROM.read(CELDA);
volatile unsigned long lasttime = 0;
volatile unsigned long debounceDelay = 80;
volatile bool pinMenos = false;
volatile bool pinMas = false;
//DEFINICIÓN DE PINES E INTERRUPCIONES
void setup() {
  pinMode(BOTONMAS, INPUT_PULLUP);
  pinMode(BOTONMENOS, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BOTONMAS), aumentar, RISING);
  attachInterrupt(digitalPinToInterrupt(BOTONMENOS), disminuir, RISING);
  Serial.begin(BAUDRATE);
}
void loop() {
  //LÓGICA PARA AUMENTO DE VOLUMEN
  if (pinMas == true && pinMenos == false) {
    if (volumen < VOLMAX) {
      volumen++;
      Serial.print("Volumen: ");
      Serial.print(volumen);
      Serial.println(".");
      EEPROM.write(CELDA, volumen);
    }
    pinMas = false;
  }
  delay(TIMESEP);
  //LÓGICA PARA DISMINUCIÓN DE VOLUMEN 
  if (pinMenos == true && pinMas == false) {
    if (volumen > VOLMIN) {
      volumen--;
      Serial.print("Volumen: ");
      Serial.print(volumen);
      Serial.println(".");
      EEPROM.write(CELDA, volumen);
    }
    pinMenos = false;
  }
  delay(TIMESEP);
  //LÓGICA PARA REINICIAR VOLUMEN 
  if(pinMas == true && pinMenos == true){
    volumen = 0;
    Serial.print("Volumen: ");
      Serial.print(volumen);
      Serial.println(".");
      EEPROM.write(CELDA, volumen);
    pinMas = false;
    pinMenos = false;
  }
  delay(TIMESEP);
}
//INTERRUPCIONES PARA ACTIVAR BANDERAS
void aumentar() {
  if (millis() - lasttime > debounceDelay) {
    pinMas = true;
    lasttime = millis();
  }
}
void disminuir() {
  if (millis() - lasttime > debounceDelay) {
    pinMenos = true;
    lasttime = millis();
  }
}
