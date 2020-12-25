#include <AFMotor.h>
#include <Servo.h>
Servo myservo;
int rel = 10;
AF_DCMotor FM(1);
AF_DCMotor BM(4);
char bt = 'S';
void setup()
{
  Serial.begin(9600);
  pinMode(rel, OUTPUT);
  FM.setSpeed(255);
  BM.setSpeed(255);
  myservo.attach(9);
  myservo.write(90);
}


void loop() {

  bt = Serial.read();

  if (bt == 'F')
  {
    forward();
  }
  if (bt == 'B')
  {
    backward();
  }
  if(bt=='L')
  {
    l();
  }
  if(bt=='R')
  {
    r();
  }
}
void forward()
{
  FM.run(FORWARD);
  BM.run(FORWARD);
  delay(400);
  FM.run(RELEASE);
  BM.run(RELEASE);
}
void backward()
{
  FM.run(BACKWARD);
  BM.run(BACKWARD);
  delay(400);
  FM.run(RELEASE);
  BM.run(RELEASE);
}
void l()
{
  myservo.write(45);
  forward();
  myservo.write(90);
}
void r()
{
  
  myservo.write(135);
  forward();
  myservo.write(90);
}
