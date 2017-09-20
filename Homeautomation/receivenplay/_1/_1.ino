#include <SoftwareSerial.h>
 String command="";
SoftwareSerial esp8266(0,1); // make RX Arduino line is pin 2, make TX Arduino line is pin 3.
                             // This means that you need to connect the TX line from the esp to the Arduino's pin 2
                             // and the RX line from the esp to the Arduino's pin 3
void setup()
{
  Serial.begin(115200);
  esp8266.begin(115200); // your esp's baud rate might be different
}
 
void loop()
{
  if(esp8266.available()) // check if the esp is sending a message 
  {
    while(esp8266.available())
    {
      // The esp has data so display its output to the serial window 
      char c = esp8266.read(); // read the next character.
      Serial.write(c);
    }  
  }
  
 
  
  if(Serial.available())
  {
    // the following delay is required because otherwise the arduino will read the first letter of the command but not the rest
    // In other words without the delay if you use AT+RST, for example, the Arduino will read the letter A send it, then read the rest and send it
    // but we want to send everything at the same time.
    delay(1000); 
    
    
    
    while(Serial.available()) // read the command character by character
    {
        // read one character
      command+=(char)Serial.read();
    }
    esp8266.println(command); // send the read character to the esp8266
  }

if (command == "a")
{
  digitalWrite(13,HIGH);
  }
if (command == "b")
{
  digitalWrite(13,LOW);
  }
  if (command == "c")
{
  digitalWrite(12,HIGH);
  }
   if (command == "d")
{
  digitalWrite(12,LOW);
  }
   if (command == "e")
{
  digitalWrite(11,HIGH);
  }
  
 if (command == "f")
{
  digitalWrite(11,LOW);
  }

   if (command == "g")
{
  digitalWrite(10,HIGH);
  }
   if (command == "h")
{
  digitalWrite(10,LOW);
  }
  
}
