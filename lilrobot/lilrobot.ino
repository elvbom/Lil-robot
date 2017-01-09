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

  //attach servo to pin 3
  lilservo.attach(3);
}

void loop() {
  long distance, distRight, distLeft;

  //center servo
  lilservo.write(90);
  
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  distance = (pulseIn(echo, HIGH)/2) / 29.1;

  if (distance < 20) { //too close stop
    Serial.println("Too close");
    Serial.print(distance);
    Serial.println(" cm");
    
    digitalWrite(leftIN1, HIGH);
    digitalWrite(leftIN2, HIGH);
    analogWrite(leftPWM, HIGH);
    digitalWrite(rightIN1, LOW);
    digitalWrite(rightIN2, LOW);
    analogWrite(rightPWM, LOW);
  
    Serial.println("Let's check the surroundings");
    lilservo.write(0); //look right
    distRight = (pulseIn(echo, HIGH)/2) / 29.1;
    delay(1000);
    lilservo.write(180); //look left
    distRight = (pulseIn(echo, HIGH)/2) / 29.1;
    delay(1000);
    lilservo.write(90); //center servo
    delay(1000);
    //if both distRight, distLeft < 20: reverse!
    if (distRight < 20 && distLeft < 20) {
      
      }
    //otherwise go in direction with greatest distance
    if (distRight > distLeft) {
    } else (distRight < distLeft) {
    } else {
      }
    
  } else { //all good drive forward
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
