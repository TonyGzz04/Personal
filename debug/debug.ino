//Include Libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//create an RF24 object
RF24 radio(9, 8);  // CE, CSN

//address through which two modules communicate.
const byte address[6] = "00002";
#define R_REGISTER    0x00

uint8_t read_register(R_REGISTER);
bool isChipConnected();

void setup()
{

  Serial.begin(9600);
  radio.begin();

  //set the address
  radio.openWritingPipe(address);

  //Set module as transmitter
  radio.stopListening();

    Serial.print(isChipConnected());
}

void loop() {
  // put your main code here, to run repeatedly:
    
      
}
