#include <Keypad.h>
#include <Arduino.h>

const char number_of_rows = 4;
const char number_of_columns = 4;

byte row_pins[number_of_rows] = {2, 3, 4, 5};
byte column_pins[number_of_columns] = {6, 7, 8, 9};

char key_array[number_of_rows][number_of_columns] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};

Keypad k = Keypad(makeKeymap(key_array), row_pins, column_pins, number_of_rows, number_of_columns);

char getKeyPressed()
{
    char key_pressed = k.getKey();
    if (key_pressed)
    {

        return key_pressed;
    }
    return '\0';
}
