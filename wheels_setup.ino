#include <Servo.h> //include servo library

//define wheel pins
#define leftPWM 6
#define leftIN1 7
#define leftIN2 8
#define rightPWM 9
#define rightIN1 10
#define rightIN2 11

void setup() {
  //define wheel pins as output
  pinMode(leftPWM, OUTPUT);
  pinMode(leftIN1, OUTPUT);
  pinMode(leftIN2, OUTPUT);
  pinMode(rightPWM, OUTPUT);
  pinMode(rightIN1, OUTPUT);
  pinMode(rightIN2, OUTPUT);

  //define trig as output and echo as input
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  Serial.println("kör framåt");
  
  delay(5000);
  digitalWrite(leftIN1, HIGH);
  digitalWrite(leftIN2, LOW);
  analogWrite(leftPWM, 200);

  digitalWrite(rightIN1, LOW);
  digitalWrite(rightIN2, HIGH);
  analogWrite(rightPWM, 200);
  
  delay(5000);
}
