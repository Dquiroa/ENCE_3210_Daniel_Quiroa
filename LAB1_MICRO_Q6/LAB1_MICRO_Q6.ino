// Optimized C program for LED sequence control with reduced memory usage
#include <Arduino.h>

// Pin definitions for LEDs and button
#define RED_LED_PIN 7
#define GREEN_LED_PIN 8
#define BLUE_LED_PIN 9
#define BUTTON_PIN 2

// State variables
volatile bool buttonPressed = false;
bool sequenceRunning = false;

// Interrupt service routine for button press
void handleButtonPress() {
    buttonPressed = true;
}

// Function to control LEDs in the sequence
void runLEDSequence() {
    const int sequence[][3] = {
        {HIGH, LOW, LOW},  // R
        {HIGH, HIGH, LOW}, // RG
        {HIGH, HIGH, HIGH},// RGB
        {LOW, HIGH, HIGH}, // GB
        {LOW, LOW, HIGH},  // B
        {HIGH, LOW, HIGH}  // RB
    };
    const int steps = sizeof(sequence) / sizeof(sequence[0]);

    for (int i = 0; i < steps; i++) {
        digitalWrite(RED_LED_PIN, sequence[i][0]);
        digitalWrite(GREEN_LED_PIN, sequence[i][1]);
        digitalWrite(BLUE_LED_PIN, sequence[i][2]);
        delay(500);
    }

    // Turn off all LEDs
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(BLUE_LED_PIN, LOW);
}

void setup() {
    // Initialize LEDs and button pin
    pinMode(RED_LED_PIN, OUTPUT);
    pinMode(GREEN_LED_PIN, OUTPUT);
    pinMode(BLUE_LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT_PULLUP);

    // Attach interrupt to the button
    attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), handleButtonPress, FALLING);
}

void loop() {
    if (buttonPressed) {
        buttonPressed = false;
        sequenceRunning = !sequenceRunning;
    }

    if (sequenceRunning) {
        runLEDSequence();
    } else {
        // Ensure LEDs are off when sequence is not running
        digitalWrite(RED_LED_PIN, LOW);
        digitalWrite(GREEN_LED_PIN, LOW);
        digitalWrite(BLUE_LED_PIN, LOW);
    }
}