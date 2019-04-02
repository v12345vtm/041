#include "IRLibAll.h"

//Create a receiver object to listen on pin 2
//hele goede !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
IRrecvPCI myReceiver(2);

//Create a decoder object 
IRdecode myDecoder;   

void setup() {
  Serial.begin(115200);  
  myReceiver.enableIRIn(); // Start the receiver
  Serial.println(F("Ready to receive IR signals decodeerd ook nec mooi , v12345vtm"));
}

void loop() {
  //Continue looping until you get a complete signal received
  if (myReceiver.getResults()) {
    myDecoder.decode();           //Decode it
    myDecoder.dumpResults(true);  //Now print results. Use false for less detail
    myReceiver.enableIRIn();      //Restart receiver
  }
}
