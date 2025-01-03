#define BTN_PIN 4

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(BTN_PIN, INPUT_PULLUP);
  Serial.begin(9600);
}
 
void loop()
{
  Serial.println(digitalRead(BTN_PIN));
  while(digitalRead(BTN_PIN))
  {
    digitalWrite(LED_BUILTIN, LOW);
  }
  digitalWrite(LED_BUILTIN, HIGH);
}
