#pragma once
#include <Arduino.h>
#include <SoftwareSerial.h>


class soundSystem{
    public:
    soundSystem();
    void playStartSound();
    void playStopSound();
    void playConnectSound();
    void playDisconnectSound();
    void initBuzzer();
    
    private:
    int BuzzerPin = 8;     // Connect Buzzer to Arduino pin 8

    int Si2 =1975;
    int LaS2=1864;
    int La2= 1760;
    int SolS2=1661;
    int Sol2=1567;
    int FaS2=1479;
    int Fa2= 1396;
    int Mi2= 1318;
    int ReS2=1244;
    int Re2= 1174;
    int DoS2=1108;
    int Do2= 1046;

    // Low Octave
    int Si = 987;
    int LaS= 932;
    int La = 880;
    int SolS=830;
    int Sol= 783;
    int FaS= 739;
    int Fa=  698;
    int Mi=  659;
    int ReS= 622;
    int Re = 587;
    int DoS =554;
    int Do = 523;

    // define the notes
    int rounda=0;
    int roundp=0;
    int white= 0;
    int whitep=0;
    int black=0;  
    int blackp=0;
    int quaver=0;
    int quaverp =0;
    int semiquaver=0;
    int semiquaverp=0;
    int bpm= 120;
};

