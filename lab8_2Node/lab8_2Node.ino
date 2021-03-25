#include <SoftwareSerial.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
SoftwareSerial Node(D5, D6);
LiquidCrystal_I2C lcd(0x27, 20, 4);

unsigned long presentPrint;
unsigned long prevoiusPrint = 0;
void setup() {
  Serial.begin(115200);
  Node.begin(9600);
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
}

String Buffer;
String humendity ;
String temperature ;
void loop() {
  presentPrint = millis();
  while (Node.available() > 0) {
    Buffer = Node.readStringUntil('\n');
    char inputBuffer[11];
    Buffer.toCharArray(inputBuffer, 11);
//    humendity += inputBuffer[0]+inputBuffer[1]+inputBuffer[2]+inputBuffer[3]+inputBuffer[4];
//    temperature += inputBuffer[6]+inputBuffer[7]+inputBuffer[8]+inputBuffer[9]+inputBuffer[10];
    humendity = "";
    for(int c=0;c<4;c++){
      humendity += inputBuffer[c];
    }

    temperature = "";
    for(int c=6;c<10;c++){
      temperature += inputBuffer[c];
    }
    
    Serial.print("Buff");
    Serial.println(Buffer);
//    humendity = Node.read();
//    temperature = Node.read();
    Serial.print(F("Humidity: "));
    Serial.print(humendity);
    Serial.print(F("%  Temperature: "));
    Serial.print(temperature);
    Serial.println(F("°C "));
  }
  if (presentPrint - prevoiusPrint >= 1000) {
    lcd.setCursor(0, 0);
    lcd.print("Humidity :");
    lcd.print(humendity);
    lcd.print(" %");
    lcd.setCursor(0, 1);
    lcd.print("Temp :");
    lcd.print(temperature);
    lcd.print(" C ");
    prevoiusPrint = presentPrint;
  }
}
