//Programa realizado por Antonio González Rivera: A01285208

int button1=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(12,OUTPUT);
  
  pinMode(10,INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  button1=digitalRead(10);
  Serial.println(button1);

  if (button1==LOW)
  {
    digitalWrite(12,HIGH);
  }
  
  else
  {  
    digitalWrite(12,LOW);
  }
}
