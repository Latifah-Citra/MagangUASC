#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_NAME "UASC3"
#define BLYNK_AUTH_TOKEN "EBXW6ZVeF3kef_pY3VL9p8HlIewWp8RY"
#define BLYNK_TEMPLATE_ID "TMPL6wlg4nSAK"
#define BLYNK_TEMPLATE_NAME "Controlling LED"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Wokwi-GUEST"; 
char pass[] = "";

BlynkTimer timer;

#define led1 16  // Merah
#define led2 4  // Kuning
#define led3 5  // Hijau
int btn1 = 0;
int btn2 = 0;
int btn3 = 0;

BLYNK_WRITE (V2)
{
  btn1 = param.asInt();
  if (btn1 == 1)
  {
    digitalWrite(led1, HIGH);
    Blynk.virtualWrite(V2, HIGH);
  }
  else
  {
    digitalWrite(led1, LOW);
    Blynk.virtualWrite(V2, LOW);
  }
}

BLYNK_WRITE (V3)
{
  btn2 = param.asInt();
  if (btn2 == 1)
  {
    digitalWrite(led2, HIGH);
    Blynk.virtualWrite(V3, HIGH);
  }
  else
  {
    digitalWrite(led2, LOW);
    Blynk.virtualWrite(V3, LOW);
  }
}

BLYNK_WRITE (V4)
{
  btn3 = param.asInt();
  if (btn3 == 1)
  {
    digitalWrite(led3, HIGH);
    Blynk.virtualWrite(V4, HIGH);
  }
  else
  {
    digitalWrite(led3, LOW);
    Blynk.virtualWrite(V4, LOW);
  }
}

void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
  timer.run();
}