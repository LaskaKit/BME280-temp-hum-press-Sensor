// upraveno pro BMP280

#include <WiFi.h>
#include <HTTPClient.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME280 bme;

unsigned long delayTime;

// vypln svou WiFi 
const char* ssid = "";
const char* password = "";

// vypln tvou domenu cidla, kterou sis zaregistroval na tmep.cz
String serverName = "http://xyz.tmep.cz/index.php?";
 
void setup() {
    Wire.begin (21, 22); // ESP32-LPkit
    Serial.begin(115200);
    while(!Serial);
    Serial.println(F("BME280 test"));

    unsigned status;
    
    // default settings
    status = bme.begin();  
    // You can also pass in a Wire library object like &Wire2
    // status = bme.begin(0x76, &Wire2)
    if (!status) {
        Serial.println("Could not find a valid BME280 sensor, check wiring, address, sensor ID!");
        Serial.print("SensorID was: 0x"); Serial.println(bme.sensorID(),16);
        Serial.print("        ID of 0xFF probably means a bad address, a BMP 180 or BMP 085\n");
        Serial.print("   ID of 0x56-0x58 represents a BMP 280,\n");
        Serial.print("        ID of 0x60 represents a BME 280.\n");
        Serial.print("        ID of 0x61 represents a BME 680.\n");
        while (1) delay(10);
    }
 
  Serial.println("-- Default Test --");
    delayTime = 1000;

    Serial.println();
 
  WiFi.begin(ssid, password);
  Serial.println("Pripojovani");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Pripojeno do site, IP adresa zarizeni: ");
  Serial.println(WiFi.localIP());
}
 
void loop() {
  //sensors_event_t humidity, temp; // promenne vlhkost a teplota
 
  // cteni teploty
  float teplota = bme.readTemperature();
  float vlhkost = bme.readHumidity();
  float tlak = bme.readPressure();
  

  // odeslani hodnot pres UART
  Serial.print("Teplota: "); Serial.print(teplota); Serial.println(" °C");
  Serial.print("Vlhkost: "); Serial.print(vlhkost); Serial.println(" %");
  Serial.print("Tlak: "); Serial.print(tlak); Serial.println(" hPa");
 
  // odeslani hodnot na TMEP.cz
  if(WiFi.status()== WL_CONNECTED){
      HTTPClient http;

      String serverPath = serverName + "teplota=" + (teplota) + "&humV=" + (vlhkost) + "&pressV=" + (tlak); //GUID pro teplotu "teplota", pro vlhkost "humV"
      
      // zacatek http spojeni
      http.begin(serverPath.c_str());
      
      // http get request
      int httpResponseCode = http.GET();
      
      if (httpResponseCode>0) {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
        String payload = http.getString();
        Serial.println(payload);
      }
      else {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
      }
      // Free resources
      http.end();
    }
    else {
      Serial.println("Wi-Fi odpojeno");
    }

  delay(60000);
}
