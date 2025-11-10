/*Thermostat for beer brewing with extra features including 

-choosing a yeast strain from my personal collection at startup which sets the perferred temperature of fermentation
-temperature of wort and the air surrounding vessel i monitored and sent to thingspeak
-maintaining stable temperatures during active fermentation
-ramping temperature at the end of fermentation
-cold crashing the beer post fermentation
-using EEPROM to remember important choices made before, in case of a power shortage

Written by Klas Bergman in 2020*/ 

//The libraries DallasTemperature and OneWire are needed for reading the temperatures
#include <DallasTemperature.h> 
#include <OneWire.h> 
#include <SoftwareSerial.h> //Nessessary to be able to use other pins for serial communication. Used by ESP8266
#include "ThingSpeak.h" //communication with Thingspeak
#include "HomeEasy.h" //The HomeEasy library lets me control a Nexa outlet
#include <RTClib.h>
#include <EEPROM.h> //Library lets me easily write data to ROM

SoftwareSerial ser(3, 2); // RX, TX 

#define ONE_WIRE_BUS 4 //   Data wire for the two sensors is plugged into digital port 4 on the Arduino
#define ONE_WIRE_BUS 4 //   Data wire for the two sensors is plugged into digital port 4 on the Arduino

OneWire oneWire(ONE_WIRE_BUS); // Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
DallasTemperature sensors(&oneWire); // Passing oneWire reference to Dallas Temperature.

HomeEasy homeEasy; //Creating an object of the HomeEasy class

String apiKey = "VENGTL7LQGT69C08"; //The key for my thingspeak channel. Mathworks

byte buzzer = 8;

float tempValueBeer;
float tempValueChamber;
unsigned int peakBeerTemp; //Used when determining when the temperature falls from it's highest point
int lowTempLimit;
int highTempLimit;
int preferredTemp;
unsigned long timeNowTemp; 
unsigned long timeNowThingSpeak;
unsigned long timeInterval = 16000; //interval between instances when data is sent to thingspeak
unsigned long timeInterval2 = 10000;
unsigned long timeOutSetup = 30000; //if no choice is made during setup for 20 seconds all settings stays the same as previously set.
unsigned long daysPassed;
unsigned long dayZero; 
DateTime now;
DateTime peakFerm; //Saves a time when the temperature in the fermenting beer is at it´s highest
DateTime startingTime;

 RTC_DS1307 rtc; //RTC-module

void setup() {
  // put your setup code here, to run once:

 ser.begin(9600); //Software Serial library used by esp8266
Serial.begin(9600); //For debugging and communication with program

 connectingWifi(); //Connecting to wifi, see tab wifi_connection.ini

 sensors.begin(); //Temperature sensors

 EEPROM.begin();

homeEasy = HomeEasy();

homeEasy.init();

if (! rtc.begin()) {
    Serial.println(F("Couldn't find RTC"));
    while (1);
  }

  if (! rtc.isrunning()) {
    Serial.println(F("RTC is NOT running!"));
    //following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

startingTime = rtc.now(); 
 
yeastChoiceMenu();

/*The reason for the timeout is in case of a power shortage, when the Arduino starts up again after the power has come back, noone is there to choose a yeast strain which in turn sets the preferred temperature for the fermentation. When timeout is reached the settings are read from RAM and is the same as before power shortage. */


dayZero = EEPROM.read(0) * 10000 + EEPROM.read(1) * 1000 + EEPROM.read(2) * 100 + EEPROM.read(3) * 10 + EEPROM.read(4); 


preferredTemp = EEPROM.read(5);// Sets the last preferred temperature that was chosen before the power shortage


while(timeOutSetup > millis()){  
  

if(Serial.available() > 0){



yeastSelection(); //Function found in the tab YeastLibrary.ino

 break;
  }
}

inquiriesMenu();

}

void loop() {


 // call sensors.requestTemperatures() to issue a global temperature request to all devices on the bus
if(millis() > timeNowTemp + timeInterval2){ 
  sensors.requestTemperatures(); // Send the command to get temperatures
  tempValueBeer = sensors.getTempCByIndex(0);
  tempValueChamber = sensors.getTempCByIndex(1); 
  timeNowTemp = millis(); //
}


sendDataThingSpeak(); // Sending data to Thingspeak, see tab send_to_thingspeak.ino 

nexaControl(); // Controlling the outlet which switches the freezer on and off, see tab UpdateNexa.ino

ramping(); //Checks to see if it's ramping time

if(Serial.available() > 0){

inquiries();

}

autoTempAdjustment(preferredTemp); //takes the preferredTemp set by choice of yeast strain in Setup and is processed for the thermostatic functionality, see tab AutoTempAdjustment.ino

now = rtc.now(); 


daysPassed = now.unixtime() / 86400; //This many days has passed since 1 jan 1970 




}

