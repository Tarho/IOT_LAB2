int PINR = 2;
int MState = LOW;

void setup() {
  pinMode(PINR, INPUT);
  Serial.begin(9600);
    Serial.println("Waiting for PIR to stabilize");
  delay(1000); 
    Serial.println("Ready to detect motion!");
}
 
void loop() {
  MState = digitalRead(PINR);
    if (MState == HIGH) {
    Serial.println("Motion detected!");
    delay(50); 
  } else {
    Serial.println("No motion detected.");
    delay(50);   }
}

