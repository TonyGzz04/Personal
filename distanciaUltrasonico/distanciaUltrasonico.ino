const int trig=9;
const int echo=10;

void setup() {
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);

}

void loop() {
    digitalWrite(trig,LOW);
    delayMicroseconds(2);
    digitalWrite(trig,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig,LOW);
    int duracion=pulseIn(echo,HIGH);
    float distancia=(duracion/2)/29.1;

    Serial.print("Distancia ");
    Serial.print(" : ");
    Serial.println(distancia);

}
