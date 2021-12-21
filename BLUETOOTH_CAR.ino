
#include <AFMotor.h>

#define MOTOR12_8KHZ 1
#define MOTOR34_1KHZ 1

AF_DCMotor motor1(1, MOTOR12_8KHZ); 
AF_DCMotor motor2(2, MOTOR12_8KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

char command; 
const int RUN_SPEED = 255;
const int STOP_SPEED = 0;

//*****************************************************************************************************

void forward();
void back();
void left();
void right();
void Stop();

//*****************************************************************************************************

void setup() 
{       
  Serial.begin(9600);  //Set the baud rate to your Bluetooth module.
}

//*****************************************************************************************************

void loop(){
  if(Serial.available() > 0){ 
    command = Serial.read(); 
    Stop(); //initialize with motors stoped
    switch(command){
    case 'F':  
      forward();
      break;
    case 'B':  
       back();
      break;
    case 'L':  
      left();
      break;
    case 'R':
      right();
      break;
    }
  } 
}

//*****************************************************************************************************

void forward()
{
  motor1.setSpeed(RUN_SPEED);
  motor1.run(FORWARD); 

  motor2.setSpeed(RUN_SPEED);
  motor2.run(BACKWARD); 

  motor3.setSpeed(RUN_SPEED);
  motor3.run(FORWARD); 

  motor4.setSpeed(RUN_SPEED);
  motor4.run(BACKWARD); 
}

//*****************************************************************************************************

void back()
{
  motor1.setSpeed(RUN_SPEED);
  motor1.run(BACKWARD); 

  motor2.setSpeed(RUN_SPEED);
  motor2.run(FORWARD); 

  motor3.setSpeed(RUN_SPEED);
  motor3.run(BACKWARD); 

  motor4.setSpeed(RUN_SPEED);
  motor4.run(FORWARD); 
 
}

//*****************************************************************************************************

void left()
{
   motor1.setSpeed(RUN_SPEED);
  motor1.run(BACKWARD); 

  motor2.setSpeed(RUN_SPEED);
  motor2.run(FORWARD); 

  motor3.setSpeed(RUN_SPEED);
  motor3.run(FORWARD); 

  motor4.setSpeed(RUN_SPEED);
  motor4.run(BACKWARD); 
}

//*****************************************************************************************************

void right()
{
   motor1.setSpeed(RUN_SPEED);
  motor1.run(FORWARD); 

  motor2.setSpeed(RUN_SPEED);
  motor2.run(BACKWARD); 

  motor3.setSpeed(RUN_SPEED);
  motor3.run(FORWARD); 

  motor4.setSpeed(RUN_SPEED);
  motor4.run(BACKWARD); 
} 

//*****************************************************************************************************

void Stop()
{
  motor1.setSpeed(STOP_SPEED); 
  motor1.run(RELEASE); 
  motor2.setSpeed(STOP_SPEED); 
  motor2.run(RELEASE); 
  motor3.setSpeed(STOP_SPEED); 
  motor3.run(RELEASE); 
  motor4.setSpeed(STOP_SPEED); 
  motor4.run(RELEASE); 
}
