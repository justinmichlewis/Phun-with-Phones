#include <string.h>
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);

void initializeDisplay(char lineOne[], char lineTwo[], int delayMs)
{
  // Setup LCD
  lcd.init();
  lcd.backlight();
  lcd.print(lineOne);
  lcd.setCursor(0, 1); // Moves cursor to second line of the display so phone # is displayed under name
  lcd.print(lineTwo);
  delay(delayMs);
}
void displayPhoneCall(char name[], char number[])
{
  char lineOne[15];
  char lineTwo[15];

  strcpy(lineOne, name);
  Serial.write(lineOne);
  strcpy(lineTwo, number);

  delay(500);

  lcd.clear();
  lcd.print(lineOne);
  lcd.setCursor(0, 1);
  lcd.print(lineTwo);

  delay(3000);

  lcd.clear();
  lcd.print("Connected");
}

void resetDisplayPhoneCall()
{
  lcd.clear();
  lcd.print("Dial number to");
  lcd.setCursor(0, 1);
  lcd.print("begin...");
}

void clearDisplay()
{
  lcd.clear();
  Serial.println("Clearing display...");
}

void displayKeyboardInput(char input)
{
  lcd.print(input);
}

void displayAdmirer()
{
  lcd.clear();
  lcd.print("Enter admirer's ");
  lcd.setCursor(0, 1);
  lcd.print("phone number.");
}

void displayAdmirerFound(char name[])
{
  lcd.clear();
  lcd.print("Admirer found:");
  lcd.setCursor(0, 1);
  lcd.print(name);
}

void displayAdmirerNotFound()
{
  lcd.clear();
  lcd.print("Admirer not");
  lcd.setCursor(0, 1);
  lcd.print("found.");
}

void displaySetUp()
{
  lcd.clear();
  lcd.print("Males(A) Both(B)");
  lcd.setCursor(0, 1);
  lcd.print("Females(C)");
}