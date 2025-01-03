#define SET_PIN_MODE_OUTPUT(port, pin) DDR ## port |= (1 << pin)
#define SET_PIN_HIGH(port, pin) (PORT ## port |= (1 << pin))
#define SET_PIN_LOW(port, pin) ((PORT ## port) &= ~(1 << (pin)))
 
#define INT0_PIN  2
 
void INT0_ISR(void)
{
  SET_PIN_HIGH(B, 0);
  delay(1);
}
 
void setup()
{
  SET_PIN_MODE_OUTPUT(B, 0);  // Set Pin8 (PB0) As Output
  pinMode(INT0_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(INT0_PIN), INT0_ISR, RISING);
}
void loop()
{
  SET_PIN_LOW(B, 0);
  delay(10);
}