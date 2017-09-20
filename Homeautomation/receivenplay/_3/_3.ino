#include <SoftwareSerial.h>

const byte rxPin = 2;
const byte txPin = 3;

SoftwareSerial ESP8266 (rxPin, txPin);

unsigned long lastTimeMillis = 0;

void setup() {
  Serial.begin(9600);   
  ESP8266.begin(9600);
  delay(2000);
}

void printResponse() {
  while (ESP8266.available()) {
    Serial.println(ESP8266.readStringUntil('\n')); 
  }
}

void loop() {

  if (millis() - lastTimeMillis > 30000) {
    lastTimeMillis = millis();

    ESP8266.println("AT+CIPMUX=1");
    delay(1000);
    printResponse();

    ESP8266.println("AT+CIPSTART=4,\"TCP\",\"192.168.1.2",80");
    delay(1000);
    printResponse();

    String c = "";
   
  if (ESP8266.available()) {
    Serial.write(ESP8266.read());
  }
   c = ESP8266.read();
   if (c == "a")
{
  digitalWrite(13,HIGH);
  }
if (c == "b")
{
  digitalWrite(13,LOW);
  }
  if (c == "c")
{
  digitalWrite(12,HIGH);
  }
   if (c == "d")
{
  digitalWrite(12,LOW);
  }
   if (c == "e")
{
  digitalWrite(11,HIGH);
  }
  
 if (c == "f")
{
  digitalWrite(11,LOW);
  }

   if (c == "g")
{
  digitalWrite(10,HIGH);
  }
   if ( c == "h")
{
  digitalWrite(10,LOW);
  }












  }   
}
