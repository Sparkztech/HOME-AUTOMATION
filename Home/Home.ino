#define IR_BELL               2
#define BELL                  3
#define IR_TLESS              4
#define Relay_TLess           5
#define Relay_Bluetooth_Light 6


int bell_value = 1, Tless_value = 1;
void setup()
{
  Serial.begin(9600);
  pinMode(IR_BELL, INPUT);
  pinMode(IR_TLESS, INPUT);
  pinMode(BELL, OUTPUT);
  pinMode(Relay_TLess, OUTPUT);
  pinMode(Relay_Bluetooth_Light, OUTPUT);
  digitalWrite(Relay_Bluetooth_Light, HIGH);
  digitalWrite(Relay_TLess, HIGH);
}
void loop()
{
  //  TOUCH_LESS BELL
  Bell();
  //  TOUCH LESS LIGHT
  TLess();
  // Bluetooth
  Bluetooth();


}

void Bell()
{
  //  Serial.println(digitalRead(IR_BELL));
  while (digitalRead(IR_BELL) == 0)
  {
    //    Serial.println(digitalRead(IR_BELL));
    bell_value = 0;
  }
  if (bell_value == 0)
  {
    tone(BELL, 2000);
    delay(3000);
    noTone(BELL);
    bell_value = 1;
  }
}

void TLess()
{
//  Serial.println(digitalRead(IR_TLESS));
  while (digitalRead(IR_TLESS) == 0)
  {
    Serial.println(digitalRead(IR_TLESS));
    Tless_value = 0;
  }
  
  if (Tless_value == 0)
  {
    if (digitalRead(Relay_TLess) == HIGH)
    {
      digitalWrite(Relay_TLess, LOW);
      delay(900);
    }
    else if (digitalRead(Relay_TLess) == LOW)
    {
      digitalWrite(Relay_TLess, HIGH);
      delay(900);
    }
    Tless_value = 1;
  }
}

void Bluetooth()
{
  char Data = '0';
  while (Serial.available() > 0)
  {
    Data = Serial.read();
    Serial.println(Data);
    if (Data == 'A')
    {
      digitalWrite(Relay_Bluetooth_Light, LOW);
    }
    if (Data == 'a')
    {
      digitalWrite(Relay_Bluetooth_Light, HIGH);
    }
  }
}
