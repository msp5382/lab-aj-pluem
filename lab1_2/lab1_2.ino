int LED[] = {10, 9, 8, 7, 6, 5};
void setup() {
  pinMode(LED[0], OUTPUT);
  pinMode(LED[1], OUTPUT);
  pinMode(LED[2], OUTPUT);
  pinMode(LED[3], OUTPUT);
  pinMode(LED[4], OUTPUT);
  pinMode(LED[5], OUTPUT);

}
int currentPin;
void loop() {
  for (currentPin = 0; currentPin < 7; currentPin++) {
        digitalWrite(LED[currentPin], HIGH);

    delay(500);
  }
  
   for (currentPin = 0; currentPin < 7; currentPin++) {
        digitalWrite(LED[currentPin], LOW);

  }
  delay(500);
}
