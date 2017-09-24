
#include <ESP8266WiFi.h>
//ur wifi and pswd
const char* ssid = "xxxx";
const char* password = "xxxx";

// Create an instance of the server
// specify the port to listen on as an argument
WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  delay(10);


  pinMode(16, OUTPUT);
  digitalWrite(16, LOW);
  
  pinMode(5, OUTPUT);
  digitalWrite(5,LOW);
 
  pinMode(4, OUTPUT);
  digitalWrite(4, LOW);
  
  pinMode(0, OUTPUT);
  digitalWrite(0, LOW);
  
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  
  // Start the server
  server.begin();
  Serial.println("Server started");

  // Print the IP address
  Serial.println(WiFi.localIP());
}

void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
  
  // Read the first line of the request
  String req = client.readStringUntil('\r');
  Serial.println(req);
  client.flush();
  
  // Match the request
 
  if (req.indexOf("/gpio16/1") != -1)
    {
      digitalWrite(16,HIGH);
      }
  else if (req.indexOf("/gpio16/0") != -1)
    
    {
      digitalWrite(16,LOW);
    }
     else if (req.indexOf("/gpio5/1") != -1)
    
    {
      digitalWrite(5,HIGH);
    }
     
else if (req.indexOf("/gpio5/0") != -1)
    
    {
      digitalWrite(5,LOW);
    }
    else if (req.indexOf("/gpio4/1") != -1)
    
    {
      digitalWrite(4,HIGH);
    }
    else if (req.indexOf("/gpio4/0") != -1)
    
    {
      digitalWrite(4,LOW);
    }
     else if (req.indexOf("/gpio0/1") != -1)
    
    {
      digitalWrite(0,HIGH);
    }
    else if (req.indexOf("/gpio0/0") != -1)
    
    {
      digitalWrite(0,LOW);
    }
    
 
  else {
    Serial.println("invalid request");
    client.stop();
    return;
  }

  // Set GPIO according to the request
 
  
  client.flush();

 
  delay(10);
 
}

