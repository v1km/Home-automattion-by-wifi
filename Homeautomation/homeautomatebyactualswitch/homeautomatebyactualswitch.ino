#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

MDNSResponder mdns;

const char* ssid = "xxxxx";  
const char* password = "xxxxx"; 

ESP8266WebServer server(80);

String mainPage = ""; 
String feedback = "";  //enter pin mo to switch with relay
String currentPage = ""; 

int GPIO_0 = 16 ; 
int GPIO_1 = 5; 
int GPIO_2 =  4;
int GPIO_3 =  0;

void setup(void){
  mainPage += "<h1 align=\"center\">Smart Junction Box</h1><h2 align=\"center\">by vikas and ratnesh</h2><h1 align=\"center\"><p>Switch 1 <a href=\"switch1On\"><button>ON</button></a>&nbsp;<a href=\"switch1Off\"><button>OFF</button>  </a></p>";
  mainPage += "<p>Switch 2 <a href=\"switch2On\"><button>ON</button></a>&nbsp;<a href=\"switch2Off\"><button>OFF</button>  </a></p>";
  mainPage += "<p>Switch 3 <a href=\"switch3On\"><button>ON</button></a>&nbsp;<a href=\"switch3Off\"><button>OFF</button>  </a></p>";
  mainPage += "<p>Switch 4 <a href=\"switch4On\"><button>ON</button></a>&nbsp;<a href=\"switch4Off\"><button>OFF</button>  </a></p>";
  feedback = "<h3 align=\"center\">Both Switch 1 and switch 2 are OFF</h3>";
  feedback = "<h3 align=\"center\">Both Switch 2 and switch 4 are OFF</h3>";

  currentPage = mainPage+feedback;
  // preparing GPIOs
  pinMode(GPIO_0, OUTPUT);
  digitalWrite(GPIO_0, LOW);
  pinMode(GPIO_1, OUTPUT);
  digitalWrite(GPIO_1, LOW);
pinMode(GPIO_2, OUTPUT);
  digitalWrite(GPIO_2, LOW);
  pinMode(GPIO_3, OUTPUT);
  digitalWrite(GPIO_3, LOW);
  
  delay(1000);
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  
  if (mdns.begin("esp8266", WiFi.localIP())) {
    Serial.println("MDNS responder started");
  }
  
  server.on("/", [](){
    currentPage = mainPage+feedback;
    server.send(200, "text/html", currentPage);
    currentPage = "";
  });

  
  server.on("/switch1On", [](){
    feedback = "<h3 align=\"center\">Switch 1 turned ON</h3>";
    currentPage=mainPage+feedback;
    server.send(200, "text/html", currentPage);
    currentPage="";
    digitalWrite(GPIO_0, HIGH);
    delay(1000);
  });
  server.on("/switch1Off", [](){
    feedback = "<h3 align=\"center\">Switch 1 turned OFF</h3>";
    currentPage=mainPage+feedback;
    server.send(200, "text/html", currentPage);
    currentPage="";
    digitalWrite(GPIO_0, LOW);
    delay(1000); 
  });

  
  server.on("/switch2On", [](){
    feedback = "<h3 align=\"center\">Switch 2 turned ON</h3>";
    currentPage=mainPage+feedback;
    server.send(200, "text/html", currentPage);
    currentPage="";
    digitalWrite(GPIO_1, HIGH);
    delay(1000);
  });
  server.on("/switch2Off", [](){
    feedback = "<h3 align=\"center\">Switch 2 turned OFF</h3>";
    currentPage=mainPage+feedback;
    server.send(200, "text/html", currentPage);
    currentPage="";
    digitalWrite(GPIO_1, LOW);
    delay(1000); 
  });

  server.on("/switch3On", [](){
    feedback = "<h3 align=\"center\">Switch 3 turned ON</h3>";
    currentPage=mainPage+feedback;
    server.send(200, "text/html", currentPage);
    currentPage="";
    digitalWrite(GPIO_2, HIGH);
    delay(1000);
  });
  server.on("/switch3Off", [](){
    feedback = "<h3 align=\"center\">Switch 3 turned OFF</h3>";
    currentPage=mainPage+feedback;
    server.send(200, "text/html", currentPage);
    currentPage="";
    digitalWrite(GPIO_2, LOW);
    delay(1000); 
  });
  server.on("/switch4On", [](){
    feedback = "<h3 align=\"center\">Switch 4 turned ON</h3>";
    currentPage=mainPage+feedback;
    server.send(200, "text/html", currentPage);
    currentPage="";
    digitalWrite(GPIO_3, HIGH);
    delay(1000);
  });
  server.on("/switch4Off", [](){
    feedback = "<h3 align=\"center\">Switch 4 turned OFF</h3>";
    currentPage=mainPage+feedback;
    server.send(200, "text/html", currentPage);
    currentPage="";
    digitalWrite(GPIO_3, LOW);
    delay(1000); 
  });
  server.begin();
  Serial.println("Smart Junction Box is up and running");
}
 
void loop(void){
  server.handleClient();
}
