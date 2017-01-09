#include <Servo.h> //include servo library

//define wheel pins
#define leftPWM 6
#define leftIN1 7
#define leftIN2 8
#define rightPWM 9
#define rightIN1 10
#define rightIN2 11

//define sensor pins
#define trig 13
#define echo 12

//define servo
Servo lilservo;

void setup() {
  Serial.begin (9600);

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
  long duration, distance;

  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = (duration/2) / 29.1;

 if (distance < 20) {
  Serial.println("Too close");
  Serial.print(distance);
  Serial.println(" cm");
  
  digitalWrite(leftIN1, HIGH);
  digitalWrite(leftIN2, HIGH);
  analogWrite(leftPWM, HIGH);
  digitalWrite(rightIN1, LOW);
  digitalWrite(rightIN2, LOW);
  analogWrite(rightPWM, LOW);
  
  }
  else { //all good drive forward
  Serial.println("All good!");
  Serial.print(distance);
  Serial.println(" cm");
  
  digitalWrite(leftIN1, HIGH);
  digitalWrite(leftIN2, LOW);
  analogWrite(leftPWM, 200);
  digitalWrite(rightIN1, LOW);
  digitalWrite(rightIN2, HIGH);
  analogWrite(rightPWM, 200);
  }
  
  delay(500);
}
