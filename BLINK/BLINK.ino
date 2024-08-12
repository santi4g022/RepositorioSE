 #define num 1
void setup() {
  // put your setup code here, to run once:
pinMode(num, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(num,HIGH)
  delay(1000)
  digitalWrite(num,LOW)
  delay(1000)
}
