#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

#define LCD_ADDR 0x27
#define LCD_COLS 16
#define LCD_ROWS 2

LiquidCrystal_I2C lcd(LCD_ADDR, LCD_COLS, LCD_ROWS);

// Keypad setup
const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

String input = "";
bool confirmed = false;

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Enter Decimal:");
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    if (!confirmed) {
      if (key >= '0' && key <= '9') {
        if (input.length() < 4) {
          input += key;
          lcd.setCursor(0, 1);
          lcd.print("                ");
          lcd.setCursor(0, 1);
          lcd.print(input);
        }
      } else if (key == '#') {
        if (input.length() > 0) {
          confirmed = true;
          int decimal = input.toInt();
          showBinary(decimal);
        }
      } else if (key == '*') {
        input = "";
        lcd.setCursor(0, 1);
        lcd.print("                ");
      }
    } else {
      if (key == '*') {
        confirmed = false;
        input = "";
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Enter Decimal:");
        lcd.setCursor(0, 1);
      }
    }
  }
}

void showBinary(int num) {
  String binary = "";

  if (num == 0) {
    binary = "0";
  } else {
    while (num > 0) {
      binary = String(num % 2) + binary;
      num /= 2;
    }
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Dec: " + input);
  lcd.setCursor(0, 1);
  lcd.print("Bin: " + binary);
}
