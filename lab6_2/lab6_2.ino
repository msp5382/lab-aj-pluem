#include <Keypad.h>
#include <LiquidCrystal_I2C.h> // ประกาศ Library
// ตั้งค่า Module IIC/I2C(add,row,coloum)
LiquidCrystal_I2C lcd(0x27, 16, 2); // บางรุ่นอาจจะใช้ 0x3F
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'},
};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup()
{
    Serial.begin(9600);
    lcd.init();      // ใช้หน้าจอ LCD
    lcd.backlight(); // เปิด backlight
}

bool isNum(char test)
{
    if (test == '1' || test == '2' || test == '3' || test == '4' || test == '5' || test == '6' || test == '7' || test == '8' || test == '9' || test == '0')
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isOprator(char test)
{
    if (test == 'A' || test == 'B' || test == 'C' || test == 'D')
    {
        return true;
    }
    else
    {
        return false;
    }
}

float calculate(String _expression)
{
    char expressionArr[15];
    _expression.toCharArray(expressionArr, 15);
    String numberBuffer[7];
    char opBuffer[7];
    int countnum = 0;
    int countop = 0;
    for (int i = 0; i < 15; i++)
    {
        if (expressionArr[i] == '+')
        {
            countnum++;
            countop++;
            opBuffer[countop] = '+';
        }
        else if (expressionArr[i] == '-')
        {
            countnum++;
            countop++;
            opBuffer[countop] = '-';
        }
        else if (expressionArr[i] == 'x')
        {
            countnum++;
            countop++;
            opBuffer[countop] = 'x';
        }
        else if (expressionArr[i] == '/')
        {
            countnum++;
            countop++;
            opBuffer[countop] = '/';
        }
        else
        {
            numberBuffer[countnum] += expressionArr[i];
        }
    }
    float currentANS = 0;
    for (int i = 0; i <= countnum; i++)
    {
        Serial.print("i ");
        Serial.println(i);

        Serial.println(opBuffer[i]);
        Serial.println(numberBuffer[i].toInt());
        if (i == 0)
        {
            currentANS = float(numberBuffer[i].toInt());
        }
        else
        {

            if (opBuffer[i] == '+')
            {
                currentANS = currentANS + float(numberBuffer[i].toInt());
                Serial.println("here");
            }
            else if (opBuffer[i] == '-')
            {
                currentANS = currentANS - float(numberBuffer[i].toInt());
            }
            else if (opBuffer[i] == 'x')
            {
                currentANS = currentANS * float(numberBuffer[i].toInt());
            }
            else if (opBuffer[i] == '/')
            {
                currentANS = currentANS / float(numberBuffer[i].toInt());
            }
            else
            {
                currentANS = currentANS;
            }
        }
        Serial.print("cans ");
        Serial.println(currentANS);
    }
    Serial.print("ans  ");
    Serial.println(currentANS);

    return currentANS;
}

char displayOprator(char op)
{
    switch (op)
    {
    case 'A':
        return '+';
        break;
    case 'B':
        return '-';
        break;
    case 'C':
        return 'x';
        break;
    case 'D':
        return '/';
        break;
    }
}

String currentStr = "";
String lastAns = '';
void loop()
{
    char key = keypad.getKey();
    if (key != NO_KEY)
    {
        Serial.println(key);
        if (isNum(key))
        {
            currentStr += key;
            lcd.setCursor(0, 0);
            lcd.print("               ");
            lcd.setCursor(0, 0);
            lcd.print(currentStr);
        }
        else if (isOprator(key))
        {
            currentStr += displayOprator(key);
            if(lastAns != ""){
                currentStr += lastAns
            }
            lcd.setCursor(0, 0);
            lcd.print("               ");
            lcd.setCursor(0, 0);
            lcd.print(currentStr);
        }
        else if (key == '#')
        {
            Serial.println(currentStr);
            Serial.println(calculate(currentStr));
            lcd.setCursor(0, 1);
            lcd.print("               ");
            lcd.setCursor(0, 1);
            lastAns = String(calculate(currentStr));
            lcd.print("= " + String(calculate(currentStr)));
        }
        else if (key == '*')
        {
            currentStr = "";
            lcd.setCursor(0, 0);
            lcd.print("               ");
            lcd.setCursor(0, 1);
lcd.print("                 ");
lastAns = "";
        }
    }
}
