#include "DHT.h"

#define DHT22PIN 13
#define LEDPIN 17
#define BUZZERPIN 16

DHT dht(DHT22PIN, DHT22);

void setup() {
  Serial.begin(115200);
  pinMode(LEDPIN, OUTPUT);
  pinMode(BUZZERPIN, OUTPUT);
  dht.begin();
}

void loop() {
  delay(1000);
  float humid = dht.readHumidity();
  float temp = dht.readTemperature();
  Serial.print("Temperature: ");
  Serial.println(temp);
  Serial.print(" C");
  Serial.print("Humidity: ");
  Serial.println(humid);

  if(temp > 30 || humid > 90){
      digitalWrite(LEDPIN, HIGH);
      digitalWrite(BUZZERPIN, HIGH);
    }
  else if(temp < 25 || humid < 70){
      digitalWrite(LEDPIN, HIGH);
      digitalWrite(BUZZERPIN, HIGH);
    }
  else{
      digitalWrite(LEDPIN, LOW);
      digitalWrite(BUZZERPIN, LOW);
    }
  delay(1000);
}
