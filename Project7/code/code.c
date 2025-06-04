#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <string.h>

#define LCD_ADDR 0x27
#define LCD_COL 16
#define LCD_ROW 2

LiquidCrystal_I2C lcd(LCD_ADDR, LCD_COL, LCD_ROW);
Servo myServo;

const byte ROW = 4;
const byte COL = 4;
char pass[5];
int i = 0;
int j = 0;
int servo = 5;
bool lock = false;

char keys[ROW][COL] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROW] = {13, 12, 11, 10};
byte colPins[COL] = {9, 8, 7, 6};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROW, COL);

void setup() {
  myServo.attach(servo);
  myServo.write(90);
  lcd.init();          
  lcd.backlight();     
  lcd.noCursor();      
}

void loop() {
  if (!lock) {
    if (j == 0) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Enter Password");    
      lcd.setCursor(0, 1);
      j++;
    }

    char key = keypad.getKey();

    if (key != NO_KEY && i < 4) {
      pass[i] = key;
      i++;
      lcd.print("*");
      delay(150);
    }

    if (i == 4) {
      pass[4] = '\0';

      lcd.clear();
      lcd.print("Password: ");
      lcd.print(pass);
      delay(1000);
      lcd.clear();

      if (strcmp(pass, "2003") == 0) {
        lcd.print("Correct");
        delay(1000);
        myServo.write(0);
        delay(5000);
        myServo.write(90);
      } else {
        lcd.print("Incorrect");
        delay(1000);
      }

      strcpy(pass, "0000");
      i = 0;
      j = 0;
      lcd.clear();
    }
  }
}
