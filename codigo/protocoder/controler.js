/*
*	
*	Description 6 DOF robotic arm controler
*	by javacasm
*   CC by SA
*
*/

// The main program!!
var metal = new Arm();

metal.init();
robot.say("hello everybody");
robot.fullServo1(90);
robot.led(0);

// Create the UI: 6 slider each for a DOF
// One every 100 y pixel
// TODO: Create dinamically: only change the position and the articulation ¿maybe an array of Articulations?

// wrist Pitch 
var sldWP = ui.addSlider(20, 20, ui.sw - 20, -1, 180, 1,
function(progress){
 var iP = Math.round(progress);
 robot.wristP(iP);
});

// wrist Roll
var sldWR = ui.addSlider(20, 120, ui.sw - 20, -1, 180, 1,
function(progress){
 var iP = Math.round(progress);
 robot.wristR(iP);
});

// Hip 
var sldH = ui.addSlider(20, 20, ui.sw - 20, -1, 180, 1,
function(progress){
 var iP = Math.round(progress);
 robot.wristP(iP);
});
var slider3 = ui.addSlider(20, 220, ui.sw - 20, -1, 180, 1,
function(progress){
 var iP = Math.round(progress);
 robot.microServo1(iP);
});
var slider4 = ui.addSlider(20, 320, ui.sw - 20, -1, 180, 1,
function(progress){
 var iP = Math.round(progress);
 robot.microServo2(iP);
});
ui.setBackgroundImage("robot.png");



// Articulation Class, hold de value an send to arduino each command
function Arti(token,min,max,ini){
  this.idToken='q';     
  this.minPosition=min;
  this.maxPosition=max;
  this.initialPosition=ini;
  
  this.init=function()   
  {
      this.servo(this.initialPosition); 
  }
  
  // Send the comand to the arduino
  this.servo=function(position)   
  {
    if(position>this.minPosition && position<this.maxPosition)
        network.sendBluetoothSerial(this.idToken+position + "\n"
    )
  }
}


function Arm() {
 
 var hip=new Arti("h",150,3200,1000);
 var elbow=new Arti("e",150,3200,1000);
 var wristx=new Arti("x",150,3200,1000);
 var wristy=new Arti("y",150,3200,1000);
 var shoulder=new Arti("s",150,3200,1000);
 var grip=new Arti("g",150,3200,1000)
 
 
 this.start = function() {
 network.connectBluetoothSerialByUi(function(m, data) {
 console.log(data);
 });
 };


this.init = function()
{
    hip.init();
    
};
 this.scan = function() {
 network.scanBluetoothNetworks(function(n, m, s) {
 console.log("hola", n, m, s);
 });
 };
 
 
 this.playSound = function(name) {
 media.playSound(name);
 };

 this.say = function(text) {
 media.textToSpeech(text);
 };

 this.showImage = function(name) {
 ui.setBackgroundImage(name);
 };

 this.stop = function() {

 };

}