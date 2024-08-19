 #define LED 13
 #define TIMELED 1000
void setup() {
  //pinMode(argument1, argument2);
  pinMode(LED, OUTPUT);
}

void loop() {
  //digitalWrite(argument1, argument2(HIGH, true, 1))
  digitalWrite(LED, HIGH);
  delay(TIMELED);
  //digitalWrite(argument1, argument2(LOW, false, 0))
  digitalWrite(LED, LOW); 
  delay(TIMELED);
}
