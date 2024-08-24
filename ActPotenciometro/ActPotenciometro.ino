//Programa elaborado por Antonio González A01285208

const int led=3;
int Vp=0;
int ValorF=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  Vp=analogRead(A0);
  ValorF=map(Vp,0,1023,0,255);
  analogWrite(led,ValorF);
  Serial.print("El valor del potenciometro es: ");
  Serial.println(ValorF);
  delay(1000);
}
