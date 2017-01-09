#define leftPWM 6
#define leftIN1 7
#define leftIN2 8

#define rightPWM 9
#define rightIN1 10
#define rightIN2 11


void setup() {
  pinMode(leftPWM, OUTPUT);
  pinMode(leftIN1, OUTPUT);
  pinMode(leftIN2, OUTPUT);

  pinMode(rightPWM, OUTPUT);
  pinMode(rightIN1, OUTPUT);
  pinMode(rightIN2, OUTPUT);
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
  Serial.println("hello world");
  
  delay(5000);
}
