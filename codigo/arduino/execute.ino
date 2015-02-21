#include <Servo.h>
Servo servoQ, servoW, servoE, servoR;
int led = 13;
void setup() {
 pinMode(led, OUTPUT);
 //servos
 servoQ.attach(12);
 servoW.attach(11);
 servoE.attach(10);
 servoR.attach(9);
 //reset
 servoQ.write(90);
 servoW.write(90);
 servoE.write(90);
 servoR.write(90);

 //Setup usb serial connection to computer
 Serial.begin(19200);
 delay(500);
}
void loop() {
 getCommands();
 delay(25);
}

String inputString = ""; // a string to hold incoming data
boolean stringComplete = false; // whether the string is complete
void getCommands() {
 if (Serial.available()) {
 while (Serial.available()) {
 char inChar = (char)Serial.read();
 inputString += inChar;
 if (inChar == '\n') {
 stringComplete = true;
 Serial.println(inputString);
 break;
 }
 }
 }
 //commands
 if (stringComplete) {
 if(inputString.startsWith("q")){
 int val = inputString.substring(1).toInt();
 servoQ.write(val);
 } else if(inputString.startsWith("w")){
 int val = inputString.substring(1).toInt();
 servoW.write(val);
 } else if(inputString.startsWith("e")){
 int val = inputString.substring(1).toInt();
 servoE.write(val);
 } else if(inputString.startsWith("r")){
 int val = inputString.substring(1).toInt();
 servoR.write(val);
 } else if(inputString.startsWith("l")){
 int val = inputString.substring(1).toInt();
 if (val == 0) {
 digitalWrite(led, LOW);
 } else {
 digitalWrite(led, HIGH);
 }
 }
 inputString = "";
 stringComplete = false;
 }
} 