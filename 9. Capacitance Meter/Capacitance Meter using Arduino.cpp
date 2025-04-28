//Code written by -
//Fuad Hasan
//BME, KUET


//Initialize Pins
int analogPin = 0;
int chargePin = 8;
int dischargePin = 9; //speeds up discharging process, not necessary though

//Initialize resistor
int resistorValue = 10000;

//Initialize Timer
unsigned long startTime;
unsigned long elapsedTime;

//Initialize Capacitance Variables
float microFarads;
float nanoFarads;

void setup()
{
  pinMode(chargePin, OUTPUT);
  digitalWrite(chargePin, LOW);
  Serial.begin(9600);   //Necessary to print data to serial monitor over USB

}

void loop()
{
  digitalWrite(chargePin, HIGH);    //Begins charging the capacitor
  startTime = millis();     //Begins the timer

  while(analogRead(analogPin) < 610) // 648;
  {
    //Does nothing untill capacitor reaches 63.25 of total voltage
  }

  unsigned long nowTime = millis();
  elapsedTime = nowTime - startTime;    //Determines how much time it took to charge capacitor
  microFarads = ((float)elapsedTime / resistorValue) * 1000;
  Serial.print(elapsedTime);
  Serial.print(" mS   ");

  if(microFarads >1)    //Determines if units should be micro or nano and prints accordingly
  {
    Serial.print((long)microFarads);
    Serial.println(" microFarads");    
  }

  else
  {
    nanoFarads = microFarads * 1000.0;
    Serial.print((long)nanoFarads);
    Serial.println(" nanoFarads"); 
    delay(500);
  }

  digitalWrite(chargePin, LOW);   //Stops charging capacitor
  pinMode(dischargePin,OUTPUT); 
  digitalWrite(dischargePin, LOW);    //Allows capacitor tot discharge
  while(analogRead(analogPin) > 0)
  {
    //Do nothing untill capacitor is discharged
  }

  pinMode(dischargePin, INPUT);     //Prevents capacitor from discharging
}