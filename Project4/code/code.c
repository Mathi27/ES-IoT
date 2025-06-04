#include <LiquidCrystal_I2C.h>
#define LCD_ADDR 0x27
#define LCD_COL 16
#define LCD_ROW 2

LiquidCrystal_I2C lcd(LCD_ADDR, LCD_COL, LCD_ROW);

void setup() {

lcd.begin(16,2);
lcd.init();
lcd.backlight();

lcd.setCursor(5,0);
lcd.print("Hello");

lcd.setCursor(5,1);
lcd.print("World");

}

void loop() {
  // put your main code here, to run repeatedly:

}
