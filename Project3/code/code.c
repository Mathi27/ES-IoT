int red = 13;
int blue = 12;
int button = 11;
int buttonS = 0;

void setup() {
  // put your setup code here, to run once:
pinMode(red, OUTPUT);
pinMode(blue, OUTPUT);
pinMode(button, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
buttonS = digitalRead(button);

if (buttonS == 1)
{
  digitalWrite(red, HIGH);
  digitalWrite(blue, HIGH);
}
else if (buttonS == 0)
{
  digitalWrite(red, LOW);
  digitalWrite(blue, LOW);
}
}
