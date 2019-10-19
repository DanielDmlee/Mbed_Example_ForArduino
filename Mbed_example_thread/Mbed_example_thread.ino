#include <mbed.h>

using namespace rtos;

Thread thread;

void ledG_thread() {
  bool led=LOW;
  while (true) {
    led != led;
    digitalWrite(LEDG, led);   // turn the LED on (HIGH is the voltage level)
    wait(1);
  }
}

void ledB_thread() {
  bool led=LOW;
  while (true) {
    led != led;
    digitalWrite(LEDB, led);   // turn the LED on (HIGH is the voltage level)
    wait_ms(500);
  }
}

void setup()
{
  Serial.begin(9600);
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);

  digitalWrite(LEDR, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LEDG, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LEDB, LOW);   // turn the LED on (HIGH is the voltage level)
  thread.start(ledG_thread);
  thread.start(ledB_thread);
}

void loop()
{ 
    Serial.print("1");
    digitalWrite(LEDR, HIGH);   // turn the LED on (HIGH is the voltage level)
    wait_ms(500);  
    Serial.print("2");
    digitalWrite(LEDR, LOW);   // turn the LED on (HIGH is the voltage level)
    wait_ms(500);                       // wait for a second
}
