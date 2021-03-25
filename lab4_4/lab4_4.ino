#include "DHT.h"
#include <LiquidCrystal_I2C.h> // ประกาศ Library
// ตั้งค่า Module IIC/I2C(add,row,coloum)
LiquidCrystal_I2C lcd(0x27, 16, 2); // บางรุ่นอาจจะใช้ 0x3F

#define DHTPIN 2 // Digital pin connected to the DHT sensor

// Uncomment whatever type you're using!
#define DHTTYPE DHT22 // DHT 22  (AM2302), AM2321

#define buttonPin 13
#define ldrPin A0

unsigned long presentTemp;
unsigned long previousTemp;
unsigned long presentTime;
unsigned long previousTime;
unsigned long presentLight;
unsigned long previousLight;

int buttonState;           // the current reading from the input pin
int lastButtonState = LOW; // the previous reading from the input pin

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0; // the last time the output pin was toggled
unsigned long debounceDelay = 50;   // the debounce time; increase if the output flickers

//temp and humendity
float h;
float t;

//timer
int second = 0;
int minute;
int hour;
int count;

//LDR
int light;
int minlight = 720;
int maxlight = 1012;
float percent;

DHT dht(DHTPIN, DHTTYPE);

void timed()
{
  if (presentTime - previousTime >= 1000)
  {
    second++;
    if (second == 60)
    {
      minute++;
      second = 0;
    }
    if (minute == 60)
    {
      hour++;
      minute = 0;
    }
    previousTime = presentTime;
  }
}

int sensor()
{
  if (presentTemp - previousTemp >= 1000)
  {
    // Reading temperature or humidity takes about 250 milliseconds!
    // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
    h = dht.readHumidity();
    // Read temperature as Celsius (the default)
    t = dht.readTemperature();

    // Check if any reads failed and exit early (to try again).
    if (isnan(h) || isnan(t))
    {
      Serial.println(F("Failed to read from DHT sensor!"));
      return;
    }
    previousTemp = presentTime;
  }
}

void readSwitch()
{
  int reading = digitalRead(buttonPin);
  if (reading != lastButtonState)
  {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay)
  {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState)
    {
      buttonState = reading;

      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH)
      {
        if (count < 3)
        {
          count++;
        }
        else
        {
          count = 1;
        }
      }
      if (count == 1)
      {
        lcd.setCursor(0, 1);
        lcd.print("                ");
      }
    }
  }
  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState = reading;
}

void LDR()
{
  if (presentLight - previousLight >= 1000)
  {
    light = analogRead(ldrPin);
    if (light < minlight)
      light = minlight; //ปรับค่าความสว่างต่ำสุดสูงสุดด้วย !!!!!!!!!!!!
    if (light > maxlight)
      light = maxlight;                                                     //ปรับค่าความสว่างต่ำสุดสูงสุดด้วย !!!!!!!!!!!!
    percent = (float(light - minlight) / float(maxlight - minlight)) * 100; //คำนวนเปอร์เซ็นต์ความสว่าง
    // Serial.println(light);// uncomment to read light
    previousLight = presentLight;
  }
}
void setup()
{
  lcd.begin();     // ใช้หน้าจอ LCD
  lcd.backlight(); // เปิด backlight
  Serial.begin(9600);

  dht.begin();
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop()
{
  LDR();
  readSwitch();
  presentTemp = millis();
  presentTime = millis();
  presentLight = millis();
  sensor();
  timed();

  lcd.setCursor(4, 0);
  lcd.print(hour / 10);
  lcd.print(hour % 10);
  lcd.print(":");
  lcd.print(minute / 10);
  lcd.print(minute % 10);
  lcd.print(":");
  lcd.print(second / 10);
  lcd.print(second % 10);

  if (count == 1)
  {
    lcd.setCursor(0, 1);
    lcd.print("Temp");
    lcd.setCursor(9, 1);
    lcd.print(t);
    lcd.setCursor(15, 1);
    lcd.print("C");
  }
  else if (count == 2)
  {
    lcd.setCursor(0, 1);
    lcd.print("Humidit");
    lcd.setCursor(9, 1);
    lcd.print(h);
    lcd.setCursor(15, 1);
    lcd.print("%");
  }
  else if (count == 3)
  {
    lcd.setCursor(0, 1);
    lcd.print("Brightness");
    lcd.setCursor(10, 1);
    lcd.print(percent);
    lcd.setCursor(15, 1);
    lcd.print("%");
  }
}