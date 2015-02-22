/*
*	
*	Description 6 DOF robotic arm controler
*	by javacasm
*   CC by SA
*
*/

// The main program!!
var metal = new Arm();
metal.start();
metal.init();
metal.say("hello everybody");


// Create the UI: 6 slider each for a DOF
// One every 100 y pixel
// TODO: Create dinamically: only change the position and the articulation ¿maybe an array of Articulations?

// Hip  
var sldHip = ui.addSlider(20, 20, ui.sw - 20, -1, 180, 1,
function(progress){
 var iP = Math.round(progress);
 metal.hip(iP);
});

// Shoulder  
var sldSld = ui.addSlider(20, 120, ui.sw - 20, -1, 180, 1,
function(progress){
 var iP = Math.round(progress);
 metal.shoulder(iP);
});

// Elbow
var sldElb = ui.addSlider(20, 220, ui.sw - 20, -1, 180, 1,
function(progress){
 var iP = Math.round(progress);
 metal.elbow(iP);
});

// wrist Pitch
var sldWP = ui.addSlider(20, 320, ui.sw - 20, -1, 180, 1,
function(progress){
 var iP = Math.round(progress);
 metal.wristR(iP);
});


// wrist Roll
var sldWR = ui.addSlider(20, 420, ui.sw - 20, -1, 180, 1,
function(progress){
 var iP = Math.round(progress);
 metal.wristR(iP);
});


// Grip
var sldGrp = ui.addSlider(20, 520, ui.sw - 20, -1, 180, 1,
function(progress){
 var iP = Math.round(progress);
 metal.grip(iP);
});

//ui.setBackgroundImage("robot.png");



// Articulation Class, hold de value an send to arduino each command
function Arti(token,min,max,ini)
{
  this.idToken=token;     
  this.minPosition=min;
  this.maxPosition=max;
  this.initialPosition=ini;
  
  this.init=function()   
  {   this.servo(this.initialPosition);  };
  
  // Send the comand to the arduino
  this.servo=function(position)   // TODO: arreglar bluetooth
  {    if(position>this.minPosition && position<this.maxPosition)
             {network.sendBluetoothSerial(this.idToken+position + "\n" );}
  };
}


function Arm() {
 
 var hip=new Arti("h",150,3200,1000);
 var elbow=new Arti("e",150,3200,1000);
 var wristP=new Arti("p",150,3200,1000);
 var wristR=new Arti("r",150,3200,1000);
 var shoulder=new Arti("s",150,3200,1000);
 var grip=new Arti("g",150,3200,1000);
 
 
 this.start = function() {
 	network.connectBluetoothSerialByUi(function(m, data) 
 		{console.log(data); });
 };


 this.init = function()
 {
    hip.init();
    shoulder.init();
    elbow.init();
    wristR.init();
    wristP.init();
    grip.init();
 };

 this.scan = function() 
 {
 	network.scanBluetoothNetworks(function(n, m, s) 
 		{ 		console.log("hola", n, m, s);  	});
 };
 
 
 this.playSound = function(name) 
 {   media.playSound(name);  };

 this.say = function(text) 
 {   media.textToSpeech(text);  };

 this.showImage = function(name) 
 {  ui.setBackgroundImage(name);  };

 this.stop = function() 
 {  };

}