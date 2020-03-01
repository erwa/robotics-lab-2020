#include <Romi32U4.h>

Romi32U4Motors motors;
Romi32U4ButtonA buttonA;
#define CONFAC (50.0/13.0)
#define DIA (14.75)


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void goCentiPerSec(float vLeft, float vRight) {
  motors.setSpeeds(-vLeft*CONFAC, vRight*CONFAC);
}

void goCenti(float Dist, float Vel) {
  float t = Dist/Vel*1000;
  int st = millis();
  while (millis()-st < t) {
    Serial.println(millis()-st);
   goCentiPerSec(Vel, Vel);
    

  }
  goCentiPerSec(0, 0);
}

void goCentiPerSecRight(float vRight) {
  motors.setRightSpeed(vRight*CONFAC);
}

void goCentiPerSecLeft(float vLeft) {
  motors.setLeftSpeed(-vLeft*CONFAC);
}

void goCentiRight(float Dist, float Vel) {
  float t = Dist/Vel*1000;
  int st = millis();
  while (millis()-st < t) {
    goCentiPerSecRight(Vel);
  }
    
}

void itTurneth(float Angle, float Speed) {
  float d = 1.0/2.0*Angle/180*3.14159*DIA;
  int st = millis();
  float t = d/Speed*1000;
  Serial.println(d);
  while (millis()-st < t) {
    goCentiPerSecRight(Speed);
    goCentiPerSecLeft(-Speed);
  }
  goCentiPerSec(0, 0);
}


void loop() {
  // put your main code here, to run repeatedly:
  buttonA.waitForButton();
  delay(1000);
// Test 1: 26 cm at 100 speed for 1 sec


//itTurneth(angle,speed); turning
//GoCenti(distance, speed); going forward
  goCenti(30, 50);
  delay(1000);
  itTurneth(90, 50);
 
}
