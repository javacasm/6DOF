// V 0.5
// Calibrado de las posiciones de los servos
// Basado en http://learn.robotgeek.com/demo-code/120-arduino-linear-actuator-tutorial-incremental-joystick-for-small-linear-actuator.html

#include <Servo.h>
#include "controlServo.h"

#define nDOF 6

controlServo csHip(12,A0,"H");
controlServo csSoulder(11,A1,"S");
controlServo csElbow(10,A2,"E");
controlServo csWristP(9,A3,"WP");
controlServo csWristR(8,A4,"WR");
controlServo csGrip(7,A5,"G");
controlServo servos[]={csHip,csSoulder,csElbow,csWristP,csWristR,csGrip};

void setup() 
{ 
  Serial.begin(9600);

  for(int i=0;i<nDOF;i++)
    servos[i].inicializa();
    
 /* csHip.inicializa();
  csSoulder.inicializa();
  csElbow.inicializa();
  csWristP.inicializa();
  csHip.inicializa();
  csGrip.inicializa();*/
} 

void loop() 
{ 
/*  csHip.checkControlSetServo();
  csSoulder.checkControlSetServo();
  csGrip.checkControlSetServo();
  csElbow.checkControlSetServo();
  csWristR.checkControlSetServo();
  csWristP.checkControlSetServo();*/
  String strStatus="";
  for(int i=0;i<nDOF;i++)
    strStatus+=servos[i].checkControlSetServo();

  Serial.println(strStatus);
} 
