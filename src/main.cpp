#include <Arduino.h>
#include "linked_list.h"
#include "display.h"
#include "struct_people.h"
#include "numberpad.h"
#include "audio.h"

#define sounds 1
#define male 2
#define female 3
#define maleFemale 4

int isSetUp = true;
char admirerGroup = 'M';
int admirerId = 0;
bool admirerCheck = false;
int keyIndex = 0;
bool isConnected = false;
char keyArray[7];

int getRandomPerson(int maxIndex);
int getRandomPerson(int numberOfAdmirers);
People findPerson(char keyArray[]);
void connectCall(People person);

void setup()
{
  // Setup.debug
  Serial.begin(115200);
  initializeAudio();
  // admirerId = getRandomPerson(10);
  // initializeDisplay("Phun with Phones", "", 2000);
  // displaySetUp();
  // resetDisplayPhoneCall();
  playRing(20);
}

void loop()
{

  char key = getKeyPressed();

  if (key != '\0')
  {
    Serial.println(key);
    if (keyIndex == 0)
    {
      clearDisplay();
    }

    if (key == 'C' && !isConnected)
    {
      clearDisplay();
      keyIndex = 0;
      memset(keyArray, 0, sizeof(keyArray));
      return;
    }
    else if (key == 'C' && isSetUp)
    {
      resetDisplayPhoneCall();
      admirerGroup = 'F';
      isSetUp = false;
    }
    if (key == 'D')
    {
      Serial.println("Dialing...");
      playRing(15);
    }

    if (key == 'A' && !isConnected)
    {
      Serial.println("Admirer Group: ");
      Serial.println(admirerGroup);
      People person = findPerson(keyArray);

      playRing(15);
      connectCall(person);
      // If person id is 0, no person found
      if (person.id != 0)
        playVoice(male, person.id, 20);
      else
        playDisconnected(15);

      isConnected = true;
    }
    else if (key == 'A' && isConnected)
    {
      resetDisplayPhoneCall();
      isConnected = false;
      memset(keyArray, 0, sizeof(keyArray));
      keyIndex = 0;
    }
    else if (key == 'A' && isSetUp)
    {
      admirerGroup = 'M';
      resetDisplayPhoneCall();
      isSetUp = false;
    }

    if (key == 'B' && isSetUp)
    {
      admirerGroup = 'B';
      resetDisplayPhoneCall();
      isSetUp = false;
    }

    if (keyIndex < 7 && key != 'A' && key != 'C')
    {
      keyArray[keyIndex] = key;
      displayKeyboardInput(key);
      keyIndex++;
      Serial.print(keyArray);
      Serial.println(' ');
    }

    if (key == '#')
    {
      if (!admirerCheck)
      {
        displayAdmirer();
        keyIndex = 0;
        memset(keyArray, 0, sizeof(keyArray));
        admirerCheck = true;
      }
      else
      {
        if (strcmp(peopleMale[admirerId - 1].number, keyArray) == 0)
        {
          displayAdmirerFound(peopleMale[admirerId - 1].name);
        }
        else
        {
          displayAdmirerNotFound();
        }
        admirerCheck = false;
      }
    }
    else
    {
      return;
    }
  }
}

People findPerson(char keyArray[])
{
  char *searchNumber = keyArray;
  People *foundPerson = nullptr;

  for (int i = 0; i < 10; i++)
  {
    if (strcmp(peopleMale[i].number, searchNumber) == 0)
    {
      foundPerson = &peopleMale[i];
      break;
    }
  }

  if (foundPerson != nullptr)
  {
    Serial.print("Found: ");
    Serial.println(foundPerson->name);
    return *foundPerson;
  }
  else
  {

    People p = {"Unknown", "", 0};
    Serial.println("Number not found.");
    return p;
  }
}

void connectCall(People person)
{
  if (person.id != 0)
  {
    Serial.print("Found: ");
    Serial.println(person.name);
    displayPhoneCall(person.name, person.number);
  }
  else
  {
    Serial.println("Number not found.");
    displayPhoneCall("Unknown", person.number);
  }
}

int getRandomPerson(int numberOfAdmirers)
{
  randomSeed(analogRead(0)); // NOTE: the pin defined in analogRead must not be in use!!!!!!
  return random(1, numberOfAdmirers + 1);
}
