#define red 9
#define green 10
#define blue 11

int x;

void playUp(int pin){
  for (x=0;x<=255;x++){
    analogWrite(pin,x);
    delay(15);
  }
}

void playDown(int pin){
  for (x=255;x>=0;x--){
    analogWrite(pin,x);
    delay(15);
  }
}

void playUp3(){
  for (x=0;x<=255;x++){
    analogWrite(red,x);
    analogWrite(green,x);
    analogWrite(blue,x);
    delay(15);
  }
}

void playDown3(){
  for (x=255;x>=0;x--){
    analogWrite(red,x);
    analogWrite(green,x);
    analogWrite(blue,x);
    delay(15);
  }
}

void setup() {
  Serial.begin(115200);
}

void loop() {
  playUp(red);
  playUp(green);
  playDown(red);
  playUp(blue);
  playDown(green);
  playUp(red);
  playUp3();
  playDown3();
  
}
