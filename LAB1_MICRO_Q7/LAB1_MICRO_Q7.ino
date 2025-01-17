// Pin definitions
const int REDL = 9;
const int GREENL = 10;   
const int BLUEL = 11;     
const int button1 = 7;   
const int button2 = 8;    

// Initialize Arrays
int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};   
int arr2[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};   

int result[10]; 

int operation = 0;        
bool operationSelected = false;  

void setup() {
  // Initialize LED 
  pinMode(REDL, OUTPUT);
  pinMode(GREENL, OUTPUT);
  pinMode(BLUEL, OUTPUT);

  // Initialize button pins as input
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);

  // Shutting off LED's
  digitalWrite(REDL, LOW);
  digitalWrite(GREENL, LOW);
  digitalWrite(BLUEL, LOW);

  Serial.begin(9600);
  
  // Print a welcome message for the user
  Serial.println("Press the first button to select an operation, and press button 2 to execute it: ");
}

void loop() {
  // Check if button 1 is pressed to change the operation
  if (digitalRead(button1) == LOW) {
    delay(200);  
    operation = (operation + 1) % 3;  

    operationSelected = true;  

    // fidning the selected button and lighting the LED
    if (operation == 0) {
      digitalWrite(REDL, HIGH);   
      digitalWrite(GREENL, LOW);  
      digitalWrite(BLUEL, LOW);   
      Serial.println("Addition operation selected: ");
    } else if (operation == 1) {
      digitalWrite(REDL, LOW);    
      digitalWrite(GREENL, HIGH); 
      digitalWrite(BLUEL, LOW);   
      Serial.println("Subtraction operation selected: ");
    } else if (operation == 2) {
      digitalWrite(REDL, LOW);    
      digitalWrite(GREENL, LOW); 
      digitalWrite(BLUEL, HIGH); 
      Serial.println("Multiplication operation selected: ");
    }
  }

  // Check if button 2 is pressed to execute the selected operation
  if (digitalRead(button2) == LOW && operationSelected) {
    delay(200);  

  
    Serial.println("Performing operation currently...: "); 

    // Perform the selected operation 
    for (int i = 0; i < 10; i++) {
      if (operation == 0) {
        result[i] = arr1[i] + arr2[i];  
      } else if (operation == 1) {
        result[i] = arr1[i] - arr2[i]; 
      } else if (operation == 2) {
        result[i] = arr1[i] * arr2[i];  
      }
    }

    // Turn off all LED
    digitalWrite(REDL, LOW);
    digitalWrite(GREENL, LOW);
    digitalWrite(BLUEL, LOW);

    // Print the results 
    Serial.println("Results: ");
    for (int i = 0; i < 10; i++) {
      Serial.print("result[");
      Serial.print(i);  
      Serial.print("] = ");
      Serial.println(result[i]);  
    }

    // Turn on all LED's
    digitalWrite(REDL, HIGH);
    digitalWrite(GREENL, HIGH);
    digitalWrite(BLUEL, HIGH);
    delay(1000);  

    // Turn off the LED's
    digitalWrite(REDL, LOW);
    digitalWrite(GREENL, LOW);
    digitalWrite(BLUEL, LOW);

    operationSelected = false; 
  }
}