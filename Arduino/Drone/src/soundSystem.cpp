#include "soundSystem.h"
soundSystem::soundSystem(){
}
void soundSystem::initBuzzer()
{
    
    pinMode(BuzzerPin,OUTPUT);
      
    black= 35000/bpm; 
    blackp=black*1.5;
    white= black*2;
    whitep=white*1.5;
    rounda= black*4;
    roundp= rounda*1.5;
    quaver= black/2;
    quaverp=quaver*1.5;
    semiquaver= black/4;
    semiquaverp=semiquaver*1.5;
}

void soundSystem::playStartSound(){
    tone(BuzzerPin,Do,black);
    delay(black+50);
    tone(BuzzerPin,Re,black);
    delay(black+50);
    tone(BuzzerPin,Mi,black*2);
    delay(black+50);
}



void soundSystem::playStopSound()
{

    tone(BuzzerPin,Mi,black);
    delay(black+50);
    tone(BuzzerPin,Re,black);
    delay(black+50);
    tone(BuzzerPin,Do,black*2);
    delay(black+50);

}

void soundSystem::playConnectSound()
{

}

void soundSystem::playDisconnectSound()
{



}