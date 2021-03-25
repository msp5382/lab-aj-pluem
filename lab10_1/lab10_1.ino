#include<TridentTD_LineNotify.h>
#define SSID           "Aong"
#define PASSWORD       "12345678"
#define LINE_TOKEN     "D18vF6OmJuCJ71nHFjnfikVgQSTbqmWuIBzy3y52qH2"

#define buttonPin D1
bool buttonState;             // the current reading from the input pin
bool lastButtonState = HIGH;
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 20;
void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println(LINE.getVersion());
  pinMode(D1, INPUT_PULLUP);

  WiFi.begin(SSID, PASSWORD);
  Serial.printf("WiFi connecting to %s\n", SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(400);
  }
  Serial.printf("\nWiFi connected\nIP : ");
  Serial.println(WiFi.localIP());
  LINE.setToken(LINE_TOKEN);
}

void readSw() {
  int reading = digitalRead(buttonPin);
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;
      // only toggle the LED if the new button state is HIGH
      if (buttonState == LOW) {
        Serial.println("กดตุ่ม");
        LINE.notify("กดตุ่ม");
      }
    }
  }
  lastButtonState=reading;
}
unsigned long present;
unsigned long prevoius = 0;

void loop() {
  readSw();
  int a = map(analogRead(A0), 600, 1023, 0, 100);
  int light=constrain(a,0,100);
  Serial.println(light);
  if (light < 32) {
    Serial.println("แสงน้อยแล้ว");
    LINE.notify("แสงน้อยแล้วว");
  }
}
