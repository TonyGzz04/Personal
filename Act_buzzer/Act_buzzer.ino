const int pinBoton1=2;
const int pinBoton2=6;
const int pinBoton3=8;
const int pinBuzzer=13;
int stateButton1=0;
int stateButton2=0;
int stateButton3=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinBoton1,INPUT_PULLUP);
  pinMode(pinBoton2,INPUT_PULLUP);
  pinMode(pinBoton3,INPUT_PULLUP);

  pinMode(pinBuzzer,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  stateButton1=digitalRead(pinBoton1);
  stateButton2=digitalRead(pinBoton2);
  stateButton3=digitalRead(pinBoton3);

  if (stateButton1==LOW)
  {
    tone(pinBuzzer,554.37,100);
  }
  
  if (stateButton2==LOW)
  {
    tone(pinBuzzer,587.33,100);
  }

  if (stateButton3==LOW)
  {
    tone(pinBuzzer,622.25,100);
  }
}
