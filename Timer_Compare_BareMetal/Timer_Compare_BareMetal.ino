/*
TICKCOUNT VALUE FOR 100 mS = 25000 (PRESCALER = 64)
AND MAXIMUM TICK VALUE = 65535 (2 POWER 16)
*/
volatile uint16_t count=0;
ISR(TIMER1_COMPA_vect){
  //OCR1A += 25000;// Advance The Compare A Register
  count +=1;
}

void setup() {
  TCCR1B |= (1<<1)|(1<<0);//SET PRESCALER = 64
  OCR1A = 25000;// TIMER COMPARE A REGISTER
  TIMSK1 |=(1<<1);// ENABLE TIMER Compare A INTERRUPT
  DDRB |= (1<<5);
  PORTB |= (1<<5);
}

void loop() {
  if((count % 1000) == 0 ){
    PORTB ^= (1<<5);
    count=0;
  }
  // put your main code here, to run repeatedly:

}
