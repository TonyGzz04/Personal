//Programa realizado por Antonio González Rivera A01285208

#include <AFMotor.h>      //librería
#include <SoftwareSerial.h>     //librería
SoftwareSerial miBT(9,10);    //pines a los que está conectado el BT

AF_DCMotor motorUno(1);     //se declara el pin al que está conectado el motor 1
AF_DCMotor motorDos(2);     //se declara el pin al que está conectado el motor 2

char dato;    //variable que es el dato que manda el celular

void setup() {
  miBT.begin(9600);     //para poder usar el BT
  Serial.begin(9600);     //se inicia la conexión con el monitor serie
  Serial.println("Listo");      //mensaje en el monitor serie

  motorUno.setSpeed(250);     //velocidad máxima del motor 1
  motorDos.setSpeed(250);   //velocidad máxima del motor 2
}

void loop() {
    if (miBT.available()){      //si el celular manda un mensaje:
      dato=miBT.read();     //dato se iguala al dato mandado
      Serial.print(dato);     //se imprime el dato en el monitor serie
      
      if (dato=='a'){   //si el dato es a: 
        adelante();     //el carro se mueve hacia adelante
      }

      else if (dato=='b'){    //si el dato es b: 
        reversa();          //el carro se mueve hacia atrás
      }     

      else if (dato=='d'){    //si el dato es d: 
        derecha();        //el carro se mueve hacia la derecha
      }

      else if (dato=='i'){    //si el dato es i: 
        izquierda();        //el carro se mueve hacia la izquierda
      }

      else if (dato=='s'){    //si el dato es s: 
        alto();           //el carro se para
      } 

      
    }
}

void adelante(){        //función
  motorUno.run(FORWARD);    //motor 1 hacia adelante
  motorDos.run(FORWARD);   //motor 2 hacia adelante
  }

void reversa(){         //función
  motorUno.run(BACKWARD);   //motor 1 hacia atrás
  motorDos.run(BACKWARD);      //motor 2 hacia atrás
  }


void derecha(){         //función
  motorUno.run(FORWARD);    //motor 1 hacia adelante
  motorDos.run(BACKWARD);      //motor 2 hacia atrás
  }

  void izquierda(){       //función
  motorUno.run(BACKWARD);   //motor 1 hacia atrás
  motorDos.run(FORWARD);   //motor 2 hacia adelante
  }

  void alto (){       //función
  motorUno.run(RELEASE);      //motor 1 se para
  motorDos.run(RELEASE);    //motor 2 se para
  }
