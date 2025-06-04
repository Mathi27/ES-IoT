#include <LiquidCrystal_I2C.h>
#define LCD_ADDR 0x27
#define LCD_COL 16
#define LCD_ROW 2

LiquidCrystal_I2C lcd(LCD_ADDR, LCD_COL, LCD_ROW);

int yellow = 13;
int magenta = 12;
int buttony = 11;
int buttonm = 10;
bool locked = false;
int y = 0;
int m = 0;

void setup() {
  pinMode(yellow, OUTPUT);
  pinMode(magenta, OUTPUT);
  pinMode(buttony, INPUT);
  pinMode(buttonm, INPUT);

lcd.begin(16,2);
lcd.init();
lcd.backlight();

lcd.setCursor(4,0);
lcd.print("Reaction");

lcd.setCursor(6,1);
lcd.print("Time");

delay(1000);

lcd.clear();

delay(1000);

lcd.setCursor(8,1);
lcd.print("3");

delay(1000);

lcd.clear();
lcd.setCursor(8,1);
lcd.print("2");

delay(1000);

lcd.clear();
lcd.setCursor(8,1);
lcd.print("1");

delay(1000);

lcd.clear();
lcd.setCursor(7,1);
lcd.print("GO");

}

void loop() {
  if (!locked) {
    int buttonys = digitalRead(buttony);
    int buttonms = digitalRead(buttonm);

    if (buttonys == HIGH) {
      y = 1;
      m = 0;
      locked = true;
    } else if (buttonms == HIGH) {
      m = 1;
      y = 0;
      locked = true;
    }
  }

  digitalWrite(yellow, y == 1 ? HIGH : LOW);
  digitalWrite(magenta, m == 1 ? HIGH : LOW);

  delay(100);
}
