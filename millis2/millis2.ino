/*
* LAB Name: Arduino millis() Multitasking Example
* Author: Khaled Magdy
* For More Info Visit: www.DeepBlueMbedded.com
*/
#define BTN_PIN  4
#define LED_PIN  5
 
unsigned long Task1_T1 = 0, Task2_T1 = 0, Task3_T1 = 0, T2 = 0;
uint8_t btnC_State = 1, btnP_State = 1, btnState = 1;
uint8_t Task1_Periodicity = 70;
uint8_t Task2_Periodicity = 25;
uint8_t Task3_Periodicity = 200;
 
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BTN_PIN, INPUT_PULLUP);
  Serial.begin(9600);
}
 
void loop()
{
  T2 = millis();
  Serial.print("T2: ");
  Serial.println(T2);
  if( (T2 - Task1_T1) >= Task1_Periodicity )
  {
    Task1_Handler();
    Task1_T1 = millis();
    Serial.print("Task1_T1: ");
    Serial.println(Task1_T1);
  }
  if( (T2 - Task2_T1) >= Task2_Periodicity )
  {
    Task2_Handler();
    Task2_T1 = millis();
    Serial.print("Task2_T1: ");
    Serial.println(Task2_T1);
  }
  if( (T2 - Task3_T1) >= Task3_Periodicity )
  {
    Task3_Handler();
    Task3_T1 = millis();
    Serial.print("Task3_T1: ");
    Serial.println(Task3_T1);
  }
}
 
void Task1_Handler(void)
{
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN)); // Toggle LED State
}
void Task2_Handler(void)
{
  btnC_State = digitalRead(BTN_PIN);
  if(btnC_State == 0 && btnP_State == 0)
  {
    digitalWrite(LED_PIN, 1);
  }
  else
  {
    digitalWrite(LED_PIN, 0);
    btnP_State = btnC_State;
  }
}
void Task3_Handler(void)
{
  Serial.print("Button State is: ");
  Serial.println(btnState);
}