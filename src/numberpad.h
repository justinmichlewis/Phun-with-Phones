#include <Keypad.h>
#include <Arduino.h>

// KEYPAD
const byte ROWS = 4; // four rows
const byte COLS = 4; // four columns
char keys[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};

byte rowPins[COLS] = {A3, A2, A1, A0}; // connect to the row pinouts of the keypad
byte colPins[ROWS] = {7, 6, 5, 4};     // connect to the column pinouts of the keypad

Keypad k = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

char getKeyPressed()
{
    char key_pressed = k.getKey();
    if (key_pressed)
    {

        return key_pressed;
    }
    return '\0';
}
