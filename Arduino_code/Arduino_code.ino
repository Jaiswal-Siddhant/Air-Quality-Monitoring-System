/*
  Code by Jaiswal Siddhant for IoT project

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
      
    Buzzer:
      VCC - 9
      GND - GND
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
#define DHTTYPE DHT11

#define DELAY 2000
#define AIR_THRESHOLD 650         // 75% of detection range
#define TEMP_THRESHOLD 45         
#define HUMID_THRESHOLD 75
#define HYDROGEN_THRESHOLD 500    // H2 detection range 1-10,000ppm
#define CO_THRESHOLD 300          // CO detection range 1-500ppm

DHT dht(DHTPIN, DHTTYPE);

int readTemp(){
  int tempC = dht.readTemperature();
  if (isnan(tempC)) {
    Serial.print("T:");
    Serial.print(0);
    Serial.print(",");
    return 0;
  }
  Serial.print("T:");
  Serial.print(tempC);
  Serial.print(",");
  return tempC;
}

int readHumidity(){
  int humi  = dht.readHumidity();
  if (isnan(humi)){
    Serial.print("H:");
    Serial.print(0);
    Serial.print(",");
    return 0;
  }
  Serial.print("H:");
  Serial.print(humi);
  Serial.print(",");
  return humi;
}

int readAirQuality() {
  int AQ = analogRead(AirQuality);                 
  Serial.print("AQ:");
  Serial.print(AQ, DEC);
  Serial.print(",");
  return AQ;
}

int readCO(){
   int co  = analogRead(MQ7);
   Serial.print("CO:");
   Serial.print(co);
   Serial.print(",");
   return co;
}

int readH2(){
   int H2  = analogRead(MQ8);
   Serial.print("H2:");
   Serial.println(H2);
   return H2;
}

/* Start */
void setup() {
  Serial.begin(9600);
  pinMode(BUZZER_PIN, OUTPUT);
  dht.begin(); 
}

// Added buzzer config
void loop() {
  int AQ = readAirQuality();
  // readTempAndHumidity();
  int Humi = readHumidity();
  int Temp = readTemp();
  int CO = readCO();
  int H2 = readH2();

  if(
      AQ > AIR_THRESHOLD || 
      Temp > TEMP_THRESHOLD || 
      Humi > HUMID_THRESHOLD || 
      H2 > HYDROGEN_THRESHOLD || 
      CO > CO_THRESHOLD
  ){
    digitalWrite(BUZZER_PIN, HIGH);
  }else{
    digitalWrite(BUZZER_PIN, LOW);
  }
  delay(DELAY);
}
