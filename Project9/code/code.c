#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Keypad.h>

#define OLED_RESET -1 
#define SCREEN_ADDRESS 0x3C
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const byte ROW = 4;
const byte COL = 4;
bool win = false;
int xo = 0;
char let;

char keys[ROW][COL] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROW] = {13, 12, 11, 10};
byte colPins[COL] = {9, 8, 7, 6};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROW, COL);

char check[3][3];

void setup() {
  Serial.begin(9600);

  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("failed to start SSD1306 OLED"));
    while (1);
  }

  delay(100);
  oled.clearDisplay();
  oled.setTextSize(2);       
  oled.setTextColor(WHITE);
  oled.setCursor(35,20);
  oled.println("Start");
  oled.display();

  delay(2000);         
  oled.clearDisplay(); 

  oled.setTextSize(2);       
  oled.setTextColor(WHITE);   
  oled.setCursor(8,5);      
  oled.println("_________"); 
  oled.setCursor(8,29);       
  oled.println("_________"); 

  for (int y = 0; y <= 60; y += 10) {
    oled.setCursor(38, y); oled.println("|");
    oled.setCursor(74, y); oled.println("|");
  }

  oled.setCursor(18, 0);       
  oled.print(1);
  oled.setCursor(55, 0);       
  oled.print(2);
  oled.setCursor(92, 0);       
  oled.print(3);
  oled.setCursor(18, 23);       
  oled.print(4);
  oled.setCursor(55, 23);       
  oled.print(5);
  oled.setCursor(92, 23);       
  oled.print(6);
  oled.setCursor(18, 46);       
  oled.print(7);
  oled.setCursor(55, 46);       
  oled.print(8);
  oled.setCursor(92, 46);       
  oled.print(9);

  oled.display();  

  delay(3000);         
  oled.clearDisplay(); 

  oled.setTextSize(2);       
  oled.setTextColor(WHITE);   
  oled.setCursor(8,5);      
  oled.println("_________"); 
  oled.setCursor(8,29);       
  oled.println("_________"); 

  for (int y = 0; y <= 60; y += 10) {
    oled.setCursor(38, y); oled.println("|");
    oled.setCursor(74, y); oled.println("|");
  }

  oled.display();  

  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      check[i][j] = ' ';
}

void loop() {
  char key = keypad.getKey();

  if (!key) return;

  switch (key) {
    case '1':
      if (check[0][0] == ' ') {
        check[0][0] = (xo % 2 == 0) ? 'X' : 'O';
        oled.setCursor(18, 0);       
        oled.print(check[0][0]);
        xo++;
      }
      break;
    case '2':
      if (check[0][1] == ' ') {
        check[0][1] = (xo % 2 == 0) ? 'X' : 'O';
        oled.setCursor(55, 0);       
        oled.print(check[0][1]);
        xo++;
      }
      break;
    case '3':
      if (check[0][2] == ' ') {
        check[0][2] = (xo % 2 == 0) ? 'X' : 'O';
        oled.setCursor(92, 0);       
        oled.print(check[0][2]);
        xo++;
      }
      break;
    case '4':
      if (check[1][0] == ' ') {
        check[1][0] = (xo % 2 == 0) ? 'X' : 'O';
        oled.setCursor(18, 23);       
        oled.print(check[1][0]);
        xo++;
      }
      break;
    case '5':
      if (check[1][1] == ' ') {
        check[1][1] = (xo % 2 == 0) ? 'X' : 'O';
        oled.setCursor(55, 23);       
        oled.print(check[1][1]);
        xo++;
      }
      break;
    case '6':
      if (check[1][2] == ' ') {
        check[1][2] = (xo % 2 == 0) ? 'X' : 'O';
        oled.setCursor(92, 23);       
        oled.print(check[1][2]);
        xo++;
      }
      break;
    case '7':
      if (check[2][0] == ' ') {
        check[2][0] = (xo % 2 == 0) ? 'X' : 'O';
        oled.setCursor(18, 46);       
        oled.print(check[2][0]);
        xo++;
      }
      break;
    case '8':
      if (check[2][1] == ' ') {
        check[2][1] = (xo % 2 == 0) ? 'X' : 'O';
        oled.setCursor(55, 46);       
        oled.print(check[2][1]);
        xo++;
      }
      break;
    case '9':
      if (check[2][2] == ' ') {
        check[2][2] = (xo % 2 == 0) ? 'X' : 'O';
        oled.setCursor(92, 46);       
        oled.print(check[2][2]);
        xo++;
      }
      break;
    default:
      break;
  }

  oled.display();

  for (int i = 0; i < 3; i++) {
    if (check[i][0] != ' ' && check[i][0] == check[i][1] && check[i][1] == check[i][2])
      win = true;
    if (check[0][i] != ' ' && check[0][i] == check[1][i] && check[1][i] == check[2][i])
      win = true;
  }
  if (check[0][0] != ' ' && check[0][0] == check[1][1] && check[1][1] == check[2][2])
    win = true;
  if (check[0][2] != ' ' && check[0][2] == check[1][1] && check[1][1] == check[2][0])
    win = true;

  if (win) {
    let=(xo%2 == 0)? 'O' : 'X';
    delay (250);
    oled.clearDisplay();
    oled.setCursor(5, 10);
    oled.setTextSize(2);
    oled.println("Game Over!");
    oled.setCursor(30, 30);
    oled.println(let);
    oled.setCursor(50, 30);
    oled.println("WINS");
    oled.display();
    while (1);
  }

  if (xo == 9) {
    delay (500);
    oled.clearDisplay();
    oled.setCursor(5, 10);
    oled.setTextSize(2);
    oled.println("Game Over!");
    oled.setCursor(40, 30);
    oled.println("DRAW");
    oled.display();
    while (1);
  }
}
