#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  // initialize the LCD
  lcd.begin();

  // Turn on the blacklight and print a message.
  lcd.backlight();
  lcd.print("K");
  lcd.setCursor(1, 0);
  lcd.print("U");
  lcd.setCursor(2, 0);
  lcd.print("Y");
}

void loop()
{
  // Do nothing here...
}
