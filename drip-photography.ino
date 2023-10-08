/* 
 * How to Make a Double Water Drip system
 * By
 * Ted Kinsman emkpph@rit.edu
 * Assistant Professor of Photographic Sciences
 * at Rochester Institute of Technology (RIT)
 * May 24, 2016  
 * This is the simplest version of code and circuit to 
 * make a double water drip. 
 * The values below are for a drip height of 44cm from bottom of 
 * valve to surface of water
 https://petapixel.com/2016/06/04/build-diy-double-water-drip-system-high-speed-photos/
 */

const int flashPin = 8;  // Set flash to pin 3 controls the opto-isolator 
const int StartButton = 7; // Set push button to pin 7 this will be an input from a switch
const int DripValve = 9;  // Set valve to pin 8 connects to a reed switch which controls the solenoid valve 
int buttonState = HIGH;

int ValveOpen = 95;  // Set a delay variable for time (milliseconds) valve is open
int ValvePause = 20; // set delay between drips (milliseconds)
int flashDelay = 290; // Set a delay for flash to be triggered: adjust this for part of collision you want to photograph
 
void setup() {
 
 pinMode(flashPin, OUTPUT);   // Set pin 3 as an output
 pinMode(StartButton, INPUT);  // Set pin 7 as an input
 pinMode(DripValve, OUTPUT);  // Set pin 8 as an output

}

void loop() {
 
   
 buttonState = digitalRead(StartButton);
 if (buttonState==LOW) {  //starts the drips if the button is pressed
 
  digitalWrite(DripValve, HIGH); // makes the valve open
  delay(ValveOpen);        //keeps valve open for ValveOpen time (milliseconds) 
  digitalWrite(DripValve, LOW);  // makes the valve close
  delay(ValvePause);       //keeps valve closed for the time between drips
  digitalWrite(DripValve, HIGH); // makes the valve open for second drip
  delay(ValveOpen);        //keeps valve open for ValveOpen time (milliseconds)
  digitalWrite(DripValve, LOW);  // closes the valve
  
  delay(flashDelay);       //wait the flash delay time to trigger flash
  
  digitalWrite(flashPin, HIGH);  //trigger the flash
  delay(5);            //keep flash trigger pin high long enough to trigger flash
  digitalWrite(flashPin, LOW);  //turn off flash trigger

  delay(3000);     // keeps the system in a pause mode to avoid false triggers
 } else{
   digitalWrite(flashPin, LOW); //sets pins low 
   digitalWrite(DripValve, LOW); //sets pins low
  }
   
}
