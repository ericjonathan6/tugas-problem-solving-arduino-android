char command;
String string;
boolean ledon = false;
#define led 8

  void setup()
  {
    Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);
  }

  void loop()
  {
    if (Serial.available() > 0) 
    {string = "";}
    
    while(Serial.available() > 0)
    {
      command = ((byte)Serial.read());
      
      if(command == ':')
      {
        break;
      }
      
      else
      {
        string += command;
      }
      
      delay(1);
    }
    
    if(string == "1")
    {
        ledOn();
        ledon = true;
         Serial.println(string);
    }
    
    if(string =="0")
    {
        ledOff();
        ledon = false;
        Serial.println(string);
    }
    
    if ((string.toInt()>=0)&&(string.toInt()<=255))
    {
      if (ledon==true)
      {
        analogWrite(LED_BUILTIN, 255);
        delay(string.toInt()*1000);
        analogWrite(LED_BUILTIN, 0);
        delay(string.toInt()*1000);
        Serial.println(string);
      }
    }
 }
 
void ledOn()
   {
      analogWrite(LED_BUILTIN, 255);
    }
 
 void ledOff()
 {
      analogWrite(LED_BUILTIN, 0);
 }
 

    
