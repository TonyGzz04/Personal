//Programa realizado por Antonio González Rivera A01285208

#include <SoftwareSerial.h>   //incluye librería 
 
SoftwareSerial miBT(0,1);   //pines del módulo bluetooth

const int ledVerde=6;     //pin del LED verde
const int ledAzul=12;   //pin del LED azul
char dato;            //variable que guardará el dato que manda el teléfono al módulo bluetooth
String mensaje;       //variable que junta los caracteres de la variable anterior

void setup() {
  Serial.begin(38400);         //se inicializa la conexión con el monitor serie
  Serial.println("Listo");      //mensaje en el monitor serie
  miBT.begin(38400);           //se utiliza para poder usar el módulo bluetooth
  pinMode(ledVerde,OUTPUT);   //se declara el LED verde como output
  pinMode(ledAzul,OUTPUT);    //se declara el LED azul como output
}

void loop() {

  mensaje="";                 //se "borra" el contenido de la variable mensaje
  while (miBT.available()){   //mientras el BT reciba un dato:
    dato=miBT.read();         //lee el dato
    mensaje=mensaje+dato;     //junta todos los caracteres
    Serial.println(mensaje);      //se imprime el mensaje en el monitor serie
  }
    
    if (dato=='v' || dato=='V'){      //si el dato es "v" o "V":
       digitalWrite(ledVerde,HIGH);     //se prende el LED verde
       digitalWrite(ledAzul,LOW);       //se apaga el LED azul
    }

    else if (dato=='d' || dato=='D'){      //o si el dato es "d" o "D":
       digitalWrite(ledAzul,HIGH);      //se prende el LED azul
       digitalWrite(ledVerde,LOW);      //se apaga el LED verde
    } 
  

  if (Serial.available()){        //si el monitor serie manda un dato
    miBT.write(Serial.read());      //el BT lo manda al dispositivo que esté conectado a él por medio de bluetooth
  }

}
