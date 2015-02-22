// V 0.5
// Calibrado de las posiciones de los servos
// Basado en http://learn.robotgeek.com/demo-code/120-arduino-linear-actuator-tutorial-incremental-joystick-for-small-linear-actuator.html

#include <Servo.h>
#include "controlServo.h"


controlServo csHip(12,A0);
controlServo csSoulder(11,A1);
controlServo csElbow(10,A2);
controlServo csWristP(9,A3);
controlServo csWristR(8,A4);
controlServo csGrip(7,A5);
//controlServo servos[]={csHip,csSoulder,csElbow,csWristP,csWristR,csGrip};

void setup() 
{ 
  Serial.begin(9600);


  csHip.inicializa();
  csSoulder.inicializa();
  csElbow.inicializa();
  csWristP.inicializa();
  csHip.inicializa();
  csGrip.inicializa();
} 

void loop() 
{ 
  csHip.checkControlSetServo();
  csSoulder.checkControlSetServo();
  csGrip.checkControlSetServo();
  csElbow.checkControlSetServo();
  csWristR.checkControlSetServo();
  csWristP.checkControlSetServo();
  
//String status=csHip.getStatus()+" "+
} 
