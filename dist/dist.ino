const int trigPin=9;
const int echoPin=10;
long duracion=0;
float distancia=0;
float ultima=0;

void setup() {
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duracion=pulseIn(echoPin,HIGH); //Mide el tiempo entre Trig y el Echo
  distancia=(duracion/2)/29.1; //y calcula la distancia
  Serial.println(distancia);
delay(1000);

}
