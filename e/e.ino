//Programa realizado por Antonio González Rivera A01285208

#include <AFMotor.h>      //librería
#include <Servo.h>        //librería
#include <NewPing.h>        //librería
#include <SoftwareSerial.h>     //librería
SoftwareSerial miBT(9,10);    //pines a los que está conectado el BT

AF_DCMotor motorUno(1);     //se declara el pin al que está conectado el motor 1
AF_DCMotor motorDos(2);     //se declara el pin al que está conectado el motor 2
AF_DCMotor motorTres(3);      //se declara el pin al que está conectado el motor 3
AF_DCMotor motorCuatro(4);   //se declara el pin al que está conectado el motor 4

NewPing Dist(A0,A1,200);
Servo servo;

short distancia=0;
short distanciaD=0;
short distanciaI=0;
char dato;    //variable que es el dato que manda el celular
byte x;



void setup() {
  miBT.begin(9600);     //para poder usar el BT
  Serial.begin(9600);     //se inicia la conexión con el monitor serie
  Serial.println("Listo");      //mensaje en el monitor serie

  servo.attach(10);

  motorUno.setSpeed(250);     //velocidad máxima del motor 1
  motorDos.setSpeed(250);   //velocidad máxima del motor 2
  motorTres.setSpeed(250);      //velocidad máxima del motor 3
  motorCuatro.setSpeed(250);      //velocidad máxima del motor 4
}

void loop() {
          
          distancia=medirDistancia();
          
          if (distancia>50 && distancia<=250){
            adelante();
          }

          else {
            servo.write(45);
          delay(1000);
          distanciaD=medirDistancia();
          servo.write(135);
          delay(1000);
          distanciaI=medirDistancia();
          servo.write(90);
          delay(300);

            if (distanciaD >= distanciaI){
              derecha();
              delay(2500);
            }
            
            else{
              izquierda();
              delay(2500);
            }
            
          }
}

void adelante(){        //función
  motorUno.run(FORWARD);    //motor 1 hacia adelante
  motorDos.run(BACKWARD);   //motor 2 hacia adelante
  motorTres.run(FORWARD);     //motor 3 hacia atrás
  motorCuatro.run(BACKWARD);      //motor 4 hacia atrás
  }

void reversa(){         //función
  motorUno.run(BACKWARD);   //motor 1 hacia atrás
  motorDos.run(FORWARD);      //motor 2 hacia atrás
  motorTres.run(BACKWARD);        //motor 3 hacia atrás 
  motorCuatro.run(FORWARD);     //motor 4 hacia atrás
  }


void derecha(){         //función
  motorUno.run(FORWARD);    //motor 1 hacia adelante
  motorDos.run(RELEASE);      //motor 2 hacia atrás
  motorTres.run(FORWARD);       //motor 3 hacia adelante 
  motorCuatro.run(RELEASE);     //motor 4 hacia atrás
  }

  void izquierda(){       //función
  motorUno.run(RELEASE);   //motor 1 hacia atrás
  motorDos.run(BACKWARD);   //motor 2 hacia adelante
  motorTres.run(BACKWARD);    //motor 3 hacia atrás
  motorCuatro.run(RELEASE);  //motor 4 hacia adelante
  }

  void alto (){       //función
  motorUno.run(RELEASE);      //motor 1 se para
  motorDos.run(RELEASE);    //motor 2 se para
  motorTres.run(RELEASE);   //motor 3 se para
  motorCuatro.run(RELEASE);}    //motor 4 se para


  int medirDistancia(){
    delay(70);
    distancia = Dist.ping_cm();
    return distancia;
  }
