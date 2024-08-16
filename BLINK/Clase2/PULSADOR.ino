void setup() {
  pinMode(13, OUTPUT);
  pinMode(2, INPUT);
}

void loop() {
  
  byte dato = digitalRead(2);
  if (dato==1){
    digitalWrite(13,1);
  }else{
    digitalWrite(13,0);
  }
}