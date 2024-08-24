//Programa realizado por Antonio González Rivera A01285208

#include <Servo.h> 

const int pir=10;
const int pinServo=9;
int valorPIR=0;
int pos=0;
const int p1=".";
const int p2="..";
const int p3="...";
int cero[22]={0,3,6,9,12,15,18,21,24,27,30,33,36,39,42,45,48,51,54,57};
int uno[22]={1,4,7,10,13,16,19,22,25,28,31,34,37,40,43,46,49,52,55,58};
int dos[22]={2,5,8,11,14,17,20,23,26,29,32,35,38,41,44,47,50,53,56,59};
Servo servo;

void setup() {
  // put your setup code here, to run once:
  pinMode(pir,INPUT);
  servo.attach(pinServo);
  servo.write(0);
  Serial.begin(9600);
  
  for (int i=0; i<60; i++)
  {
    
    if (i==cero[22])
    {
      Serial.println("Calibrando el sensor PIR.");
    }

    else if (i==uno[22])
    {
      Serial.println("Calibrando el sensor PIR..");
    }

    else if (i==dos[22])
    {
      Serial.println("Calibrando el sensor PIR...");
    }
    
  delay(1000);
  }
  
  Serial.println("Calibración terminada");
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  valorPIR=digitalRead(pir);

  if (valorPIR==HIGH)
  {
    pos=45;
    Serial.println("¡Adelante!");
    Serial.print("Posición del Servo = ");
    Serial.println(pos);
    servo.write(pos);
  }

  else
  {
    pos=90;
    Serial.println("Falso");
    Serial.print("Posición del Servo = ");
    Serial.println(pos);
    servo.write(pos);
  }
}
