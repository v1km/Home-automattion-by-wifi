int incoming = 0;

void setup() {
  
Serial.begin(115200);
// enter the commands from readme file  

}

void loop() {


incoming = Serial.read();
      
    
    if(incoming == '1')            
      {
        digitalWrite(8, LOW); 
      }
    else if(incoming == '2')  
    {     
      digitalWrite(8, HIGH);   
  }
  else  if(incoming == '3')            
      {
        digitalWrite(9, LOW);
      }
    else if(incoming == '4')  
    {     
      digitalWrite(9, HIGH);   
  }
    else if(incoming == '5')            
      {
        digitalWrite(10, LOW); 
      }
    else if(incoming == '6')  
    {     
      digitalWrite(10, HIGH);   
  }
    else if(incoming == '7')            
      {
        digitalWrite(11,LOW); 
      }
    else if (incoming == '8')  
    {     
      digitalWrite(11, HIGH);   
  }
  // statement of else are experimental 
else
{
  return;
  }
}
