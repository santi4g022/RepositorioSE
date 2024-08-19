#define LED 13
#define BUTTON 2

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop() {
  /*Se crea la variable "dato" para leer si hay un true o un false en 
  el puerto digital nro 2, esto cambiará con el pulsado del botón*/
  byte dato = digitalRead(BUTTON);
  if (dato==1){
    /*Si es true, el led se encenderá*/
    digitalWrite(LED, HIGH);
  }else{
    /*Si es false, el led se apagará, respondiendo de esta manera
    al pulso del botón.*/
    digitalWrite(LED, LOW);
  }
}