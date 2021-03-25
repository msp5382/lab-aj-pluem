#include <SoftwareSerial.h>
SoftwareSerial Node(D2,D3);

int poten;
int light;
void setup() {
  Serial.begin(115200);
  Node.begin(9600);
}

void loop() {
 poten=analogRead(A0);
 light=map(poten,0,1023,0,255);
 Node.write(light);
}
