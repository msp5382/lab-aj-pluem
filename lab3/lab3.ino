int LED[] = {10, 9, 8, 7, 6, 5};

void setup()
{
  Serial.begin (115200);
  pinMode(LED[0], OUTPUT);
  pinMode(LED[1], OUTPUT);
  pinMode(LED[2], OUTPUT);
  pinMode(LED[3], OUTPUT);
  pinMode(LED[4], OUTPUT);
  pinMode(LED[5], OUTPUT);

}

unsigned long prevMillis = 0;

int globalPosition = 0;
String selectedType = "0";
String beforePauseType = "0";

void loop() {
  unsigned long currentMillis = millis();
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    if (command == "1" || command == "2" || command == "3" || command == "PAUSE" || command == "PLAY") {
      if (command == "PAUSE") {
        beforePauseType = selectedType;
      }

      if (command == "PLAY") {
        selectedType = beforePauseType;
      } 
      else {
        selectedType = command;
      }
      Serial.print("DOING ");
      Serial.println(command);
    }
    else {
      Serial.println("ERROR");
    }
  }

  if (selectedType == "1") {
    if (currentMillis - prevMillis >= 200) {
      runNum1(globalPosition);
      globalPosition++;
      prevMillis = currentMillis;
    }

  }
  else if (selectedType == "2") {
    if (currentMillis - prevMillis >= 200) {
      runNum2(globalPosition);
      globalPosition++;
      prevMillis = currentMillis;
    }

  }
  else if (selectedType == "3") {
    if (currentMillis - prevMillis >= 200) {
      runNum3(globalPosition);
      globalPosition++;
      prevMillis = currentMillis;
    }

  }

}

void clearLED() {
  int currentPin;
  for (currentPin = 0; currentPin < 7; currentPin++) {
    digitalWrite(LED[currentPin], LOW);
  }
}

void runNum1(int pos) {
  if (pos < 7) {
    digitalWrite(LED[pos], HIGH);
  } else {
    int currentPin;
    for (currentPin = 0; currentPin < 7; currentPin++) {
      digitalWrite(LED[currentPin], LOW);
    }
    globalPosition = -1;
  }
}
void runNum2(int pos) {
  if (pos < 7) {
    digitalWrite(LED[6 - pos], HIGH);
  } else {
    int currentPin;
    for (currentPin = 0; currentPin < 7; currentPin++) {
      digitalWrite(LED[currentPin], LOW);
    }
    globalPosition = -1;
  }
}

void runNum3(int pos) {
  if (pos < 7) {
    if (pos % 2 == 0) {
      digitalWrite(LED[6 - pos], HIGH);
    } else {
      digitalWrite(LED[pos], HIGH);
    }

  } else {
    int currentPin;
    for (currentPin = 0; currentPin < 7; currentPin++) {
      digitalWrite(LED[currentPin], LOW);
    }
    globalPosition = -1;
  }
}
