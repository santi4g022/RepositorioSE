#define DELAYTIME 50
float lectura;
float conv;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  lectura = analogRead(A5);
  conv = (lectura*5)/1023;
  Serial.print("Voltaje: ");
  Serial.print(conv);
  Serial.println(" V.");
  delay(DELAYTIME);
}