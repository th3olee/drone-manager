#include <Arduino.h>
#include <SoftwareSerial.h>
#include "wifiController.h"
#include "soundSystem.h"
 
soundSystem *sound = new soundSystem();


#include "env.h"

SoftwareSerial esp8266(10,11);
#define serialCommunicationSpeed 115200
#define DEBUG true

String sendData(String command, const int timeout, boolean debug)
{
<<<<<<< HEAD
  // initialize LED digital pin as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("INIT");
  sound->initBuzzer();
  Serial.println("INIT F");

=======
    String response = "";                                             
    esp8266.print(command);                                          
    long int time = millis();                                      
    while( (time+timeout) > millis())                                 
    {      
      while(esp8266.available())                                      
      {
        char c = esp8266.read();                                     
        response+=c;                                                  
      }  
    }    
    if(debug)                                                        
    {
      Serial.print(response);
    }    
    return response;                                                  
>>>>>>> 833d45887dac7cb3e80c5ee035f8b8cf876495aa
}

void InitWifiModule()
{
<<<<<<< HEAD
  // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("ON F");


  // wait for a second
  delay(1000);
  sound->playStartSound();
=======
  sendData("AT+RST\r\n", 2000, DEBUG);
  String wifi = "AT+CWJAP=" + String(WIFI) + "," + String(WIFI_PASSWORD) + "\r\n";
  sendData(wifi, 2000, DEBUG);
  delay(3000);
  sendData("AT+CWMODE=1\r\n", 1500, DEBUG);
  delay(1500);
  sendData("AT+CIFSR\r\n", 1500, DEBUG);
  delay(1500);
  sendData("AT+CIPMUX=1\r\n", 1500, DEBUG);
  delay(1500);
  sendData("AT+CIPSERVER=1,80\r\n", 1500, DEBUG);
  delay(1500);
  Serial.println("Wifi initialisation finished.");
}

void setup()

{
  Serial.begin(serialCommunicationSpeed);           
  esp8266.begin(serialCommunicationSpeed);     
  InitWifiModule();                              
}
>>>>>>> 833d45887dac7cb3e80c5ee035f8b8cf876495aa

void loop()                                                         
{

  if(esp8266.available())                                           
 {    
    if(esp8266.find("+IPD,"))
    {
     delay(1000);
 
     int connectionId = esp8266.read()-48;                                                
     String webpage = "<h1>Hello World!</h1>";
     String cipSend = "AT+CIPSEND=";
     cipSend += connectionId;
     cipSend += ",";
     cipSend +=webpage.length();
     cipSend +="\r\n";
     
     sendData(cipSend,1000,DEBUG);
     sendData(webpage,1000,DEBUG);
 
     String closeCommand = "AT+CIPCLOSE="; 
     closeCommand+=connectionId; // append connection id
     closeCommand+="\r\n";    
     sendData(closeCommand,3000,DEBUG);
    }
  }
}

