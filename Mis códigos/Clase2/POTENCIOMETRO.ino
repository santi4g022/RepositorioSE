#define POT A5
#define DELAYTIME 50
#define BAUTRATE 9600
float lectura;
float conv;

void setup()
{
  /*Se inicia el monitor serial con el siguiente comando, 9600 es la 
  resolución ideal de comunicación entre el arduino y el monitor serial*/
  Serial.begin(BAUTRATE);
}

void loop()
{
  /*La variable float "lectura" nos va a proporcionar la información
  obtenida en el pin A5, que va de 0 a 1023 por su resolución*/
  lectura = analogRead(POT);
  /*Con la siguiente linea se hace una conversión de la lectura a V,
  para saber el voltaje de salida del potenciometro*/
  conv = (lectura*5)/1023;
  /*Se realiza la impresión de la lectura convertida en el mon. serial*/
  Serial.print("Voltaje: ");
  Serial.print(conv);
  Serial.println(" V.");
  /*Se introduce un delay para desacelerar las lecturas por segundo*/
  delay(DELAYTIME);
}