#include <EEPROM.h>
#define BAUDRATE 9600
#define BTN1 2
#define BTN2 3
#define LED1 8
#define LED2 9
#define LED3 10
#define CELDA 0
#define TMAX 10
#define TMIN 1

uint8_t tiempoSet = 5;//EEPROM.read(CELDA);
short tiempoTrans = 0;
volatile unsigned long lasttime1 = 0;
volatile unsigned long lasttime2 = 0;
volatile unsigned long debounceDelay = 120;
volatile bool pin1 = false;
volatile bool pin2 = false;
volatile bool ejecucion = false;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(BTN1, INPUT_PULLUP);
  pinMode(BTN2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BTN1),mas,RISING);
  attachInterrupt(digitalPinToInterrupt(BTN2),menos,RISING);
  Serial.begin(BAUDRATE);
}

void loop() {
  if(ejecucion==false){
    digitalWrite(LED1,1);
  }
  if(pin1==true && pin2==true){
    digitalWrite(LED1,0);
    digitalWrite(LED2,1);
    ejecucion = true;
    tiempoTrans = tiempoSet;
  }
  if(ejecucion==true){
    Serial.print("Tiempo restante: ");
    Serial.print(tiempoTrans);
    Serial.println(".");
    delay(1000);
    tiempoTrans--;
    if(tiempoTrans==0){
      Serial.println("CURADO COMPLETADO");
      digitalWrite(LED2,0);
      ejecucion = false;
    }
  }
  delay(100);
  pin1 = false;
  pin2 = false;
}

void mas(){
  if (millis() - lasttime1 > debounceDelay) {
    if(ejecucion==false){
      pin1 = true;
      if(tiempoSet<TMAX){
        tiempoSet++;
        //EEPROM.write(CELDA, tiempoSet);
        Serial.print("Tiempo de curado: ");
        Serial.print(tiempoSet);
        Serial.println(".");
      }
    }
    lasttime1 = millis();
  }
}

void menos(){
  if (millis() - lasttime2 > debounceDelay) {
    if(ejecucion==false){
      pin2 = true;
      if(tiempoSet>TMIN){
        tiempoSet--;
        //EEPROM.write(CELDA, tiempoSet);
        Serial.print("Tiempo de curado: ");
        Serial.print(tiempoSet);
        Serial.println(".");
      }
    }
    lasttime2 = millis();
  }
}