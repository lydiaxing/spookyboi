#include <AFMotor.h>
char state = 'g';

AF_DCMotor m1(1);

void setup() {
  m1.setSpeed(255);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.begin(9600); // Default communication rate of the Bluetooth module
}

void loop() {
  if(Serial.available() > 0){ // Checks whether data is comming from the serial port
    state = char(Serial.read()); // Reads the data from the serial port
    Serial.println(state);
 }

 if (state == 'g') {
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("shooting");
  m1.run(FORWARD);
 }
 else if (state == 'l') {
  //todo move turret left
 } 
 else if (state == 'r') {
  //todo move turret right
 } 
 else if (state == 'u') {
  //todo move turret up
 } 
 else if (state == 'd') {
  //todo move turret down
 } 
 else if (state == 'x') {
  //todo move left
 } 
 else if (state == 'y') {
  //todo move right
 } 
 else if (state == 'f') {
  //todo move forward
 } 
 else if (state == 'b') {
  //todo move back
 } else {
  digitalWrite(LED_BUILTIN, LOW); //turn led off
 }
}
