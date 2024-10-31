#include <string.h>
#include <Arduino.h>
#include <Adafruit_ST7735.h>
#include <Adafruit_GFX.h>
#include <SdFat.h>
#include <Adafruit_ImageReader.h>
#include <SPI.h>

#define TFT_CS 10
#define TFT_RST 9
#define TFT_DC 8
#define SD_CS 3

SdFat SD;
Adafruit_ImageReader reader(SD);

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
Adafruit_Image img;
int32_t width = 0,
        height = 0;

void centerText(const char text[], int textSize);

void initializeDisplay(char lineOne[], char lineTwo[], int delayMs)
{
  // Intialize SD as wellf or reading bmp images
  if (!SD.begin(SD_CS, SD_SCK_MHZ(10)))
  { // Breakouts require 10 MHz limit due to longer wires
    // Serial.println(F("SD begin() failed"));
    for (;;)
      ; // Fatal error, do not continue
  }

  tft.initR(INITR_144GREENTAB);
  tft.fillScreen(ST7735_BLACK);
  tft.setRotation(3);
  centerText(lineOne, 2);
  delay(delayMs);
  tft.fillScreen(ST7735_BLACK);
}
void displayPhoneCall(char name[], char number[])
{
  char lineOne[15];
  char lineTwo[15];

  strcpy(lineOne, name);
  Serial.write(lineOne);
  strcpy(lineTwo, number);
  tft.println(name);
  tft.println(number);

  delay(500);

  // delay(3000);

  // lcd.clear();
  // lcd.print("Connected");
}

void resetDisplayPhoneCall()
{

  tft.fillScreen(ST7735_BLACK);
  tft.print("Dial number to begin...");
  // lcd.clear();
  // lcd.print("Dial number to");
  // lcd.setCursor(0, 1);
  // lcd.print("begin...");
}

void clearDisplay()
{
  tft.fillScreen(ST7735_BLACK);
  // lcd.clear();
  Serial.println("Clearing display...");
}

void displayKeyboardInput(char input)
{
  tft.print(input);
  // lcd.print(input);
}

void displayAdmirer()
{
  // lcd.clear();
  // lcd.print("Enter admirer's ");
  // lcd.setCursor(0, 1);
  // lcd.print("phone number.");
}

void displayAdmirerFound(char name[])
{
  // lcd.clear();
  // lcd.print("Admirer found:");
  // lcd.setCursor(0, 1);
  // lcd.print(name);
}

void displayAdmirerNotFound()
{
  // lcd.clear();
  // lcd.print("Admirer not");
  // lcd.setCursor(0, 1);
  // lcd.print("found.");
}

void displaySetUp()
{
  // lcd.clear();
  // lcd.print("Males(A) Both(B)");
  // lcd.setCursor(0, 1);
  // lcd.print("Females(C)");
}

ImageReturnCode displayImage(const char *filename)
{
  ImageReturnCode stat;
  stat = reader.drawBMP(filename, tft, 30, 0);
  return stat;
}

void centerText(const char text[], int textSize)
{
  // Set text size and color
  tft.setTextSize(textSize);
  tft.setTextColor(ST7735_RED);

  // Get the width and height of the text
  int16_t x, y; // Temporary variables to store cursor position
  uint16_t textWidth, textHeight;
  tft.getTextBounds(text, 0, 0, &x, &y, &textWidth, &textHeight);

  // Calculate center position
  int16_t centerX = (tft.width() - textWidth) / 2;
  int16_t centerY = (tft.height() - textHeight) / 2;

  // Set cursor and print text
  tft.setCursor(centerX, centerY);
  tft.println(text);
}