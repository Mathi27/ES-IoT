#include <Servo.h>

Servo myServo;
int vert = A0;
int horz = A1;
int servo = 9;



void setup() {
  // put your setup code here, to run once:
  myServo.attach(servo);
  pinMode(vert, INPUT);
  pinMode(horz, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int vertvalue = analogRead(vert);
  int anglex = map(vertvalue, 0,1023,0,180);
  int horzvalue = analogRead(horz);
  int angley = map(horzvalue, 0,1023,0,180);
  if (angley>90)
  {
    if (anglex<90)
    {
      myServo.write(anglex+(angley/4));
    }
    else if (anglex>90)
    {
      myServo.write(anglex-(angley/4));
    }
    else
    {
      myServo.write(anglex);
    }
  }
  else 
  {
    myServo.write(anglex);
  }
  delay(15);
}
