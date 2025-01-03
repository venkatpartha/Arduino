void setup() {
  ADCSRA |= (1<<7);// Enable the ADC
  ADMUX |= (1<<6);// set the referance voltage (AVcc with external capacitor at AREF pin)
  ADCSRA |= (1<<2)|(1<<1)|(1<<0);// Prescaler selection = 128
  ADMUX |= (1<<0);//select channel (ADC1)
  DDRD |=(1<<3);
  Serial.begin(9600);
}
volatile uint16_t adc_data=0;

uint16_t read_ADC(void){
  static uint16_t data=0;
  ADCSRA |= (1<<6);//start conversion
  while(ADCSRA & (1<<6));// check the conversion is ended or not
  data = (ADCH<<8)|ADCL;
  return ADC;
}
void loop() {
  adc_data= read_ADC();
  TCCR2A |= (1 << COM2B1) | (1 << WGM20); OCR2B = adc_data;//PWM registers
  Serial.println(adc_data);
  delay(100);
}
