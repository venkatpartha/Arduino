#define LED_PIN 3
void setup() {
  pinMode(LED_PIN, OUTPUT);
  for(int i=0;i<256;i++){
    analogWrite(LED_PIN, i);
    delay(10);
  }
  delay(2000);
  for(int i=255;i>=0;i--){
    analogWrite(LED_PIN, i);
    delay(10);
  }

}

void loop() {
  // put your main code here, to run repeatedly:

}
