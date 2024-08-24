//Programa realizado por Antonio González Rivera: A01285208

int button1=0;
int button2=0;
const int pinBoton1=7;
const int pinBoton2=8;
const int led1=11;
const int led2=12;

void setup() {
  // put your setup code here, to run once:
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  
  pinMode(pinBoton1,INPUT_PULLUP);
  pinMode(pinBoton2,INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  button1=digitalRead(pinBoton1);
  button2=digitalRead(pinBoton2);

  if (button1==LOW)
  {
    digitalWrite(led1,HIGH);
  }
  
    else if (button1==HIGH)
  {
    digitalWrite(led1,LOW);
  }

  
  if (button2==LOW)
  {
    digitalWrite(led2,HIGH);
  }
  
  else if (button2==HIGH)
  {
    digitalWrite(led2,LOW);
  }
}
