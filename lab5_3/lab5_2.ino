#define sw 13
#define potenPin A5

#include <Servo.h>

Servo myservo;
bool S1;
bool lastS1 = 1;
bool state  = 1;
int volt;
int degree;
int minVolt = 0;
int maxVolt = 1001;

void readSw()
{
  S1 = digitalRead(sw);
  if (S1 == 0)
  {
    delay(50);
    S1 = digitalRead(sw);
    if (S1 == 0 )
    {
      if (state == 0) {
        state = 1;
      }
      else {
        state = 0;
      }
      Serial.println(state);
      delay(200);
    }
  }
}

void poten() {
  volt = analogRead(potenPin);
  degree = map(volt, minVolt, maxVolt, 0, 180);
}
void setup() {
  Serial.begin(9600);
  pinMode(sw, INPUT_PULLUP);
  myservo.attach(7);
}

void loop() {
  readSw();
  if (state == 1) {
    poten();
    myservo.write(degree);
    delay(8);
  }

}