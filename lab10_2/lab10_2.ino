#include <TridentTD_LineNotify.h>
#include "DHT.h"

#define SSID           "Aong"
#define PASSWORD       "12345678"
#define LINE_TOKEN     "D18vF6OmJuCJ71nHFjnfikVgQSTbqmWuIBzy3y52qH2"
#define DHTPIN D2
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

#define buttonPin D1
bool buttonState;             // the current reading from the input pin
bool lastButtonState = HIGH;
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 20;
float h,t;

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
        LINE.notify("NOW \nTemperature : " +String(t) +" °C\n Humidity : "+ String(h) +" %\n");
      }
    }
  }
  lastButtonState = reading;
}

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
  dht.begin();
}


unsigned long present;
unsigned long prevoius = 0;
unsigned long presentLine;
unsigned long prevoiusLine = 0;

void loop() {
  // Wait a few seconds between measurements.
  present = millis();
  readSw();
  if (present - prevoius >= 350) {

    // Reading temperature or humidity takes about 250 milliseconds!
    // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
    h = dht.readHumidity();
    // Read temperature as Celsius (the default)
    t = dht.readTemperature();

    // Check if any reads failed and exit early (to try again).
    if (isnan(h) || isnan(t)) {
      Serial.println(F("Failed to read from DHT sensor!"));
      return;
    }

    Serial.print(F("Humidity: "));
    Serial.print(h);
    Serial.print(F("%  Temperature: "));
    Serial.print(t);
    Serial.println(F("°C "));
    prevoius = present;
  }
  presentLine = millis();
  if (presentLine - prevoiusLine >= 10000) {
    LINE.notify("Auto \nTemperature : " +String(t) +" °C\n Humidity : "+ String(h) +" %\n");
    prevoiusLine = presentLine;
  }
}
