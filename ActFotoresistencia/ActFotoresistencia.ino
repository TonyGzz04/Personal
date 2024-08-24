//Programa elaborado por Antonio González Rivera A01285208

#define buzzer 2
#define ledRojo 3
#define ledAmarillo 4
#define ledVerde 5
#define fotor A2

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer,OUTPUT);
  pinMode(ledRojo,OUTPUT);
  pinMode(ledAmarillo,OUTPUT);
  pinMode(ledVerde,OUTPUT);

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i=2; i<6; i++)
  {
    digitalWrite(i,LOW);
  }
  
  status_Indicator();
}

void status_Indicator()
{
  int ValorF=analogRead(fotor);
  Serial.print("El valor de la fotorresistencia es ");
  Serial.println(ValorF);

  if (ValorF>=1000)
  {
    digitalWrite(ledRojo,HIGH);
    tone(buzzer,400,100);
  }

  else if (ValorF>=900 && ValorF<1000)
  {
    digitalWrite(ledAmarillo,HIGH);
  }

  else if (ValorF<900)
  {
    digitalWrite(ledVerde,HIGH);
  }

  delay(1000);
}
