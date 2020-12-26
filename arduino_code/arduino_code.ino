#include <AFMotor.h>
#include <Servo.h>
Servo myservo;
AF_DCMotor FM(1);
AF_DCMotor BM(4);
char bt = 'S';
void setup()
{
  Serial.begin(9600);
  FM.setSpeed(255);
  BM.setSpeed(255);
  FM.run(RELEASE);
  BM.run(RELEASE);
  myservo.attach(9);
  myservo.write(90);
}


void loop() {

  bt = Serial.read();

  if (bt == '0')
  {
    FM.run(RELEASE);
    BM.run(RELEASE);
  }
  if (bt == '1')
  {
    FM.run(FORWARD);
    BM.run(FORWARD);
  }
  if (bt == '2')
  {
    myservo.write(30);
  }
  if (bt == '3')
  {
    myservo.write(50);
  }
  if (bt == '4')
  {
    myservo.write(70);
  }
  if (bt == '5')
  {
    myservo.write(90);
  }
  if (bt == '6')
  {
    myservo.write(110);
  }
  if (bt == '7')
  {
    myservo.write(130);
  }
  if (bt == '8')
  {
    myservo.write(150);
  }
}
 
