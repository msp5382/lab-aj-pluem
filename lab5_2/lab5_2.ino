int steps[4][4] = {{1,1,0,0},
                   {0,1,1,0},
                   {0,0,1,1},
                   {1,0,0,1}};

void setup() {
    Serial.begin(9600);
    for (int i = 8; i <= 11;i++){
        pinMode(i, OUTPUT);
    }
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
  if (Serial.available() > 0) {
    String way = Serial.readStringUntil(',');
    String gack = Serial.readStringUntil('E');
    if (way == "LEFT" || way == "RIGHT") {
      Serial.print("WAY: ");
      Serial.print(way);
      Serial.print(" ");
      Serial.println(gack);
      if (way == "LEFT") {
        runInStep(gack.toInt());
      }
      else if (way == "RIGHT")
      {
        runInBackStep(gack.toInt());
      }
    } else {
      Serial.println("ERROR");
    }
  }
}