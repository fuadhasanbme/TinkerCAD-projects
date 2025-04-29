/*
Code Written By-
Fuad Hasan
BME, KUET
*/

/*
This program blinks pin 13 of the arduino (the built-in LED)
*/

int buttonState = 0;
const int buttonPin = 2;
int ledOne = 13;
int ledTwo = 12;
int ledThree = 8;

void setup()
{
  pinMode(ledOne, OUTPUT);
  pinMode(ledTwo, OUTPUT);
  pinMode(ledThree, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  buttonState = digitalRead(buttonPin);
  if(buttonState==1)
  {
    digitalWrite(ledOne, 1);
    Serial.print("STOP\n");
    delay(2000);
    digitalWrite(ledOne, 0);
    delay(500);
    digitalWrite(ledTwo, 1);
    Serial.print("GET READY\n");
    delay(2000);
    digitalWrite(ledTwo, 0);
    delay(500);
    digitalWrite(ledThree, 1);
    Serial.print("BYE\n");
    delay(2000);
    digitalWrite(ledThree, 0);
    delay(500);
  }
}