/*In this tab there is firstly the yeast choice menu that is displayed upon start in the serial monitor. Called from setup. Then there is the yeast selection which is built using a switch case setup. Based on the chosen strain, the preferred tempareture is set. Upon user choice the temp i written to arduino RAM. So if there is a power shortage, the preferred temperature is remembered. It is important that the value in RAM is erased when fermenation is terminated. In the coldcrash-function, the data positions in RAM is emptied "set to 0". 

Following that is the menu for communication during setup and the switch case corresponding to that menu. */

//This function displays the yeast selection menu. Called from setup. 

void yeastChoiceMenu(){
 Serial.println(F("*************************************")); 
 Serial.println(F("Pick a yeast strain using the keyboard"));
 Serial.println(F("                                     "));
 Serial.println(F("[a]: LONDON ALE I"));
 Serial.println(F("[b]: OLD BAVARIAN LAGER"));
 Serial.println(F("[c]: B45 GNOME"));
 Serial.println(F("[d]: IRISH ALE"));
 Serial.println(F("[e]: SAN DIEGO SUPER"));
 Serial.println(F("[f]: STARO PRAGUE LAGER"));
 Serial.println(F("[g]: GERMAN BOCK LAGER"));
 Serial.println(F("[h]: DRY ENGLISH ALE"));
  Serial.println(F("[i]: LONDON ALE III"));
 Serial.println(F("[j]: KÖLSCH"));
 Serial.println(F("[k]: BURLINGTON ALE YEAST"));
 Serial.println(F("*************************************"));

 }

 //This function sets the preferred temp from user input and displays information in the serial monitor. 
void yeastSelection(){

byte selectionFromMenu = Serial.read();

  switch (selectionFromMenu) {

case 'a':

selectionFromMenu = 0;
 
 Serial.println(F(""));
  Serial.println(F("The yeast selected for this brew is LONDON ALE [WYEAST 1968]"));
  Serial.println(F("The temperature range for this strain is (18 - 22) C"));
  Serial.println(F("Attenuation for this strain is (67-71) %")); 
  Serial.println(F("Flocculation: High")); 
  Serial.println(F(""));

preferredTemp = 19;

dayZero = startingTime.unixtime() / 86400; 

writeReadNumberToEEPROM(dayZero);
EEPROM.write(5, preferredTemp);


break;

case 'b': 

selectionFromMenu = 0;
  Serial.println(F(""));
  Serial.println(F("The yeast selected for this brew is OLD BAVARIAN LAGER"));
  Serial.println(F("The temperature range for this strain is (10 - 13) C"));
  Serial.println(F("Attenuation for this strain is (66-73) %")); 
  Serial.println(F("Flocculation: Medium - High")); 
  Serial.println(F(""));

preferredTemp = 12;

dayZero = startingTime.unixtime() / 86400; 

writeReadNumberToEEPROM(dayZero);
EEPROM.write(5, preferredTemp);



break;

case 'c':
selectionFromMenu = 0;
  Serial.println(F(""));
  Serial.println(F("The yeast selected for this brew is B45 GNOME"));
  Serial.println(F("The temperature range for this strain is (13 - 21) C"));
  Serial.println(F("Attenuation for this strain is (73-77) %")); 
  Serial.println(F("Flocculation: Low")); 
  Serial.println(F(""));

preferredTemp = 14;

dayZero = startingTime.unixtime() / 86400; 

writeReadNumberToEEPROM(dayZero);
EEPROM.write(5, preferredTemp);

break;

case 'd':
selectionFromMenu = 0;
  Serial.println(F(""));
  Serial.println(F("The yeast selected for this brew is Irish Ale"));
  Serial.println(F("The temperature range for this strain is (17 - 22) C"));
  Serial.println(F("Attenuation for this strain is (71-75) %")); 
  Serial.println(F("Flocculation: Medium")); 
  Serial.println(F(""));

preferredTemp = 18;

dayZero = startingTime.unixtime() / 86400; 

writeReadNumberToEEPROM(dayZero);
EEPROM.write(5, preferredTemp);


break;
 
case 'e':
selectionFromMenu = 0;
  Serial.println(F(""));
  Serial.println(F("The yeast selected for this brew is San Diego Super"));
  Serial.println(F("The temperature range for this strain is (18 - 20) C"));
  Serial.println(F("Attenuation for this strain is (76-83) %")); 
  Serial.println(F("Flocculation: Medium to High")); 
  Serial.println(F(""));

preferredTemp = 19;

dayZero = startingTime.unixtime() / 86400; 

writeReadNumberToEEPROM(dayZero);
EEPROM.write(5, preferredTemp);


break; 

case 'f':
selectionFromMenu = 0;
  Serial.println(F(""));
  Serial.println(F("The yeast selected for this brew is Staro Prague Lager"));
  Serial.println(F("The temperature range for this strain is (10 - 14) C"));
  Serial.println(F("Attenuation for this strain is (70-74) %")); 
  Serial.println(F("Flocculation: High")); 
  Serial.println(F(""));

preferredTemp = 12;

dayZero = startingTime.unixtime() / 86400; 

writeReadNumberToEEPROM(dayZero);
EEPROM.write(5, preferredTemp);


break;
case 'g':
selectionFromMenu = 0;
  Serial.println(F(""));
  Serial.println(F("The yeast selected for this brew is German Bock Lager"));
  Serial.println(F("The temperature range for this strain is (9 - 13) C"));
  Serial.println(F("Attenuation for this strain is (70-76) %")); 
  Serial.println(F("Flocculation: Medium")); 
  Serial.println(F(""));

preferredTemp = 11;

dayZero = startingTime.unixtime() / 86400; 

writeReadNumberToEEPROM(dayZero);
EEPROM.write(5, preferredTemp);


break;
case 'h':
selectionFromMenu = 0;
  Serial.println(F(""));
  Serial.println(F("The yeast selected for this brew is Dry English Ale"));
  Serial.println(F("The temperature range for this strain is (18 - 21) C"));
  Serial.println(F("Attenuation for this strain is (70-80) %")); 
  Serial.println(F("Flocculation: Medium to High")); 
  Serial.println(F(""));

preferredTemp = 20;

dayZero = startingTime.unixtime() / 86400; 

writeReadNumberToEEPROM(dayZero);
EEPROM.write(5, preferredTemp);


break;
case 'i':
selectionFromMenu = 0;
  Serial.println(F(""));
  Serial.println(F("The yeast selected for this brew is London Ale III"));
  Serial.println(F("The temperature range for this strain is (18 - 23) C"));
  Serial.println(F("Attenuation for this strain is (71-75) %")); 
  Serial.println(F("Flocculation: High")); 
  Serial.println(F(""));

preferredTemp = 19;

dayZero = startingTime.unixtime() / 86400; 

writeReadNumberToEEPROM(dayZero);
EEPROM.write(5, preferredTemp);


break;
case 'j':
selectionFromMenu = 0;
  Serial.println(F(""));
  Serial.println(F("The yeast selected for this brew is Kölsch"));
  Serial.println(F("The temperature range for this strain is (13 - 21) C"));
  Serial.println(F("Attenuation for this strain is (73-77) %")); 
  Serial.println(F("Flocculation: Low")); 
  Serial.println(F(""));

preferredTemp = 15;

dayZero = startingTime.unixtime() / 86400; 

writeReadNumberToEEPROM(dayZero);
EEPROM.write(5, preferredTemp);

break;

case 'k':
selectionFromMenu = 0;
  Serial.println(F(""));
  Serial.println(F("The yeast selected for this brew is Burlington Ale Yeast"));
  Serial.println(F("The temperature range for this strain is (19 - 22) C"));
  Serial.println(F("Attenuation for this strain is (75-80) %")); 
  Serial.println(F("Flocculation: Medium")); 
  Serial.println(F(""));

preferredTemp = 20;

dayZero = startingTime.unixtime() / 86400; 

writeReadNumberToEEPROM(dayZero);
EEPROM.write(5, preferredTemp);


break;
 
}

}


//This function displays a menu for the purpose of answering inquiries during fermentation and erase RAM and induce cold crash manually

void inquiriesMenu(){
 Serial.println(F("************************************************************************************")); 
 Serial.print(F("**Press [a] for Beer temp"));
 Serial.print(F("                     "));
 Serial.println(F("Press [b] for Chamber temp************"));
 Serial.print(F("**Press [c] for Preferred temp"));
 Serial.print(F("                "));
 Serial.println(F("Press [d] for Date/time stamp*********"));
 Serial.print(F("**Press [e] to erase temp from RAM"));
 Serial.print(F("            "));
 Serial.println(F("Press [f] to see whats in RAM*********"));
  Serial.print(F("**Press [g] to manually initiate cold crash"));
 Serial.print(F("   "));
 Serial.println(F("Press [h] to inquire low/high limits**"));
 Serial.println(F("************************************************************************************"));

 }

void inquiries(){

byte loopMenyItems = Serial.read();

switch(loopMenyItems){

  case 'a':

Serial.print(F("Temperature beer: "))  ;
Serial.print(tempValueBeer);
Serial.println(F(" degrees"))  ;

break;

case 'b':

Serial.print(F("Temperature chamber: "))  ;
Serial.print(tempValueChamber);
Serial.println(F(" degrees"));

 break;

 case 'c':

Serial.print(F("Preferred temperature: "));
Serial.print(preferredTemp);
Serial.println(F(" degrees"))  ;


break;

case 'd':

Serial.print(F("The date and time is: "));
Serial.print(now.year(), DEC);
    Serial.print(F("-"));
    Serial.print(now.month(), DEC);
    Serial.print(F("-"));
    Serial.print(now.day(), DEC);
    Serial.print(F("-"));    
    Serial.print(now.hour(), DEC);
    Serial.print(F("-"));
    Serial.print(now.minute(), DEC);
    Serial.print(F("  days passed since start of fermentation: "));
    Serial.print(daysPassed-dayZero);
    Serial.print(F( ". dayZero: "));
    Serial.print(dayZero);
    Serial.print(F( ". daysPassed since 1970: "));
    Serial.print(daysPassed);
    Serial.println(F("."));


break;

case 'e':

EEPROM.write(0, 0);
Serial.println(F("Temperature erased from RAM"));
Serial.print(F("Value on position 0 in RAM: "));
Serial.println(EEPROM.read(0));

break;

case 'f':

Serial.print(F("Value on position 5 in RAM i.e. the preferred temperature: "));
Serial.println(EEPROM.read(5));
Serial.print(F("Value on position 1-4 in RAM i.e. the starting day: "));
Serial.println(EEPROM.read(0) * 10000 + EEPROM.read(1) * 1000 + EEPROM.read(2) * 100 + EEPROM.read(3) * 10 + EEPROM.read(4));


break;

case 'g':

coldCrash(); 
Serial.print(F("Cold Crash initiated. Preferred temp is changed to: "));
Serial.println(preferredTemp); 

break;

case 'h':

Serial.print(F("Low templimit = "));
Serial.print(lowTempLimit);
Serial.print(F("  High templimit = "));
Serial.println(highTempLimit);

break;

 default: ;


}
}
