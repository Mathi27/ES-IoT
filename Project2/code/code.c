int red= 13;
int green = 12;
int blue = 11;

void setup() {
  // put your setup code here, to run once:
pinMode(red, OUTPUT);
pinMode(green, OUTPUT);
pinMode(blue, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(red, HIGH);
digitalWrite(green, LOW);
digitalWrite(blue, LOW);
delay(1500);

digitalWrite(red, LOW);
digitalWrite(green, HIGH);
digitalWrite(blue, LOW);
delay(1500);

digitalWrite(red, LOW);
digitalWrite(green, LOW);
digitalWrite(blue, HIGH);
delay(1500);

}
