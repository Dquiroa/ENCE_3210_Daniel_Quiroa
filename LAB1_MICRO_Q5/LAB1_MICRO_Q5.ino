// Define pin numbers for the red and green LEDs
const int redLED = 9;
const int greenLED = 10;

// Character array containing the main string
char array[] = "ABCDEFGHIJK";
// Character array containing the pattern to search for
char pattern[] = "GHI";

// Variable to keep track of how many times the pattern is found
int patternCount = 0;

void setup() {
  // This function runs once when the program starts

  // Set up the LED pins as outputs
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  // Initialize the LEDs to the OFF state
  digitalWrite(redLED, LOW);
  digitalWrite(greenLED, LOW);

  // Start serial communication at 9600 baud
  Serial.begin(9600);

  // Search for the pattern in the array
  for (int i = 0; i < sizeof(array) - sizeof(pattern); i++) {
    // Compare the substring of `array` starting at index `i` with `pattern`
    if (strncmp(&array[i], pattern, sizeof(pattern) - 1) == 0) {
      patternCount++; 
    }
  }

  // Turn on the green LED if the pattern is found, otherwise turn on the red LED
  if (patternCount > 0) {
    digitalWrite(greenLED, HIGH); 
  } else {
    digitalWrite(redLED, HIGH); 
  }

  // Print the result of the pattern detection to the Serial Monitor
  Serial.println("Pattern detection result: ");
  Serial.print("Pattern found: ");
  Serial.print(patternCount);
  Serial.println(" times.");
}

void loop() {
  // This function runs repeatedly after `setup()`
  
}