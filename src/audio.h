#include "Arduino.h"
#include "DFRobotDFPlayerMini.h"
#include <SoftwareSerial.h>

SoftwareSerial softSerial(/*rx =*/10, /*tx =*/11);
#define FPSerial softSerial

DFRobotDFPlayerMini myDFPlayer;

void initializeAudio()
{
    FPSerial.begin(9600);

    if (!myDFPlayer.begin(FPSerial, /*isACK = */ true, /*doReset = */ true))
    {
        Serial.println(F("Unable to begin:"));
        Serial.println(F("1.Please recheck the connection!"));
        Serial.println(F("2.Please insert the SD card!"));
    }
    Serial.println(F("DFPlayer Mini online."));
}

void playRing(int volume)
{
    myDFPlayer.volume(volume);
    Serial.println("Playing ring...");
    myDFPlayer.playFolder(1, 1);
}

void playDisconnected(int volume)
{
    myDFPlayer.volume(volume);
    Serial.println("Playing disconnected...");
    myDFPlayer.playFolder(1, 2);
}
void playVoice(int folderId, int voiceId, int volume)
{
    Serial.print("Playing voice for: ");
    // Serial.println(voiceId);
    myDFPlayer.volume(volume);
    myDFPlayer.playFolder(folderId, voiceId);
}
