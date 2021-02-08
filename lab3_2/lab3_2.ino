int count = 0;

void setup()
{
    attachInterrupt(0, UP, FALLING);
    attachInterrupt(1, DOWN, FALLING);
    Serial.begin(115200);
    Serial.println("START");
    pinMode(2, INPUT_PULLUP);
    pinMode(3, INPUT_PULLUP);
    pinMode(13, OUTPUT);
}
void UP()
{
    if (count < 99)
    {
        count++;
        Serial.print("Count UP ");
        Serial.println(count);
    }
    else
    {
        count = 0;
        Serial.print("Count UP ");
        Serial.println(count);
    }
}

void DOWN()
{
    if (count > 0)
    {
        count--;
        Serial.print("Count DOWN ");
        Serial.println(count);
        delay(200);
    }
    else
    {
        count = 99;
        Serial.print("Count DOWN ");
        Serial.println(count);
    }
}

void loop()
{
    digitalWrite(13, HIGH);
    delay(2000);
    digitalWrite(13, LOW);
    delay(2000);
}