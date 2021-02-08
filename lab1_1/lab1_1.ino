int LED[] = {10, 9, 8, 7, 6, 5};

void setup()
{
  pinMode(LED[0], OUTPUT);
  pinMode(LED[1], OUTPUT);
  pinMode(LED[2], OUTPUT);
  pinMode(LED[3], OUTPUT);
  pinMode(LED[4], OUTPUT);
  pinMode(LED[5], OUTPUT);

}

int currentPin = 0;

void loop()
{
  if (currentPin < 6) {
    if (currentPin >= 0) {
      digitalWrite(LED[0], HIGH);
    } else {
      digitalWrite(LED[0], LOW);
    }
    if (currentPin >= 1) {
      digitalWrite(LED[1], HIGH);
    } else {
      digitalWrite(LED[1], LOW);
    }
    if (currentPin >= 2) {
      digitalWrite(LED[2], HIGH);
    } else {
      digitalWrite(LED[2], LOW);
    }
    if (currentPin >= 3) {
      digitalWrite(LED[3], HIGH);
    } else {
      digitalWrite(LED[3], LOW);
    }
    if (currentPin >= 4) {
      digitalWrite(LED[4], HIGH);
    } else {
      digitalWrite(LED[4], LOW);
    }
    if (currentPin >= 5) {
      digitalWrite(LED[5], HIGH);
    } else {
      digitalWrite(LED[5], LOW);
    }
    currentPin++;
  } else {
    currentPin = 0;
    digitalWrite(LED[0], LOW);
    digitalWrite(LED[1], LOW);
    digitalWrite(LED[2], LOW);
    digitalWrite(LED[3], LOW);
    digitalWrite(LED[4], LOW);
    digitalWrite(LED[5], LOW);
  }
  delay(500);
}
