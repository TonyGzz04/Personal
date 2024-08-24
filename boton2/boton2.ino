//Programa realizado por Antonio González Rivera: A01285208

int button1=0;
int pinBoton=8;
int led1=12;
int led2=11;

void setup() {
  // put your setup code here, to run once:
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  
  pinMode(pinBoton,INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  button1=digitalRead(pinBoton);

  if (button1==LOW)
  {
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
  }
  
  else
  {
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
  }
}
