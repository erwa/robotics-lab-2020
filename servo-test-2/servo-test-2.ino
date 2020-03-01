#include <Romi32U4.h>
#include <Servo.h>             //Servo library

Romi32U4ButtonA buttonA;
Servo testservo;        //initialize a servo object for the connected servo  

uint32_t next;
                
int angle = 0;    
 
void setup() 
{
  buttonA.waitForButton();
  delay(1000);

  // gripper: 500: fully open, 2400: fully closed
  // need to use more than the documented 1200 to get tilt to go down
  // tilt: 900: fully down, 1900: fully up
  // lift: 700: fully up, 1900: fully down
  testservo.attach(3, 900, 1900);
  next = millis() + 500;

  // gripper: 180: closed; 0: open
  // tilt: 180: fully up, 0: fully down
  // lift: 0: fully up, 110 (@ 1900): basically fully down
  testservo.write(0); 
  
  buttonA.waitForButton();
  delay(1000);
} 
  
void loop() 
{ 
  static bool rising = true;

  while (!buttonA.isPressed()) {
    if(millis() > next)
    {
      if(rising)
      {
        testservo.write(110);
        rising = false;
      }
      else
      {
        testservo.write(0);
        rising = true;
      }
  
      // repeat again after a couple seconds.
      next += 3000;
    }
  }
  buttonA.waitForRelease();
  
  while (!buttonA.isPressed()) {
    delay(500);
  }
  buttonA.waitForRelease();
}
