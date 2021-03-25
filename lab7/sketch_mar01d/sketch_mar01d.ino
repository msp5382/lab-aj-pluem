#define sw1 D1
#define sw2 D2

int LED[] = {D0, D3, D4, D5, D6, D7};
bool _led[] = {0, 0, 0, 0, 0, 0};

int count = 0;
void setup()
{
  pinMode(LED[0], OUTPUT);
  pinMode(LED[1], OUTPUT);
  pinMode(LED[2], OUTPUT);
  pinMode(LED[3], OUTPUT);
  pinMode(LED[4], OUTPUT);
  pinMode(LED[5], OUTPUT);
  pinMode(D1, INPUT_PULLUP);
  pinMode(D2, INPUT_PULLUP);

  Serial.begin(115200);
}


bool lastStateSW1 = 1;
bool lastStateSW2 = 1;


bool readSw(int sw) {
  bool state = digitalRead(sw);
 
  return state;
}

void listenToChange(){
   if(lastStateSW1 == 0){
    lastStateSW1 = readSw(sw1);
    }
    if(lastStateSW2 == 0){
    lastStateSW2 = readSw(sw2);
    }
}


void countUp() {
  if (!readSw(sw1) && lastStateSW1 == 1) {
    delay(50);
    //lastStateSw1=!(readSw(sw1);
    if (!readSw(sw1)) {
      lastStateSW1 = 0;
      if (count < 6) {
        count++;
      }
    }
    delay(200);
  }
}

void countDown() {
  if (!readSw(sw2) && lastStateSW2 == 1) {
    delay(50);
    if (!readSw(sw2)) {
      lastStateSW2 = 0;
      if (count > 0) {
        count--;
      }
    }
    delay(200);
  }
}

void loop() {
//    for(int x=0;x<6;x++){
//    Serial.print(_led[x]);
//    }
listenToChange();
countDown() ;
countUp() ;
Serial.println(count);
delay(100);
  // put your main code here, to run repeatedly:
 for(int x=0;x<count;x++){
    _led[x]=1;
  }
   for(int x=count;x<6;x++){
    _led[x]=0;
  }
for(int x=0;x<6;x++){
    digitalWrite(LED[x], _led[x]);
  }
}
