#include <SoftwareSerial.h>

SoftwareSerial miBT1(10,11);
SoftwareSerial miBT2(6,7);

char dato;            //variable que guardará el dato que manda el teléfono al módulo bluetooth
String mensaje;

void setup() {
  Serial.begin(9600);         //se inicializa la conexión con el monitor serie
  miBT1.begin(9600);           //se utiliza para poder usar el módulo bluetooth
  miBT2.begin(9600);           //se utiliza para poder usar el módulo bluetooth

}

void loop() {
  mensaje="";

  if (Serial.available()){        //si el monitor serie manda un dato
    miBT1.write(Serial.read());      //el BT lo manda al dispositivo que esté conectado a él por medio de bluetooth
  }

  while (miBT2.available()){   //mientras el BT reciba un dato:
    dato=miBT2.read();         //lee el dato
    mensaje=mensaje+dato;     //junta todos los caracteres
    Serial.println(mensaje);      //se imprime el mensaje en el monitor serie
  }

}
