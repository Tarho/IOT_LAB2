int trigPin = 13;
int echoPin = 12;
int leds[] = {3, 4, 5, 6, 7};

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  for(int i = 0; i < 5; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void allLedOff() {
  for(int i = 0; i < 5; i++) {
    digitalWrite(leds[i], LOW);
  }
}

void allLedOn() {
  for(int i = 0; i < 5; i++) {
    digitalWrite(leds[i], HIGH);
  }
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;

  if(distance <= 0 || distance >= 200) {
    allLedOn(); // Turn on all LEDs
  } else {
    int n = map(distance, 0, 20, 5, 0);

    allLedOff();
    if(n >= 5) n = 5;
    if(n < 0) n = 0;

    for(int i = 0; i < n; i++) {
      digitalWrite(leds[i], HIGH);
    }
  }

  // Display distance
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  delay(50);
}