/*Code written by-
Fuad Hasan
BME, KUET */


/*Interface temperature sensor and Arduino*/


// Code Written by-
// Fuad Hasan
// BME, KUET

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int degree;
double realdegree;

void setup() {
  lcd.begin(16, 2);
  degree = 0;
  realdegree = 0.0;
  lcd.print("Today's Temp:");
}

void loop() {
  degree = analogRead(A0); // Use A0 clearly
  
  realdegree = (double)degree / 1024.0; // Always better to write 1024.0 for accuracy
  realdegree *= 5.0;  // scaling to voltage (0-5V)
  realdegree -= 0.5;  // sensor adjustment if needed
  realdegree += 100.0; // sensor-specific calibration
  
  
  lcd.setCursor(0, 1); // Move to second line
  realdegree = (9.0 / 5.0) * realdegree + 32.0; // Convert Celsius to Fahrenheit
  String output = String(realdegree) + String((char)178) + "F"; // (char)178 is the degree symbol
  lcd.print(output);

  delay(500); // Add small delay so it’s readable
}
