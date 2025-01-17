// Taskl.ino
#include <Arduino.h> 
// Function to calculate twice the square of a given number
int calculateTwice(int num) {
  //Multiplying the square by 2
  return 2 * (num * num); 
}

void setup() {
  //Initializing 
  Serial.begin(9600);
  int results[512];  

  // Loop to calculate twice the square for numbers from 0 to 511
  for (int i = 0; i <= 511; i++) { // Corrected the syntax error in the loop condition
    results[i] = calculateTwice(i); 
    Serial.print("Number: "); 
    Serial.print(i);
    Serial.print("  -> Twice the square:  ");
    Serial.println(results[i]);
  }
}
void loop(){

}