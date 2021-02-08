int LED[] = {10, 9, 8, 7, 6, 5};
void setup() {
  pinMode(LED[0], OUTPUT);
  pinMode(LED[1], OUTPUT);
  pinMode(LED[2], OUTPUT);
  pinMode(LED[3], OUTPUT);
  pinMode(LED[4], OUTPUT);
  pinMode(LED[5], OUTPUT);

}
int currentPin = 0;
void loop() {
  currentPin=0;
  while (currentPin <= 6) {
    digitalWrite(LED[currentPin], HIGH);
    delay(500);
    currentPin++;

  }
  currentPin=0;
  while (currentPin <= 6) {
    digitalWrite(LED[currentPin], LOW);
    currentPin++;
  }
  delay(500);
}
