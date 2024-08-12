 #define LED 13
 #define time 1000
void setup() {
pinMode(num, OUTPUT);
}

void loop() {
  //
  digitalWrite(LED, HIGH);
  delay(time);
  digitalWrite(LED, LOW); 
  delay(time);
}
