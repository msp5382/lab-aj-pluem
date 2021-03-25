#define sw1 D1
#define sw2 D2

int LED[] = {D0, D3, D4, D5, D6, D7};
int count=0;
void setup()
{
  pinMode(LED[0], OUTPUT);
  pinMode(LED[1], OUTPUT);
  pinMode(LED[2], OUTPUT);
  pinMode(LED[3], OUTPUT);
  pinMode(LED[4], OUTPUT);
  pinMode(LED[5], OUTPUT);
  pinMode(D1, INPUT_PULLUP);
  pinMode(D2, INPUT_PULLUP);
}

bool readSw(int sw){
    bool state = digitalRead(sw);
    return state;
}
void countUp(){
    if(readSwUp(sw1)){
        delay(50);
        if(readSwUp(sw1)){
            if(count<=6){
                count++;
            }
            else{
                count = 0;
                for (int i=1;i <=6,i++)
                {
                    digitalWrite(LED[i-1],LOW);
                }
            }
        }
    }
}

void countDown(){
    if(readSw(sw2)){
        delay(50);
        if(readSw(sw2)){
            if(count>=0){
                count--;
            }
            else{
                count = 6;
                for (int i = 1; i <= 6; i++)
                {
                    digitalWrite(LED[i-1],LOW);
                }
                for (int i = 1; i <= 6; i++)
                {
                    digitalWrite(LED[i-1],LOW);
                }
            }
        }
    }
}
void loop()
{
    countUp();
    countDown();
    digitalWrite(LED[count - 1], HIGH);
}
