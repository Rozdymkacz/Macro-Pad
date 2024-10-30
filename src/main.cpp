#include <Arduino.h>
#include <Wire.h>
#include "HID-Project.h"
#include <Keypad.h>
#include <RotaryEncoder.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "main.hpp"
#include "fish_SD.h"

// Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup()
{
  Serial.begin(9600); // inicjacja portu szeregowego
  // delay(2000);
  // Serial.println("Serial gotów");

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
  {
    delay(3000);
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ; // Don't proceed, loop forever
  }

  display.display();
  delay(2000); // Pause for 2 seconds

  display.clearDisplay();
  display.drawBitmap(0, 0, epd_bitmap_rozdymka_SD, SCREEN_WIDTH, SCREEN_HEIGHT, 1);
  display.display();
  delay(1000);

  for (int i = 0; i < NUM_OF_ESP32_PINS; i++)
  {
    pinMode(ESP32_Pins_IN[i], OUTPUT);
    digitalWrite(ESP32_Pins_IN[i], HIGH);
  }
  pinMode(ESP32_Pins_OUT[0], INPUT_PULLUP);

  pinMode(encoderPin[2], INPUT_PULLUP);

  Keyboard.begin(); // inicjacja klawiatury (od teraz możer symulować klawiature)
  Consumer.begin();
  System.begin();
  SurfaceDial.begin();
  delay(1000); // Czekaj na stabilizację
}

void loop()
{
  unsigned long currentMillis = millis(); // Odczytaj bieżący czas'

  bool esp32out1 = !digitalRead(ESP32_Pins_OUT[0]);

  if (esp32out1 != Desk_State)
  {
    if (esp32out1)
    {
      Desk_State = true;
    }
    else
    {
      Desk_State = false;
    }
    display_update();
  }

  // Sprawdź, czy upłynęło 5 sekund
  if (currentMillis - previousMillis_Oled >= interval_5s)
  {
    previousMillis_Oled = currentMillis; // Zaktualizuj czas dla następnego sprawdzenia
    display_update();
  }

  SurfaceDial_Func();
  buttons_func();
}

void buttons_func()
{
  char customKey = customKeypad.getKey();
  if (!customKey)
  {
    return;
  }

  butonCharToBoolTable(customKey);
  Chang_Profile();
  hid_acctions();
  for (int i = 0; i < sizeof(keyPress) / sizeof(keyPress[0]); i++)
  {
    keyPress[i] = false;
  }
}

void hid_acctions()
{
  for (int i = 0; i < NUM_OF_BUTTON_FUNC; i++) // pętla sprawdzająca naciśnięcie symulowanych przycisków
  {
    if (keyPress[i])
    {
      MacroStrukt tmpMS = Button_Func[Current_Profile_Number][i];
      if (tmpMS.Num_Of_Mod_Key > 0 || tmpMS.Num_Of_Mod_Key < 3)
      {
        if (tmpMS.position == ESP32Positions::NONE)
        {
          for (int j = 0; j < tmpMS.Num_Of_Mod_Key; j++)
          {
            Keyboard.press(KeyboardKeycode(tmpMS.ModKeys[j]));
            Serial.println(tmpMS.ModKeys[j]);
          }
        }
      }

      switch (tmpMS.type)
      {
      case TKeyType::KEYBOARD:
        Keyboard.press(KeyboardKeycode(tmpMS.kaycode)); // symulowanie kliknięcia odpowiedniego przycisku klawiatury
        break;

      case TKeyType::CONSUMER:
        Consumer.write(ConsumerKeycode(tmpMS.kaycode)); // symulowanie kliknięcia odpowiedniego przycisku klawiatury
        break;

      case TKeyType::SYSTEM:
        System.write(SystemKeycode(tmpMS.kaycode)); // symulowanie kliknięcia odpowiedniego przycisku klawiatury
        break;

      case TKeyType::TOESP32:
        To_ESP32(tmpMS);
        break;

      default:
        break;
      }
      Serial.println(tmpMS.kaycode);
      delay(50); // opuźnienie na odczyt przez komputer
      Keyboard.releaseAll();
      delay(200); // opuźnienie dosymulowania puszczenia przycisku (*1)
    }
  }
}

void SurfaceDial_Func()
{
  encoder.tick();

  bool buttonValue = digitalRead(encoderPin[2]);
  if (buttonValue != previousEncButtonValue)
  {
    if (buttonValue)
    {
      SurfaceDial.press();
      Serial.println("SD pres");
    }
    else
    {
      SurfaceDial.release();
      Serial.println("SD release");
    }
    previousEncButtonValue = buttonValue;
  }

  RotaryEncoder::Direction direct = encoder.getDirection();

  if (direct == RotaryEncoder::Direction::CLOCKWISE)
  {
    SurfaceDial.rotate(SDRotate);
    Serial.println("SD +");
  }
  else if (direct == RotaryEncoder::Direction::COUNTERCLOCKWISE)
  {
    SurfaceDial.rotate(SDRotate * -1);
    Serial.println("SD -");
  }
}

void To_ESP32(MacroStrukt _tmpMS)
{
  switch (_tmpMS.position)
  {
  case ESP32Positions::NONE:
    Serial.println(" esp32 None ");
    return;
    break;

  case ESP32Positions::DESK_POWER:
    Serial.println(" esp32 power desk");
    Keyboard.press(KeyboardKeycode(KEY_LEFT_GUI));
    Keyboard.press(KeyboardKeycode(KEY_L));
    //delay(100);
    //Keyboard.releaseAll();
    Consumer.write(ConsumerKeycode(MEDIA_STOP));
    display_update();
    analogWrite(ESP32_Pins_IN[0], 0);
    delay(200);
    analogWrite(ESP32_Pins_IN[0], 1024);
    break;

  case ESP32Positions::PRINTER:
    Serial.println("esp32 drukarka");
    analogWrite(ESP32_Pins_IN[1], 0);
    delay(200);
    analogWrite(ESP32_Pins_IN[1], 1024);
    break;

  case ESP32Positions::LIGHT:
    Serial.println("esp32 światłO");
    analogWrite(ESP32_Pins_IN[2], 0);
    delay(200);
    analogWrite(ESP32_Pins_IN[2], 1024);
    break;

  default:
    return;
    break;
  }
}

void Chang_Profile()
{
  Serial.println("Dobry");
  if (keyPress[9]) // sprawdzanie czy przycisko od zmiany profilu na następny nie został kliknięty
  {
    Current_Profile_Number++; // Zwiększenie numeru profilu
    if (Current_Profile_Number > NUM_OF_PROFILE - 1)
    {                             // Sprawdzenie, czy przekroczono maksymalny numer profilu
      Current_Profile_Number = 0; // Powrót do profilu nr 0
    }
    Serial.println("");
    Serial.println("profil nr.");
    Serial.println(Current_Profile_Number);
    display_update();
    delay(300);
  }
}

void butonCharToBoolTable(char _key)
{

  switch (_key)
  {
  case '0':
    keyPress[0] = true;
    break;
  case '1':
    keyPress[1] = true;
    break;
  case '2':
    keyPress[2] = true;
    break;
  case '3':
    keyPress[3] = true;
    break;
  case '4':
    keyPress[4] = true;
    break;
  case '5':
    keyPress[5] = true;
    break;
  case '6':
    keyPress[6] = true;
    break;
  case '7':
    keyPress[7] = true;
    break;
  case '8':
    keyPress[8] = true;
    break;
  case '9':
    keyPress[9] = true;
    break;

  default:
    break;
  }
}

void display_update()
{
  display.clearDisplay();

  display.setTextColor(SSD1306_WHITE); // Draw white text
  display.setTextSize(3);
  display.setCursor(0, 0);
  display.println(profileName[Current_Profile_Number]);

  display.setTextSize(1);
  display.setCursor(0, 54);
  display.print(F("Stan Biurka:  "));

  if (Desk_State == true)
  {
    display.fillRect(75, 54, 8, 8, SSD1306_WHITE);
  }
  else
  {
    display.drawRect(75, 54, 8, 8, SSD1306_WHITE);
  }

  display.display();
}
