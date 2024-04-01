int PIR_PIN = 2;
int motionState = LOW;

void setup() {
  pinMode(PIR_PIN, INPUT);
  Serial.begin(9600);
    Serial.println("Waiting for PIR to stabilize");
  delay(1000); // Wait for 1 second
    Serial.println("Ready to detect motion!");
}
 
void loop() {
  motionState = digitalRead(PIR_PIN);
    if (motionState == HIGH) {
    Serial.println("Motion detected!");
    delay(500); 
  } else {
    Serial.println("No motion detected.");
    delay(500);   }
}
