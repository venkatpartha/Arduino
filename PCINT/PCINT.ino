/*
* LAB Name: Arduino PCINT Example
* Author: Khaled Magdy
* For More Info Visit: www.DeepBlueMbedded.com
*/
#include "PinChangeInterrupt.h"
 
#define BTN0_PIN  8
#define BTN1_PIN  9
#define LED0_PIN  6
#define LED1_PIN  7
 
void BTN0_ISR(void)
{
  digitalWrite(LED0_PIN, !digitalRead(LED0_PIN));
}
 
void BTN1_ISR(void)
{
  digitalWrite(LED1_PIN, !digitalRead(LED1_PIN));
}
 
void setup() {
  pinMode(LED0_PIN, OUTPUT);
  pinMode(LED1_PIN, OUTPUT);
  pinMode(BTN0_PIN, INPUT);
  pinMode(BTN1_PIN, INPUT);
  attachPCINT(digitalPinToPCINT(BTN0_PIN), BTN0_ISR, RISING);
  attachPCINT(digitalPinToPCINT(BTN1_PIN), BTN1_ISR, RISING);
}
 
void loop() {
  // Do Nothing
}