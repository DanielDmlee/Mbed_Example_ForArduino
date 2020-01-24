unsigned long timech, timech_s, timech_e;

void setup()
{
  Serial.begin(9600);

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.print("Time: ");
  timech_s = millis();
  wait_ms(320);
  timech_e = millis();
  timech = timech_e - timech_s;
  Serial.println(timech); //prints time since program started
  
  digitalWrite(LED_BUILTIN, LOW);
  Serial.print("Time: ");
  timech_s = millis();
  wait_ms(570);
  timech_e = millis();
  timech = timech_e - timech_s;
  Serial.println(timech); //prints time since program started
}
