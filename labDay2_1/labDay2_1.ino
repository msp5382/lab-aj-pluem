int analogValue;
float voltageValue;
float Voltage;


void setup() {
  
  Serial.begin(115200);

}

void loop() {
  analogValue=analogRead(A0);
  Serial.print("Analog : ");
  Serial.print(analogValue);
  voltageValue=map(analogValue,4,1002,0,255);
  Voltage=((voltageValue/255)*5);
  Serial.print("   Voltage : ");
  Serial.println(Voltage);
  delay(250);

}
