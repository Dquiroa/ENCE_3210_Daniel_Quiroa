//find the cosine of integer degrees between 0 to 360. the results should be saved in a array and printed 

#include <math.h> // Include the math library for cos() and PI

#define NUM_DEGREES 361 // Total number of degrees from 0 to 360
float cosineValues[NUM_DEGREES]; // Array to store cosine values

void setup() {
  Serial.begin(9600); // Start serial communication
  while (!Serial) {
    ; // Wait for the serial connection to be established
  }

  Serial.println("Calculating Cosine Values for Degrees 0 to 360...");

  // Calculate and store cosine values in the array
  for (int degree = 0; degree < NUM_DEGREES; degree++) {
    float radians = degree * PI / 180.0; // Convert degrees to radians
    cosineValues[degree] = cos(radians); // Store cosine value in the array
  }

  // Print the stored cosine values
  printCosineArray();
}

void loop() {
  // No actions required in the loop
}

// Function to print the array of cosine values
void printCosineArray() {
  Serial.println("\nPrinting Cosine Array Values:");
  for (int degree = 0; degree < NUM_DEGREES; degree++) {
    Serial.print("Cos(");
    Serial.print(degree);
    Serial.print("°) = ");
    Serial.println(cosineValues[degree], 6); // Print with 6 decimal precision
  }
}
