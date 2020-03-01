#include <Romi32U4.h>

#include <Servo.h>             //Servo library
 
Servo servo_test;        //initialize a servo object for the connected servo  
Romi32U4Motors motors;
Romi32U4ButtonA buttonA;
                
int angle = 0;    
 
void setup() 
{ 
//  buttonA.waitForButton();
//  delay(1000);
//  motors.setSpeeds(50, -50);
//
//  buttonA.waitForButton();
//  delay(1000);
//  motors.setLeftSpeed(0);
//  motors.setRightSpeed(0);

  buttonA.waitForButton();
  delay(1000);
  // motor starts spinning as soon as attached to pin 9; A0 seems to have no problem
  servo_test.attach(A0);      // attach the signal pin of servo to a pin of arduino
  
  buttonA.waitForButton();
} 
  
void loop() 
{ 
  for(angle = 0; angle <= 180; angle += 10)    // command to move from 0 degrees to 180 degrees 
  {                                  
    servo_test.write(angle);                 //command to rotate the servo to the specified angle
    delay(15);                       
  } 
//  servo_test.write(180);
 
  delay(5000);
  
  for(angle = 180; angle >= 0; angle -= 10)     // command to move from 180 degrees to 0 degrees 
  {                                
    servo_test.write(angle);              //command to rotate the servo to the specified angle
    delay(15);                       
  } 

//  servo_test.write(0);

  delay(5000);
}
