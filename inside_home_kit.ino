
  
#include <ESP8266WiFi.h>

const char* ssid     = "wifi001";
const char* password = "12345678";

const char* host = "iotproject2024.000webhostapp.com";
const char* streamId   = "....................";
const char* privateKey = "....................";
int modev=0;
#include <Adafruit_Sensor.h>

#include "DHT.h"

#define DHTPIN D2     // Digital pin connected to the DHT sensor

#define DHTTYPE DHT11   // DHT 11


DHT dht(DHTPIN, DHTTYPE);

int count1=0;
int count11=0;
String stat="";
int flg=0;
int flag=0;
int btrate=0;
int flg1=0;
int flag1=0;
int btrate1=0;

int ldr=0;
int spo=0;
int gs=0;
int gasv=0;
int delayMS=0;
float tp;
float mv;
int cel;
int sm=0;
int hum=0;
int ws=0;
int pump=10;
void setup(void)
{
 
  ESP.wdtDisable();
// Your code here
ESP.wdtEnable(WDTO_8S); 

  Serial.begin(115200);
  pinMode(D3,INPUT);
  pinMode(D8,OUTPUT);
  digitalWrite(D8,HIGH);
  
  pinMode(D7,OUTPUT);
  digitalWrite(D7,HIGH);
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
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
   
}

void loop(void)
{ 
  temperature();
  humidity();
  lightsen();
  gassen();

  if(modev==0)
  {
    if(tp>32)
    {
      digitalWrite(D8,LOW);
      }
      else
      {
      digitalWrite(D8,HIGH);
        }
     if(sm==0)
    {
      digitalWrite(D7,LOW);
      }
      else
      {
      digitalWrite(D7,HIGH);
        }
    
    }
delay(1000);
    Serial.print("connecting to ");
  Serial.println(host);
  
  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }

  String url = "GET http://iotproject2024.000webhostapp.com/home_automation/update2.php?temp="; // Getting info from my online database through my online website
  url+=tp;
  url+="&hum=";
  url+=hum;
  url+="&ldr=";
  url+=ldr;
  url+="&gas=";
  url+=gs;
  url+=" HTTP/1.1\r\nHost: iotproject2024.000webhostapp.com\r\n\r\n";
  url += "\r\n\r\n";
  Serial.print("Requesting URL: ");
  Serial.println(url);
  
  // This will send the request to the server
  client.print(url);
  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 5000) {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return;
    }
  }
  
  // Read all the lines of the reply from server and print them to Serial
  while(client.available()){
    char a=client.read();
    Serial.print(a);
    if(a=='*')
    {
      a=client.read();
    Serial.print(a);
    if(a=='a')
    {
      a=client.read();
      Serial.print(a);
    if(a=='1')
    {
      modev=1;
      }
      if(a=='0')
    {
      modev=0;
      }  
       a=client.read();
    Serial.print(a);
    if(a=='b')
    {
      a=client.read();
    Serial.print(a);
if(a=='1')
    {
      if(modev==1)
      digitalWrite(D8,LOW);
    }
    if(a=='0')
    {
      if(modev==1)
      digitalWrite(D8,HIGH);
    }
    
       a=client.read();
    Serial.print(a);
    if(a=='c')
    {
      a=client.read();
    Serial.print(a);
if(a=='1')
    {
      if(modev==1)
      digitalWrite(D7,LOW);
    }
    if(a=='0')
    {
      if(modev==1)
      digitalWrite(D7,HIGH);
    }
    }
    }
    }
    
      }
    //String line = client.readStringUntil('\r');
    //Serial.print(line);
   
     
    } 
}
  void temperature()
  {
     tp = dht.readTemperature(false);
 Serial.print("Temp: ");
 Serial.println(tp);
  
    }
    
  void humidity()
  {
     
   hum=dht.readHumidity();
    
 Serial.print("Hum: ");
 Serial.println(hum);
  
    
    }
    
  void lightsen()
  {
    ldr = !digitalRead(D3);
    if(ldr==1)
    {
      Serial.print("LDR: ");
      Serial.println("HIGH");
      }
      else
      {
      Serial.print("LDR: ");
      Serial.println("LOW");
        
        }
    }  
    void gassen()
  {
    gs = analogRead(A0);
    gs/=2;
      Serial.print("GAS: ");
      Serial.println(gs);
        
    }
  
