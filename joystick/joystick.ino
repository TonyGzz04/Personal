int VRx=0;
int VRy=0;
const int ledB=11;
const int ledA=10;
int vA=0;
int vB=0;
int sw=0;
int estado=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledB,OUTPUT);
  pinMode(ledA,OUTPUT);
  pinMode(2,INPUT_PULLUP);
  

}

void loop() {
  // put your main code here, to run repeatedly:

  sw=digitalRead(2);

  if (sw==LOW && estado==0)
  {
    estado=1;
    delay(500);
  }

  else if (sw==LOW && estado==1)
  {
    estado=0;
    delay(500);
  }

  if (estado==0)
  {
    analogWrite(ledA,0);
    analogWrite(ledB,0);
  }

  if (estado==1)
  {
  VRx=analogRead(A0);
  VRy=analogRead(A1);
  vA=map(VRx,0,1023,0,255);
  vB=map(VRy,0,1023,0,255);
  analogWrite(ledB,vB);
  analogWrite(ledA,vA);
  }

}
