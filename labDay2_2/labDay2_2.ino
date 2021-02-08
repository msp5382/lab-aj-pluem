String valueRed;
String valueGreen;
String valueBlue;
int red;
int green;
int blue;

void RGB(int red,int green,int blue){
  analogWrite(9,red);
  analogWrite(10,green);
  analogWrite(11,blue);
}


void setup() {
  Serial.begin(115200);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);

}

void loop() {
  if (Serial.available() > 0) {
  valueRed=Serial.readStringUntil('&');
  valueGreen=Serial.readStringUntil('&');
  valueBlue=Serial.readStringUntil('\n');
  red=valueRed.toInt();
  green=valueGreen.toInt();
  blue=valueBlue.toInt();
  RGB(red,green,blue);
  }

}
