#include <AT24C256.h>

AT24C256 eeprom(0x50);

int8_t eeprom_items_space = 30;
char write_helloworld[] = "Hello World!";
char write_alamin[] = "Alamin ashik!";
char message[30];

const int PIN_D7 = 13;
const int PIN_D6 = 12;
const int PIN_D5 = 14;

void setup() {
  Serial.begin(115200);

  pinMode(PIN_D7, INPUT_PULLUP);   //to write one data D3
  pinMode(PIN_D6, INPUT_PULLUP);   //to write another data D2
  pinMode(PIN_D5, INPUT_PULLUP);   //to read data store in eeprom D1
}

void loop() {
  if(digitalRead(PIN_D7) == LOW){
    eeprom.write(0, (uint8_t*)write_helloworld, eeprom_items_space);  //eeprom.read(readAddress, *data, len)
    Serial.println("wrote eeprom1");
    delay(500);
  }
  else if(digitalRead(PIN_D6) == LOW){
    eeprom.write(0, (uint8_t*)write_alamin, eeprom_items_space);  //eeprom.read(writeAddress, *data, len)
    Serial.println("wrote eeprom2");
    delay(500);   
  }
  else if(digitalRead(PIN_D5) == LOW){
    Serial.println("reading eeprom");
    eeprom.read(0, (uint8_t*)message, eeprom_items_space); //eeprom.read(readAddress, *data, len)
    Serial.println(message);
    delay(500);
  }
  delay(100);
}
