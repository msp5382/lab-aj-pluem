#define EncoderA 2
#define EncoderB 3
#define sw 13
int Pos = 0;
bool S1;
bool lastS1 = 1;

void readSw()
{
    S1 = digitalRead(sw);
}
int steps[4][4] = {{1,1,0,0},
                   {0,1,1,0},
                   {0,0,1,1},
                   {1,0,0,1}};


void runInStep (int _step){
  for(int c = 0; c <= _step;c++){
    for (int i = 0; i < 4;i++){
        digitalWrite(8, steps[i][0]);
        digitalWrite(9, steps[i][1]);
        digitalWrite(10, steps[i][2]);
        digitalWrite(11, steps[i][3]);
        delay(10);
    }
  }
    
} 

void runInBackStep (int _step){
  for(int c = 0; c <= _step;c++){
    for (int i = 0; i < 4;i++){
        digitalWrite(8, steps[i][3]);
        digitalWrite(9, steps[i][2]);
        digitalWrite(10, steps[i][1]);
        digitalWrite(11, steps[i][0]);
        delay(10);
    }
  }
    
} 

void setup()
{
    Serial.begin(9600);
    pinMode(sw, INPUT_PULLUP);
    pinMode(EncoderA, INPUT);
    pinMode(EncoderA, INPUT);
    attachInterrupt(0, EncoderEvent1, FALLING); //D2
    attachInterrupt(0, EncoderEvent2, FALLING); //D3
    for (int i = 8; i <= 11; i++)
    {
        pinMode(i, OUTPUT);
    }
}

void EncoderEvent1()
{
    if (digitalRead(EncoderA) == HIGH)
    {
        if (digitalRead(EncoderB) == LOW)
        {
            Pos = Pos + 1;
        }
        else
        {
            Pos = Pos - 1;
        }
    }
    else
    {
        if (digitalRead(EncoderB) == HIGH)
        {
            Pos = Pos + 1;
        }
        else
        {
            Pos = Pos - 1;
        }
    }
}

void EncoderEvent2()
{
    if (digitalRead(EncoderB) == HIGH)
    {
        if (digitalRead(EncoderA) == HIGH)
        {
            Pos = Pos + 1;
        }
        else
        {
            Pos = Pos - 1;
        }
    }
    else
    {
        if (digitalRead(EncoderA) == LOW)
        {
            Pos = Pos + 1;
        }
        else
        {
            Pos = Pos - 1;
        }
    }
}

void loop()
{
    readSw();
    if (S1 != lastS1)
    {
        delay(2);
        readSw();
        if (S1 == 0)
        {
            Serial.println('Gack');
            if(Pos > 0){
                runInStep(calcGack(Pos));
                Pos = 0;
            }else{
                runInBackStep(calcGack(abs(Pos)));
                Pos = 0;
            }
        }
        lastS1 = S1;
    }
    Serial.println(Pos);
}

int calcGack(float input) {
    float harn = input/20;
    return harn * 512;
}