//the EEPROM chip works with both 3.3V and 5V
//I2C address is selected by address pins, here both are connected to GND which means 0x50
#include <at24c256.h>

AT24C256 eprom(0x50);  //connect AT24C256 I2C chip

int16_t message;    //varibale to store the incoming data from eeprom

const int PIN_D7 = 13;  //button to write one byte
const int PIN_D6 = 12;  //button to write another byte
const int PIN_D5 = 14;  //button to read the saved data

void setup() {
  Serial.begin(115200);
  Wire.begin();     //start wire interface for EEPROM since I2C bus used

  pinMode(PIN_D7, INPUT_PULLUP);   //to write one data D3
  pinMode(PIN_D6, INPUT_PULLUP);   //to write another data D2
  pinMode(PIN_D5, INPUT_PULLUP);   //to read data store in eeprom D1
}

void loop() {
  if(digitalRead(PIN_D7) == LOW){     //if button pressed to store a value
    eprom.update(0, 50);
    Serial.println("wrote eeprom1");
    delay(500);   //eliminate debounce
  }
  else if(digitalRead(PIN_D6) == LOW){  //if button pressed to store another value
    eprom.update(0, 100);
    Serial.println("wrote eeprom2");
    delay(500);   //eliminate debounce
  }
  else if(digitalRead(PIN_D5) == LOW){  //if buton pressed to read the stored data
    Serial.println("reading eeprom");
    message = eprom.read(0);
      if (eprom.getLastError() != 0) {
        Serial.print("Error reading from eeprom");
      } 
    Serial.println(message);
    delay(500);   //eliminate debounce
  }
  delay(100);
}