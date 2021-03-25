#include <SoftwareSerial.h>
SoftwareSerial Ar(9,10);
void setup() {
  Serial.begin(9600);
  Ar.begin(9600);

}

void loop() {
  while(Ar.available()>0){
    if(Ar.read=='1'){
      Serial.printlm("OK");
      Ar.print("Hell NodeMCU");
    }
    else{
      Serial.println("ERROR");
    }
  }

}
