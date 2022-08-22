/*
* This example code for Temperature, Humidity and Pressure BME280 module
* is used with ESP32 LPkit board.
* ESP32-LPkit reads Temperature, Humidity and Pressure from BME280 sensor 
* and sends every second through UART
*
* SDA - GPIO21
* SCL - GPIO22
*
* Made by (c) laskakit.cz 2022
*
* Libraries
* https://github.com/adafruit/Adafruit_BME280_Library
* https://github.com/adafruit/Adafruit_Sensor
*/

#include <Wire.h>
#include <Adafruit_Sensor.h>    // https://github.com/adafruit/Adafruit_Sensor
#include <Adafruit_BME280.h>    // https://github.com/adafruit/Adafruit_BME280_Library

#define SEALEVELPRESSURE_HPA (1013.25)
#define DELAYTIME 1000
#define BME280_ADDRESS (0x77)   // (0x76) cut left and solder left pad on board

Adafruit_BME280 bme; // I2C

void setup() {

    Serial.begin(115200);
    while(!Serial);    // time to get serial running
    Serial.println("BME280 test");


  // initilizace BME280 | BME280 Initialization
    Wire.begin (21, 22); // for ESP32 + uŠup
    if (! bme.begin(BME280_ADDRESS)) {
        Serial.println("Could not find a valid BME280 sensor, check wiring, address, sensor ID!");
        Serial.print("SensorID was: 0x"); Serial.println(bme.sensorID(),16);
        Serial.print("        ID of 0xFF probably means a bad address, a BMP 180 or BMP 085\n");
        Serial.print("   ID of 0x56-0x58 represents a BMP 280,\n");
        Serial.print("        ID of 0x60 represents a BME 280.\n");
        Serial.print("        ID of 0x61 represents a BME 680.\n");
        while (1) delay(10);
    }
    Serial.println("-- Weather Station Scenario --");
    Serial.println("forced mode, 1x temperature / 1x humidity / 1x pressure oversampling,");
    Serial.println("filter off");
    bme.setSampling(Adafruit_BME280::MODE_FORCED,
                  Adafruit_BME280::SAMPLING_X1, // temperature
                  Adafruit_BME280::SAMPLING_X1, // pressure
                  Adafruit_BME280::SAMPLING_X1, // humidity
                  Adafruit_BME280::FILTER_OFF   );
    
    Serial.println("-- Default Test --");
    Serial.println();
}


void loop() { 
    printValues();
    delay(DELAYTIME);
}


void printValues() {
    Serial.print("Temperature = ");
    Serial.print(bme.readTemperature());
    Serial.println(" °C");

    Serial.print("Pressure = ");
    Serial.print(bme.readPressure() / 100.0F);
    Serial.println(" hPa");

    Serial.print("Approx. Altitude = ");
    Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
    Serial.println(" m");

    Serial.print("Humidity = ");
    Serial.print(bme.readHumidity());
    Serial.println(" %");

    Serial.println();
}
