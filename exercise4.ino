#include "DHT.h"

#define DHTPIN 2
#define led1 7 //Red
#define led2 6 //Yellow
#define led3 5 //Green

#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  dht.begin();
}

void loop() {
  delay(2000);

  float t = dht.readHumidity();
  float h = dht.readTemperature();
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  float hif = dht.computeHeatIndex(f, h);
  float hic = dht.computeHeatIndex(t, h, false);

  if(t >= 60 && t <= 63) {
    delay(100);
    digitalWrite(led1, HIGH);
  } else if(t >= 64 && t <= 66) {
    delay(100);
    digitalWrite(led2, HIGH);
  } else if(t >= 68 && t <= 70) {
    delay(100);
    digitalWrite(led3, HIGH);
  }
  else
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }

  Serial.print(F("Humidity: "));
  Serial.print(t);
  Serial.print(F("%  Temperature: "));
  Serial.print(h);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));
}