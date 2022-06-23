/*
  Created by Jaiswal Siddhant for IoT project

  This code reads Temperature, Humidity, Carbon Monoxide, Hydrogen and other Gases

  Group Members: 
    Vaivaswat Yeotikar   ,  Ayyan Shaikh    
    Vyankatesh Tuppalwad ,  Nawaz Khan
    
  Components: 
     MQ7, MQ8, MQ135, DHT11

  Pin Configuration:
    DHT11:
      VCC  - +5v
      GND  - GND
      Data - Pin 8

    MQ7:
      VCC - +5v
      GND - GND
      A0  - A3
    
    MQ8:
      VCC - +5v
      GND - GND
      A0  - A5

    MQ135:
      VCC - +5v
      GND - GND
      A0  - A0  
*/

#include "DHT.h"

// Input Pins
#define DHTPIN 8
#define AirQuality A0
#define MQ7 A3
#define MQ8 A5

// Output Pins
#define BUZZER_PIN 9

// Constants
#define DELAY 2000
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void readTempAndHumidity() {
  int humi  = dht.readHumidity();
  // read temperature as Celsius
  int tempC = dht.readTemperature();

  if (isnan(humi) || isnan(tempC)) {
    // Failed to read from DHT sensor!
    Serial.print("H:");
    Serial.print(0);
    Serial.print(",");
    Serial.print("T:");
    Serial.print(0);
    Serial.print(",");
  } else {
    Serial.print("H:");
    Serial.print(humi);
    Serial.print(",");
    Serial.print("T:");
    Serial.print(tempC);
    Serial.print(",");
  }
}

void readAirQuality() {
  int AQ = analogRead(AirQuality);                 
  Serial.print("AQ:");
  Serial.print(AQ, DEC);
  Serial.print(",");
}

void readCO(){
   int co  = analogRead(MQ7);
   Serial.print("CO:");
   Serial.print(co);
   Serial.print(",");
}

void readH2(){
   int co  = analogRead(MQ8);
   Serial.print("H2:");
   Serial.println(co);
}

/* Start */
void setup() {
  Serial.begin(9600);
  dht.begin(); 
}

void loop() {
  readAirQuality();
  readTempAndHumidity();
  readCO();
  readH2();
  delay(DELAY);
}
