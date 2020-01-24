// Robo India Tutorial 
// Digital Output on LED 
// Hardware: NodeMCU Blynk Board


#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "DHT.h"           // including the library of DHT11 temperature and humidity sensor
#include <SimpleTimer.h>   //including the library of SimpleTimer
#define DHTTYPE DHT11      // DHT 11

#define dht_dpin 14
DHT dht(dht_dpin, DHTTYPE); 
SimpleTimer timer;
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "GgOgwGdj5MIWVFaCnBNHlSCbXoE";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "papindarhome";
char pass[] = "@@@@@@@";
float t;                                   // Declare the variables 
float h;



void setup()
{
    
    Serial.begin(9600);// Debug console
    Serial.setDebugOutput(true);
    Blynk.begin(auth, ssid, pass);
    pinMode(D3, OUTPUT);
    pinMode(D4, OUTPUT);  
    pinMode(D6, OUTPUT);
    pinMode(D7, OUTPUT);
    
    digitalWrite(D3, HIGH); 
    digitalWrite(D4, HIGH); 
        
    digitalWrite(D6, HIGH); 
    digitalWrite(D7, HIGH);
    dht.begin();
    timer.setInterval(2000, sendUptime);
}

BLYNK_CONNECTED() {
    Blynk.syncAll();
}

void sendUptime()
{
  
  float h = dht.readHumidity();
  float t = dht.readTemperature(); 
  Serial.println("Humidity and temperature\n\n");
  Serial.print("Current humidity = ");
  Serial.print(h);
  Serial.print("%  ");
  Serial.print("temperature = ");
  Serial.print(t); 
  Blynk.virtualWrite(V0, t);
  Blynk.virtualWrite(V1, h);
  
}

void loop()
{
  Blynk.run();
  timer.run();
}
