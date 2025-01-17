#define DC_MOTOR 8
#define GREEN_LED 2
#define YELLOW_LED 3
#define RED_LED 4
#define Sensor1 A0
#define Sensor2 A1
 
int val1,val2;
float voltage1, voltage2;
 
void readSensors(){
  val1 = analogRead(Sensor1);
  val2 = analogRead(Sensor2);
 
  voltage1 = ((float)val1*5.0)/1024;
  voltage2 = ((float)val2*5.0)/1024;
}
 
void setup() {
 pinMode(DC_MOTOR,OUTPUT);
 pinMode(GREEN_LED,OUTPUT);
 pinMode(YELLOW_LED,OUTPUT);
 pinMode(RED_LED,OUTPUT);
 
 digitalWrite(RED_LED,HIGH);
digitalWrite(YELLOW_LED,LOW);
digitalWrite(GREEN_LED,LOW);
digitalWrite(DC_MOTOR,LOW);
}
 
void loop() {
readSensors();
 
if(voltage1<4.29||voltage2<4.29){
  digitalWrite(RED_LED,LOW);
  digitalWrite(YELLOW_LED,HIGH);
  delay(2000);
  digitalWrite(DC_MOTOR,HIGH);
  delay(5000);
  digitalWrite(DC_MOTOR,LOW);
  digitalWrite(YELLOW_LED,LOW);
  digitalWrite(GREEN_LED,HIGH);
while(voltage1<4.29||voltage2<4.29){
  readSensors();
}  
digitalWrite(RED_LED,HIGH);
digitalWrite(YELLOW_LED,LOW);
digitalWrite(GREEN_LED,LOW);
digitalWrite(DC_MOTOR,HIGH);
delay(5000);
digitalWrite(DC_MOTOR,LOW);
}
}
 
