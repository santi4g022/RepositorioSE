#define BTNPLAY 2
#define BTNSTOP 3
#define BAUDRATE 9600
#define TIME 1000

unsigned minutos = 0;
unsigned segundos = 0;
volatile bool bandera1 = true;

void setup(){
    pinMode(BTNPLAY, INPUT_PULLUP);
    pinMode(BTNSTOP, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(BTNPLAY),playPause,FALLING);
    attachInterrupt(digitalPinToInterrupt(BTNSTOP),stop,FALLING);
    Serial.begin(BAUDRATE);
}

void loop(){
  if(bandera1==true){  
    if(minutos<10){
      Serial.print(0);
    }
    Serial.print(minutos);
    Serial.print(":");
    if(segundos<10){
      Serial.print(0);
    }
    Serial.println(segundos);

    segundos++;
    if(segundos==60){
        minutos++;
        segundos = 0;
    }
    delay(TIME);
  }
}

void playPause(){
  if(bandera1 == true){
    bandera1 = false;
  }else{
    bandera1 = true;
  }
}

void stop(){
  if(bandera1==true){
    bandera1 = false;
  }
  minutos = 0;
  segundos = 0;
  Serial.print(0);
  Serial.print(minutos);
  Serial.print(":");
  Serial.print(0);
  Serial.println(segundos);
}