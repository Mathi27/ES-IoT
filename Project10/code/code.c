#include <LiquidCrystal_I2C.h>
#define LCD_ADDR 0x27
#define LCD_COL 16
#define LCD_ROW 2

LiquidCrystal_I2C lcd(LCD_ADDR, LCD_COL, LCD_ROW);

int redPins[]   = {13, 10, 7};
int greenPins[] = {12, 9, 6};
int bluePins[]  = {11, 8, 5};

int button = 4;
int del = 300;
bool lockr = false;
bool lock = false;
int rando[3];
int rem = 2000;
int buttonr = 3;
int l = 0;

void setup() {
  lcd.begin(16,2);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(2,0);
  lcd.print("PUSH BUTTON");
  lcd.setCursor(6,1);
  lcd.print(rem);

  randomSeed(analogRead(A0));

  for (int i = 0; i < 3; i++) {
    pinMode(redPins[i], OUTPUT);
    pinMode(greenPins[i], OUTPUT);
    pinMode(bluePins[i], OUTPUT);
  }

  pinMode(button, INPUT);
  pinMode(buttonr, INPUT);
}

void setColor(bool red, bool green, bool blue) {
  for (int i = 0; i < 3; i++) {
    digitalWrite(redPins[i], red);
    digitalWrite(greenPins[i], green);
    digitalWrite(bluePins[i], blue);
  }
}

void setColor1(bool r, bool g, bool b) {
  digitalWrite(redPins[0], r);
  digitalWrite(greenPins[0], g);
  digitalWrite(bluePins[0], b);
}

void setColor2(bool r, bool g, bool b) {
  digitalWrite(redPins[1], r);
  digitalWrite(greenPins[1], g);
  digitalWrite(bluePins[1], b);
}

void setColor3(bool r, bool g, bool b) {
  digitalWrite(redPins[2], r);
  digitalWrite(greenPins[2], g);
  digitalWrite(bluePins[2], b);
}

void loop() {
  del = 300;
  int buttonS = digitalRead(button);
  int buttonrS = digitalRead(buttonr);
  lock = (buttonS == HIGH);
  lockr = (buttonrS == HIGH);
  if (lockr == HIGH && l == 0){
    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("CASHOUT!");
    lcd.setCursor(6,1);
    lcd.print(rem - rem/10);
    l=1;
  }

  if (lock == HIGH && rem > 0 && l==0) {
    for (int j = 0; j < 3; j++) {
      rando[j] = random(6);
    }

    for (int j = 0; j < 3; j++) {
      setColor(HIGH, LOW, LOW);   delay(del); // Red
      setColor(LOW, HIGH, LOW);   delay(del); // Green
      setColor(LOW, LOW, HIGH);   delay(del); // Blue
      setColor(HIGH, HIGH, LOW);  delay(del); // Yellow
      setColor(HIGH, LOW, HIGH);  delay(del); // Magenta
      setColor(LOW, HIGH, HIGH);  delay(del); // Cyan

      if (j > 1) {
        del += 100;
      }
    }

    for (int k = 0; k < 3; k++) {
      bool r = LOW, g = LOW, b = LOW;

      switch (rando[k]) {
        case 0: r = HIGH; break;                         // Red
        case 1: g = HIGH; break;                         // Green
        case 2: b = HIGH; break;                         // Blue
        case 3: r = HIGH; g = HIGH; break;               // Yellow
        case 4: r = HIGH; b = HIGH; break;               // Magenta
        case 5: g = HIGH; b = HIGH; break;               // Cyan
        default: r = g = b = HIGH; break;                // White
      }

      if (k == 0) setColor1(r, g, b);
      else if (k == 1) setColor2(r, g, b);
      else if (k == 2) setColor3(r, g, b);

      delay(300);

    }
    if (rando[0] == rando[1] && rando[1] == rando[2]){
      lcd.clear();
      lcd.setCursor(4,0);
      lcd.print("JACKPOT!");
      lcd.setCursor(5,1);
      lcd.print("+2500");
      rem = rem + 2500;
      delay(3000);
      lcd.clear();
      lcd.setCursor(2,0);
      lcd.print("PUSH BUTTON");
      lcd.setCursor(6,1);
      lcd.print(rem);
    }
    else if (rando[0] == rando[1] || rando[1] == rando[2] || rando[0] == rando[2]){
      lcd.clear();
      lcd.setCursor(6,0);
      lcd.print("SAFE");
      lcd.setCursor(6,1);
      lcd.print("+500");
      rem = rem + 500;
      delay(3000);
      lcd.clear();
      lcd.setCursor(2,0);
      lcd.print("PUSH BUTTON");
      lcd.setCursor(6,1);
      lcd.print(rem);
    }
    else {
      lcd.clear();
      lcd.setCursor(6,0);
      lcd.print("BUST");
      lcd.setCursor(6,1);
      lcd.print("-500");
      rem = rem - 500;
      delay(3000);
      if (rem == 0){
        lcd.clear();
        lcd.setCursor(6,0);
        lcd.print("GAME");
        lcd.setCursor(6,1);
        lcd.print("OVER");
      }
      else{
        lcd.clear();
        lcd.setCursor(2,0);
        lcd.print("PUSH BUTTON");
        lcd.setCursor(6,1);
        lcd.print(rem);
      }
    }
  }
}
