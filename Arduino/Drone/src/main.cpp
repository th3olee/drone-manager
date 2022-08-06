#include <Arduino.h>
#include "wifiController.h"
#include "soundSystem.h"
 
soundSystem *sound = new soundSystem();


void setup()
{
  // initialize LED digital pin as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("INIT");
  sound->initBuzzer();
  Serial.println("INIT F");

}

void loop()
{
  // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("ON F");


  // wait for a second
  delay(1000);
  sound->playStartSound();

  // turn the LED off by making the voltage LOW
  digitalWrite(LED_BUILTIN, LOW);

   // wait for a second
  delay(1000);
 
}