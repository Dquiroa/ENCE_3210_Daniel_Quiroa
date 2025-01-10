#include <stdio.h>
#include <string.h>

// Simulated pins for LEDs
#define RED_LED_PIN 2
#define GREEN_LED_PIN 3
#define BLUE_LED_PIN 4

// Simulated array of characters
char letters[] = "RGBRGRBBRGGGBBR";

// Counters for occurrences
int redCount = 0, greenCount = 0, blueCount = 0;

// Functions to control LEDs (simulate turning on/off LEDs)
void turnOnLED(int pin) {
    printf("LED on PIN %d is ON\n", pin);
}

void turnOffLED(int pin) {
    printf("LED on PIN %d is OFF\n", pin);
}

// Function to process the array and control LEDs
void processArray(char *arr, int size) {
    // Iterate through the array
    for (int i = 0; i < size; i++) {
        char current = arr[i];

        switch (current) {
            case 'R': // Red letter detected
                redCount++;
                turnOnLED(RED_LED_PIN);
                break;
            case 'G': // Green letter detected
                greenCount++;
                turnOnLED(GREEN_LED_PIN);
                break;
            case 'B': // Blue letter detected
                blueCount++;
                turnOnLED(BLUE_LED_PIN);
                break;
            default:
                // If other characters, turn off LEDs
                turnOffLED(RED_LED_PIN);
                turnOffLED(GREEN_LED_PIN);
                turnOffLED(BLUE_LED_PIN);
                break;
        }
    }
}

// Main function
int main() {
    int size = strlen(letters); // Calculate size of the array

    printf("Processing array: %s\n", letters);
    processArray(letters, size);

    // Display counts
    printf("\nOccurrences:\n");
    printf("Red (R): %d\n", redCount);
    printf("Green (G): %d\n", greenCount);
    printf("Blue (B): %d\n", blueCount);

    return 0;
}