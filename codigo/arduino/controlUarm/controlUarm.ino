// V 0.5
// Calibrado de las posiciones de los servos
// Basado en http://learn.robotgeek.com/demo-code/120-arduino-linear-actuator-tutorial-incremental-joystick-for-small-linear-actuator.html

#include <Servo.h>
#include "controlServo.h"

#define nDOF 5
#define tokenHip "H"
#define tokenSoulder "L"
#define tokenElbow "R"
#define tokenWristR "R"
#define tokenGrip "G"

// Vamos a crear una estructura para almacenar una posicion completa
struct position
{
  char name[4];
  int pos[nDOF];
};



controlServo csHip(12,A2,tokenHip);
controlServo csSoulder(11,A0,tokenSoulder);
controlServo csElbow(10,A1,tokenElbow);
controlServo csWristR(8,A4,tokenWristR);
controlServo csGrip(7,A5,tokenGrip);
controlServo servos[]={csHip,csSoulder,csElbow,csWristR,csGrip};

void setup() 
{ 
  Serial.begin(19200);

  for(int i=0;i<nDOF;i++)
  {    servos[i].inicializa();  }

//  csSoulder.setSigno(-1);
//  csElbow.setSigno(-1);  
} 

String strStatusOld="";
void loop() 
{ 
  
  String strStatus="";
  for(int i=0;i<nDOF;i++)
  {  strStatus+=servos[i].checkControlSetServo(); }
  if(strStatus!=strStatusOld)
  {
    Serial.println(strStatus);
    strStatusOld=strStatus;
  }

  getCommands();
} 

String getStatus()
{
  String strStatus="";
  for(int i=0;i<nDOF;i++)
    strStatus+=servos[i].getStatus();
  return strStatus;
}

String inputString = ""; // a string to hold incoming data
boolean stringComplete = false; // whether the string is complete

void getCommands() 
{
  if (Serial.available()) 
  {
    while (Serial.available()) 
    {
      char inChar = (char)Serial.read();
      inputString += inChar;
      Serial.println(inputString);
      if (inChar == '\n') 
      {
        stringComplete = true;
        Serial.println(inputString);
        break;
      }
    }
  }

  //commands
  if (stringComplete) 
  { if(inputString.startsWith(tokenHip))
    { int val = inputString.substring(1).toInt();
      csHip.setPosicion(val);     } 
    else if(inputString.startsWith(tokenSoulder))
    { int val = inputString.substring(1).toInt();
      csSoulder.setPosicion(val);    } 
    else if(inputString.startsWith(tokenElbow))
    { int val = inputString.substring(1).toInt();
      csElbow.setPosicion(val);    } 
    else if(inputString.startsWith(tokenWristR))
    { int val = inputString.substring(1).toInt();
      csWristR.setPosicion(val);    } 
    else if(inputString.startsWith(tokenGrip))
    { int val = inputString.substring(1).toInt();
      csGrip.setPosicion(val);   } 
    Serial.println(getStatus());
    inputString = "";
    stringComplete = false;
  }
}

