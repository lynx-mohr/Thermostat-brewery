#include <EEPROM.h>


void writeReadNumberToEEPROM(int number) {
  // Write the number to the EEPROM
  EEPROM.write(0, number / 10000);
  EEPROM.write(1, (number / 1000) % 10);
  EEPROM.write(2, (number / 100) % 10);
  EEPROM.write(3, (number / 10) % 10);
  EEPROM.write(4, number % 10);
 
  // Read the number back from the EEPROM
  int readNumber = EEPROM.read(0) * 10000 + EEPROM.read(1) * 1000 + EEPROM.read(2) * 100 + EEPROM.read(3) * 10 + EEPROM.read(4);
 
}





