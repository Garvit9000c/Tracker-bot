#include <AFMotor.h>
#include <Servo.h>
#include <string.h>
Servo myservo;
int rel = 10;
AF_DCMotor FM(1);
AF_DCMotor BM(4);
int bt = -1;
void setup()
{
  Serial.begin(9600);
  pinMode(rel, OUTPUT);
  FM.setSpeed(200);
  BM.setSpeed(200);
  myservo.attach(9);
  myservo.write(90);
}


void loop() {

  bt = Serial.read();

  if (bt == 0)
  {
    f();
  }
  if (bt == 180)
  {
    s();
  }
  else
  {
    if(bt<180 and bt>0)
    {
      myservo.write(bt);
    }
  }
}
void f()
{
  FM.run(FORWARD);
  BM.run(FORWARD);
}
void s()
{
  FM.run(RELEASE);
  BM.run(RELEASE);
}
