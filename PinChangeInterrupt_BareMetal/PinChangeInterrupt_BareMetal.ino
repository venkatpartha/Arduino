ISR(PCINT2_vect){
  PORTB ^= (1<<0);
  delay(1000);
}
void setup() {
  DDRB |= (1<<0);//set the pin PB0 or digital pin 8 as output
  PORTB &= ~(1<<0);
  DDRD &= ~(1<<4);//set the pin PD2 or Digital pin 2 as input 
  PORTD |= (1<<2);//ENABLING THE PULLUP RESISTOR TO THE CORRESPONDING BUTTON PIN 
                  //TO AVOID UNRELIABLE OR RAMDOM BUTTON BEHAVIOR 
  //SREG |= (1<<7);//ENABLING THE GLOBAL INTERRUPT
  sei();
  PCICR |= (1<<2);//ENABLE PIN CHANGE INTERRUPT
  PCMSK2 |= (1<<4);//ENABLE THE EXTERNAL INTERRUPT 0
}

void loop() {
  // put your main code here, to run repeatedly:
  //PORTB |= (1<<0);

}
