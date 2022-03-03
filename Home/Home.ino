#define relay1 5
#define relay2 6
#define relay3 7
#define Ir1    A0
#define Ir2    A1
#define Touch  8
#define Buzzer 9
int touch_Value = 0, IR1 = 0, IR2 = 0;
void setup()
{
  pinMode(Touch, INPUT_PULLUP);
  pinMode(Buzzer, OUTPUT);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(Ir1, INPUT);
  pinMode(Ir2, INPUT);
  Serial.begin(9600);
}
void loop()
{
  //  Touch Btn
  //  Serial.println(digitalRead(Touch));//Touch Value
  while (digitalRead(Touch) == 1)
  {
    touch_Value = 1;

  }
  if (touch_Value == 1)
  {
    if (digitalRead(relay1) == 1)
    {
      digitalWrite(relay1, LOW);
    }
    else
    {
      digitalWrite(relay1, HIGH);
    }
    touch_Value = 0;
  }

//Touch Less Door Bell
//  Serial.println(digitalRead(Ir2));//IR
//  Serial.println(digitalRead(Ir1));//IR
  while (digitalRead(Ir1) == 0)
  {
    IR1 = 1;
  }
  while (digitalRead(Ir2) == 0)
  {
    IR2 = 1;
  }
  if (IR1 == 1 || IR2 == 1)
  {
    tone(Buzzer,2000);
    delay(3000);
    noTone(Buzzer);
     IR1 = 0;
     IR2 = 0;
  }
  char Data='0';
  while(Serial.available()>0)
  {
    Data = Serial.read();
    Serial.print(Data);
    if(Data == 'A')
    {digitalWrite(relay1,LOW);}
    if(Data == 'a')
    {digitalWrite(relay1,HIGH);}
  }
}
