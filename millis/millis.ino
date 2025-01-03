unsigned long T1 = 0, T2 = 0;
unsigned int TimeInterval = 1000;
 
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}
 
void loop()
{
  T2 = millis();
  if( (T2-T1) >= TimeInterval )
  {
    Serial.print("T2 : ");
    Serial.println(T2);
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    T1 = millis();
    Serial.print("T1 : ");
    Serial.println(T1);
  }
}