#pragma once

#include <Arduino.h>
#include <Wire.h>
#include "HID-Project.h"
#include <Keypad.h>
#include <RotaryEncoder.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

const int SCREEN_WIDTH = 128; // OLED display width, in pixels
const int SCREEN_HEIGHT = 64; // OLED display height, in pixels

#define OLED_RESET -1       // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C // i2c Address display

unsigned long previousMillis_Oled = 0; // Zmienna przechowująca poprzedni czas
const long interval_5s = 5000;         // Interwał co 5 sekund (5000 ms)

const byte NUM_OF_BUTTON_PIN = 10;   // ilość przycisków podłączonych do arduino
const byte NUM_OF_BUTTON_FUNC = 9;   // ilość przycisków kture mają jakąś funkcje wysyłaną do komputera
const byte NUM_OF_PROFILE = 2;       // aktualna ilość profili
const byte NUM_OF_ESP32_IN_PINS = 3; // liczba pinów kture słóżą do sterowania esp32

const byte ROWS = 2;                    // woersze w matrycy przycisków
const byte COLS = 5;                    // kolumny w matrycy przycisków
byte rowPins[ROWS] = {15, 14};          // connect to the row pinouts of the keypad
byte colPins[COLS] = {10, 16, 4, 5, 6}; //{4, 5, 6, 10, 16}; // connect to the column pinouts of the keypad
bool keyPress[10] = {false, false, false, false, false, false, false, false, false, false};

int Current_Profile_Number = 0;                             // numer bierzącego profilu
String profileName[NUM_OF_PROFILE] = {"Default", "prof 2"}; // nazwy profili

const int ESP32_Pins_IN[NUM_OF_ESP32_IN_PINS] = {A0, A2, A1}; // definicja pinów wchodzących esp32
const int ESP32_Pins_OUT[1] = {A3};                           // definicja minów wychodzących z esp32
bool Desk_State = true;                                       // status biurka

const int encoderPin[3] = {8, 7, 9};          // pinA,PinB,button
volatile bool previousEncButtonValue = false; // poprzedni stan przyciku z enkodera do SurfaceDial
const int SDRotate = 10;

enum TKeyType
{
  KEYBOARD,
  CONSUMER,
  SYSTEM,
  TOESP32
}; // typy w jakich mogą pracować przyciski

enum ESP32Positions
{
  NONE,
  DESK_POWER,
  LIGHT,
  PRINTER,
}; // rzechy kturymi można sterować w esp32

struct MacroStrukt
{
  uint16_t kaycode;
  int Num_Of_Mod_Key;
  uint8_t ModKeys[3];
  enum TKeyType type;
  enum ESP32Positions position;
}; // struktura opisująca przycisk

// define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
    {'0', '1', '2', '3', '4'},
    {'5', '6', '7', '8', '9'},

};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);     // tworzenie obiektu odpowiedzialnego za button arry
RotaryEncoder encoder(encoderPin[0], encoderPin[1], RotaryEncoder::LatchMode::TWO03); // tworzenie obiektu odpowiedzialnego za enkoder do SurfaceDial
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);             // tworzenie obiektu odpowiedzialnego za wyświetlacz

MacroStrukt Button_Func[NUM_OF_PROFILE][NUM_OF_BUTTON_FUNC] = {
    {{KEY_F13, 0, {0, 0, 0}, KEYBOARD, NONE}, // diskord mic
     {KEY_F14, 0, {0, 0, 0}, KEYBOARD, NONE}, // discord spiker
     {KEY_F15, 0, {0, 0, 0}, KEYBOARD, NONE}, // steam mic
     {0, 0, {0, 0, 0}, TOESP32, DESK_POWER},  // wyłączanie biurka
     {0, 0, {0, 0, 0}, TOESP32, PRINTER},
     {MEDIA_PLAY_PAUSE, 0, {0, 0, 0}, CONSUMER, NONE},
     {MEDIA_PREV, 0, {0, 0, 0}, CONSUMER, NONE},
     {MEDIA_NEXT, 0, {0, 0, 0}, CONSUMER, NONE},
     {0, 0, {0, 0, 0}, TOESP32, LIGHT}},
    {{KEY_F16, 0, {0, 0, 0}, KEYBOARD, NONE},
     {KEY_F17, 0, {0, 0, 0}, KEYBOARD, NONE},
     {KEY_F18, 0, {0, 0, 0}, KEYBOARD, NONE},
     {KEY_F19, 0, {0, 0, 0}, KEYBOARD, NONE},
     {KEY_F20, 0, {0, 0, 0}, KEYBOARD, NONE},
     {KEY_F21, 0, {0, 0, 0}, KEYBOARD, NONE},
     {KEY_F22, 0, {0, 0, 0}, KEYBOARD, NONE},
     {KEY_F23, 0, {0, 0, 0}, KEYBOARD, NONE},
     {KEY_F24, 0, {0, 0, 0}, KEYBOARD, NONE}}}; // tablica opisująca karzdy przycisk z osobna na button arry z uwzględnieniem kilku profili

void buttons_func();
void hid_acctions();
void SurfaceDial_Func();
void To_ESP32(MacroStrukt);
void Chang_Profile();
void butonCharToBoolTable(char);
void display_update();