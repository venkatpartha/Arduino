#define LED_PIN 13
#define BTN_PIN 2

volatile bool flag=0;

void INT0_ISR(void){
  flag=digitalRead(LED_PIN);
  //digitalWrite(LED_PIN, !);
}
 
void setup()
{
  pinMode(LED_PIN, OUTPUT);
  pinMode(BTN_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(BTN_PIN), INT0_ISR, RISING);
}
void loop()
{
  if(!flag){  
    digitalWrite(LED_PIN, HIGH);
  }
  else{
    digitalWrite(LED_PIN, LOW);
  }
  //flag=0;
  // Do Nothing
}