#include <Servo.h>
Servo lilservo; // Define our Servo

void setup()
{
  Serial.begin (9600);
  lilservo.attach(3); // servo on digital pin 3
}

void loop()
{
  lilservo.write(0);
  Serial.println("Let's get this party started");
  lilservo.write(90);  // Turn Servo Left to 45 degrees
  delay(1000);          // Wait 1 second
  lilservo.write(0);   // Turn Servo Left to 0 degrees
  delay(1000);          // Wait 1 second
  lilservo.write(180);  // Turn Servo back to center position (90 degrees)
  delay(1000);          // Wait 1 second
}
