int LED[] = {D0, D3, D4, D5, D6, D7};
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
void loop() {
  if (Serial.available() > 0) {
    String pin = Serial.readStringUntil(' ');
    String command = Serial.readStringUntil('\n');
    if (!(pin.toInt() > 6) && !(pin.toInt() < 1) && (command == "ON" || command == "OFF")) {
      Serial.print("LED: ");
      Serial.print(pin);
      Serial.print(" ");
      Serial.println(command);
      if (command == "ON") {
        digitalWrite(LED[pin.toInt() - 1], HIGH);
      } else if (command == "OFF") {
        digitalWrite(LED[pin.toInt() - 1], LOW);
      }

    } else {
      Serial.println("ERROR");
    }
  }
}
