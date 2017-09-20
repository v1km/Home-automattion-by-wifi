#include <SoftwareSerial.h>

//i find that putting them here makes it easier to 
//edit it when trying out new things
char c = "";
#define RX_PIN 0
#define TX_PIN 1
#define ESP_BRATE 115200

SoftwareSerial esp8266(RX_PIN, TX_PIN);

void setup()
{
  Serial.begin(9600);
  esp8266.begin(ESP_BRATE); // I changed this
}

void loop()
{
 esp8266.println("AT\r\n"); //the newline and CR added
 delay(10);  //arbitrary value

 if(esp8266.available()) // check if the esp is sending a message 
 {
 while(esp8266.available())
  {
    // The esp has data so display its output to the serial window 
    char c = esp8266.read(); // read the next character.
    Serial.write(c);
  }  
 }
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
