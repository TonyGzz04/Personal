#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int trigPin=9;
const int echoPin=10;
long duracion=0;
int distancia=0;
int ultima=0;

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  Serial.begin(9600);
  lcd.init();  //inicializa el display LCD lcd.begin(); 
  lcd.backlight(); //prende la iluminación posterior de la pantalla
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duracion=pulseIn(echoPin,HIGH); //Mide el tiempo entre Trig y el Echo
  distancia=(duracion/2)/29.1; //y calcula la distancia
  Serial.println(distancia);

  if (distancia != ultima)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Distancia: ");
    lcd.print(distancia);
    lcd.print(" cm");
    ultima=distancia;
  }

  delay(500);
}
