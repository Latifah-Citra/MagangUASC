#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define RESET          -1
#define HEIGHT  64
#define WIDTH   128

float duration, distance;

const int TRIGPIN = 33;
const int ECHOPIN = 32;

Adafruit_SSD1306 display(WIDTH, HEIGHT, &Wire, RESET);

void setup() {
  Serial.begin(115200);
  pinMode(TRIGPIN, OUTPUT);
  pinMode(ECHOPIN, INPUT);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)){
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); 
  }
}

void loop() {
  digitalWrite(TRIGPIN, LOW);  
	delayMicroseconds(2);  
	digitalWrite(TRIGPIN, HIGH);  
	delayMicroseconds(10);  
	digitalWrite(TRIGPIN, LOW);  
  duration = pulseIn(ECHOPIN, HIGH);
  distance = (duration*.017);  
// ====================== //
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(10, 30);
  display.print("Jarak = ");
  display.print(distance);
  display.println(" cm");
  display.display();
}
