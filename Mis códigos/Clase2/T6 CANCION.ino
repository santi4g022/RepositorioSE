//DEFINICIÓN DE MACROS
#define BTNPLAY 2
#define BTNSTOP 3
#define BAUDRATE 9600
#define TIME 1000
//DEFINICIÓN DE VARIABLES
unsigned minutos = 0;
unsigned segundos = 0;
volatile bool bandera = true;
volatile unsigned long lasttime1 = 0;
volatile unsigned long lasttime2 = 0;
volatile unsigned long debounceDelay = 60;
//DEFINICION DE PINES E INTERRUPCIONES
void setup() {
  pinMode(BTNPLAY, INPUT_PULLUP);
  pinMode(BTNSTOP, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BTNPLAY), playPause, FALLING);
  attachInterrupt(digitalPinToInterrupt(BTNSTOP), stop, FALLING);
  Serial.begin(BAUDRATE);
}

void loop() {
  //BANDERA NOS PERMITE PAUSAR, REPRODUCIR O FINALIZAR ENTRE CADA SEGUNDO
  if (bandera == true) {
    //INTRODUCE UN 0 DELANTE DE NUMEROS DE 1 DIGITO EN APARTADO MINUTOS
    if (minutos < 10) {
      Serial.print(0);
    }
    Serial.print(minutos);
    Serial.print(":");
    //INTRODUCE UN 0 DELANTE DE NUMEROS DE 1 DIGITO EN APARTADO SEGUNDOS
    if (segundos < 10) {
      Serial.print(0);
    }
    Serial.println(segundos);
    //AUMENTA 1 SEGUNDO
    segundos++;
    //SI SE COMPLETAN 60 SEG. SE REINICIAN LOS SEGUNDOS Y SE AUMENTA 1 MIN
    if (segundos == 60) {
      minutos++;
      segundos = 0;
    }
    delay(TIME);
  }
}
//FUNCION PARA CAMBIAR EL ESTADO DE LA BANDERA
void playPause() {
  if (millis() - lasttime1 > debounceDelay) {
    if (bandera == true) {
      bandera = false;
    } else {
      bandera = true;
    }
    lasttime1 = millis();
  }
}
//FUNCION PARA CAMBIAR ESTADO DE BANDERA, REINICIAR EL RELOJ E IMPRIMIRLO
void stop() {
  if (millis() - lasttime2 > debounceDelay) {
    if (bandera == true) {
      bandera = false;
    }
    minutos = 0;
    segundos = 0;
    Serial.print(0);
    Serial.print(minutos);
    Serial.print(":");
    Serial.print(0);
    Serial.println(segundos);
    lasttime2 = millis();
  }
}