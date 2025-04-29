/*Code Written by-
Fuad Hasan
BME, KUET
*/

//Ultrasonic Sensor

//Variable and pins declared and initialised.
int trigPin = 10; //TRIG connected to pin 10 of Arduino
int echoPin = 9; // ECHO connected to pin 9 of Arduino
long time;
int distance;

void setup()
  //this loop repeats only once
{
  pinMode(10, OUTPUT); //TRIG pin set as output
  pinMode(9, INPUT); //ECHO pin set as input
  Serial.begin(9600); //begin communication
}

void loop()
  //this loop repeats continuoously
{
  digitalWrite(10, LOW); //TRIG pin set low(cleared)
  delayMicroseconds(2); //delay of 2 microseconds given
  
  digitalWrite(10, HIGH); //TRIG pin set high (signal transmitted)
  delayMicroseconds(10); //delay of 10 microseconds given
  digitalWrite(10, LOW); //TRIG pin set as low again
  
  //calculateing the distance:
  time = pulseIn(9, HIGH); //to calculate time of flight
  distance = time*0.034/2; //to calculate distance of object
  
  //printing the distance:
  Serial.print("Distance: ");
  Serial.println(distance);
}
