bool lastStateS1 = 1;
bool presentStateS1;
bool lastStateS2 = 1;
bool presentStateS2;

int count = 0;

void setup()
{
    Serial.begin(115200);
    Serial.println("count");
    pinMode(2, INPUT_PULLUP);
    pinMode(3, INPUT_PULLUP);
}

void loop()
{

    presentStateS1 = digitalRead(2);
    presentStateS2 = digitalRead(3);
    if (lastStateS1 == 1)
    {
        if (presentStateS1 == 0)
        {
            delay(100);
            if (presentStateS1 == 0 && count < 99)
            {
                count++;
                Serial.print("Count UP ");
                Serial.println(count);
                delay(200);
            }
            else
            {
                count = 0;
                Serial.print("Count UP ");
                Serial.println(count);
            }
        }
    }
    if (lastStateS2 == 1)
    {

        if (presentStateS2 == 0)
        {
            delay(100);
            if (presentStateS2 == 0 && count > 0)
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
    }
    lastStateS1 = presentStateS1;
    lastStateS2 = presentStateS2;
}