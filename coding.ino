#define BLYNK_PRINT Serial

#include "DHT.h"

#define DHTPIN D1 

#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

/* Fill-in your Template ID (only if using Blynk.Cloud) */
//#define BLYNK_TEMPLATE_ID   "YourTemplateID"


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "T1sy7inFEiWSYSNtDkl1bQ0aq3KixHMx";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "DESKTOP-HP";
char pass[] = "nafza9494";

BlynkTimer timer;

void mysensor(){
  float h = dht.readHumidity();
  
  float t = dht.readTemperature();

  Blynk.virtualWrite(V0, h);
  Blynk.virtualWrite(V1, t);
  }

void setup()
{
  // Debug console
  Serial.begin(9600);
  dht.begin();

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
  timer.setInterval(1000, mysensor);
}

void loop()
{
  Blynk.run();
  timer.run();
}
