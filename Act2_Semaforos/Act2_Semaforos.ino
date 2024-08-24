//Programa por Antonio González Rivera: A01285208

#define ledRojo1 2
#define ledAmarillo1 3
#define ledVerde1 4

#define ledVerde2 11
#define ledAmarillo2 12
#define ledRojo2 13


void setup() {
  // put your setup code here, to run once:
  pinMode(ledRojo1,OUTPUT);
  pinMode(ledAmarillo1,OUTPUT);
  pinMode(ledVerde1,OUTPUT);
  pinMode(ledRojo2,OUTPUT);
  pinMode(ledAmarillo2,OUTPUT);
  pinMode(ledVerde2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(ledRojo2,HIGH);
  
  digitalWrite(ledRojo1,LOW);   //empieza semáforo 1
  digitalWrite(ledVerde1,HIGH); 
  delay(2000);
  
  digitalWrite(ledVerde1,LOW);
  delay(300);
  digitalWrite(ledVerde1,HIGH);
  delay(300);
  digitalWrite(ledVerde1,LOW);
  delay(300);
  digitalWrite(ledVerde1,HIGH);
  delay(300);
  digitalWrite(ledVerde1,LOW);
  delay(300);
  digitalWrite(ledVerde1,HIGH);
  delay(300);
  
  digitalWrite(ledVerde1,LOW);
  digitalWrite(ledAmarillo1,HIGH);
  delay(2000);

  digitalWrite(ledAmarillo1,LOW);
  digitalWrite(ledRojo1,HIGH);  //termina semáforo 1




  digitalWrite(ledRojo2,LOW);  //empieza semáforo 2
  digitalWrite(ledVerde2,HIGH);
  delay(2000);
  
  digitalWrite(ledVerde2,LOW);
  delay(300);
  digitalWrite(ledVerde2,HIGH);
  delay(300);
  digitalWrite(ledVerde2,LOW);
  delay(300);
  digitalWrite(ledVerde2,HIGH);
  delay(300);
  digitalWrite(ledVerde2,LOW);
  delay(300);
  digitalWrite(ledVerde2,HIGH);
  delay(300);
  
  digitalWrite(ledVerde2,LOW);
  digitalWrite(ledAmarillo2,HIGH);
  delay(2000);

  digitalWrite(ledAmarillo2,LOW);   //termina semáforo 2 
}
