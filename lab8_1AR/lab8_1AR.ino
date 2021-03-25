#include <SoftwareSerial.h>
SoftwareSerial Ar(9,10);
int light;
void setup() {
  Serial.begin(115200);
  Ar.begin(9600);

}

void loop() {
  while(Ar.available()>0){
    light=Ar.read();
    analogWrite(3,light);
    Serial.println(light);
  }

}
