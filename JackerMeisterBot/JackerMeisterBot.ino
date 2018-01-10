#include <CNY.h>

#include <Sharp.h>

#include <NewPing.h>

#include <Motor.h>


Sharp paredIzq(A4);
Sharp paredDcha(A3);
CNY CNYTrasero(A5);
NewPing paredFront(8, 8, 200);
Motor MotorIzq(10, 9, 255);
Motor MotorDcho(6, 5, 255);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
    if(paredDcha.getDistance() > 20){
      turnRight();
      goAhead();
    }
    else if(paredFront.ping_cm() > 15){
      goAhead();
    }
    else if(paredIzq.getDistance() > 20){
      turnLeft();
      goAhead();
    }
}

void goAhead(){
  MotorIzq.moveForward();
  MotorDcho.moveForward();
}

void turnRight(){
  MotorIzq.moveForward();
  MotorDcho.moveBackward();

  delay(700);

  MotorIzq.stopMotor();
  MotorDcho.stopMotor();

  delay(1000);
}


void turnLeft(){
  MotorIzq.moveBackward();
  MotorDcho.moveForward();

  delay(1000);

  MotorIzq.stopMotor();
  MotorDcho.stopMotor();

  delay(250);
}
