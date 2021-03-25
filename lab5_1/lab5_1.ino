
void setup() {
    for (int i = 8; i <= 11;i++){
        pinMode(i, OUTPUT);
    }
    runInStep(256);
    runInBackStep(256);
}

void runInStep (int _step){
  for(int c = 0; c <= _step;c++){
    for (int i = 0; i < 4;i++){
        digitalWrite(8, steps[i][0]);
        digitalWrite(9, steps[i][1]);
        digitalWrite(10, steps[i][2]);
        digitalWrite(11, steps[i][3]);
        delay(10);
    }
  }
    
} 

void runInBackStep (int _step){
  for(int c = 0; c <= _step;c++){
    for (int i = 0; i < 4;i++){
        digitalWrite(8, steps[i][3]);
        digitalWrite(9, steps[i][2]);
        digitalWrite(10, steps[i][1]);
        digitalWrite(11, steps[i][0]);
        delay(10);
    }
  }
    
} 

void loop() {
}