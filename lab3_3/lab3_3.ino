#define s1 2
#define s2 3
#define poten A0
#define red 9
#define green 10
#define blue 11

int light;
int countS1;
bool switchS1;
bool switchS2;
bool stateS2;

void rgbControl(int colorPin)
{
    light = map(analogRead(poten), 0, 1023, 0, 255);
    analogWrite(colorPin, light);
}

void setup()
{
    Serial.begin(115200);
    pinMode(2, INPUT_PULLUP);
    pinMode(3, INPUT_PULLUP);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
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
        }
        else
        {
            countS1 = 0;
        }
    }
    if (switchS2 == 0)
    {
        delay(100);
        if (switchS2 == 0)
        {
            stateS2 = !stateS2;
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
    Serial.print(countS1);
    Serial.print(" ");
    Serial.println(stateS2);

}