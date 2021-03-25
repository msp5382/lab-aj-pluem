#define s1 D1
#define s2 D2
#define poten A0
#define red D5
#define green D6
#define blue D7

int light;
int countS1;
bool switchS1;
bool switchS2;
bool stateS2;

unsigned long lastPrint=0;

void rgbControl(int colorPin)
{
  light = analogRead(poten);
  analogWrite(colorPin, light);
}

void setup()
{
  Serial.begin(115200);
  pinMode(s1, INPUT_PULLUP);
  pinMode(s2, INPUT_PULLUP);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}

void loop()
{
  switchS1 = digitalRead(s1);
  switchS2 = digitalRead(s2);

  if (switchS1 == 0)
  {
    delay(100);
    if (switchS1 == 0 && countS1 < 3)
    {
      countS1++;
      delay(200);
      Serial.print(countS1);
      Serial.print(" ");
      Serial.println(stateS2);
    }
    else
    {
      countS1 = 0;
      Serial.print(countS1);
      Serial.print(" ");
      Serial.println(stateS2);
    }
  }
  if (switchS2 == 0)
  {
    delay(100);
    if (switchS2 == 0)
    {
      stateS2 = !stateS2;
      Serial.print(countS1);
      Serial.print(" ");
      Serial.println(stateS2);
      delay(200);
    }
  }
  if (stateS2 == 1)
  {
    if (countS1 == 1)
    {
      rgbControl(red);
    }
    else if (countS1 == 2)
    {
      rgbControl(green);
    }
    else if (countS1 == 3)
    {
      rgbControl(blue);
    }
  }
if(millis()-lastPrint>100){
  Serial.println(light);
  lastPrint=millis();
}

}
