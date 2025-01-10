//find the second largest number in the array and storingn that value in a global variable 

#include <EEPROM.h> // Include EEPROM library to write to memory
#include <avr/pgmspace.h> // Include library for PROGMEM

#define ARRAY_SIZE 50 // Define the size of the array

// Store the array in Flash memory (PROGMEM) instead of SRAM
const int numbers[ARRAY_SIZE] PROGMEM = {
  12, 34, 56, 78, 90, 11, 45, 67, 89, 23,
  5, 67, 89, 100, 33, 22, 11, 66, 77, 88,
  44, 55, 10, 9, 8, 7, 6, 3, 2, 1,
  21, 31, 41, 51, 61, 71, 81, 91, 13, 25,
  37, 49, 60, 72, 84, 96, 100, 99, 98, 97
};

void setup() {
  Serial.begin(9600); // Start serial communication

  // Find and print the second maximum
  int secondMax = findSecondMax(ARRAY_SIZE);
  Serial.print("Second Maximum: ");
  Serial.println(secondMax);

  // Save the result in memory just after the array ends
  saveToMemory(ARRAY_SIZE * sizeof(int), secondMax);
}

void loop() {
  // Nothing to do in the loop
}

// Function to find the second maximum in the PROGMEM array
int findSecondMax(int size) {
  int max = INT_MIN;       // Initialize maximum to smallest possible integer
  int secondMax = INT_MIN; // Initialize second maximum to smallest possible integer

  for (int i = 0; i < size; i++) {
    int value = pgm_read_word(&numbers[i]); // Read value from PROGMEM
    if (value > max) {
      secondMax = max; // Update second maximum
      max = value;     // Update maximum
    } else if (value > secondMax && value != max) {
      secondMax = value; // Update second maximum
    }
  }

  return secondMax;
}

// Function to save a value to a memory location
void saveToMemory(int address, int value) {
  // Ensure the address is within EEPROM limits
  if (address + sizeof(value) <= EEPROM.length()) {
    for (int i = 0; i < sizeof(value); i++) {
      EEPROM.write(address + i, (value >> (i * 8)) & 0xFF); // Write byte-by-byte
    }
    Serial.println("Second maximum saved to memory.");
  } else {
    Serial.println("Error: Memory location exceeds EEPROM size.");
  }
}