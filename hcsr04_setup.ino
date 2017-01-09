#define trig 13
#define echo 12

void setup() {
  Serial.begin (9600);
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
  }
  else {
    Serial.println("All good!");
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(500);
} 
