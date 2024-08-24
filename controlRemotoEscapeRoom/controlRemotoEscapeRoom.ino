#include <LiquidCrystal_I2C.h>
#include <IRremote.hpp>

byte RECV_PIN=11;
byte valor=0;
byte y=0;
byte x=0;
byte a=0;
byte b=0;

IRrecv irrecv(11);
decode_results results;

LiquidCrystal_I2C lcd(0x27,16,2);

void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn(); 
  lcd.init();
  lcd.backlight();
}

int numero(){
      switch (results.value){
        case 0xFFA25D:
            valor=1;
          break;
        case 0xFF629D:
            valor=2;
          break;
        case 0xFFE21D:
            valor=3;
          break;
        case 0xFF22DD:
            valor=4;
          break;
        case 0xFF02FD:
            valor=5;
          break;
        case 0xFFC23D:
            valor=6;
          break;
        case 0xFFE01F:
            valor=7;
          break;
        case 0xFFA857:
            valor=8;
          break;
        case 0xFF906F:
            valor=9;
          break;
        case 0xFF9867:
            valor=0;
          break;
        case 0xFFFFFF:
          break;
      }
      return valor;
}

void loop(){

delay(200);

if (!(irrecv.decode(&results))){
  lcd.clear();
  lcd.print("Contrasena");
}

y=0;
x=0;
a=0;
b=0;
  
  while (y==0){ //primer while
    if (irrecv.decode(&results)){ //primer if
     numero(); 
      if (valor==0){ //primer if interno
       lcd.clear();
       lcd.print(valor);
       delay(200);
       irrecv.resume();
       
        while (x==0){ //segundo while
         if (irrecv.decode(&results)){ //segundo if
          numero();
           if (valor==1){ //segundo if interno
            lcd.print(valor);
            delay(200);
            irrecv.resume();
            
              while (a==0){ //tercer while
                if (irrecv.decode(&results)){ //tercer if
                  numero();
                   if (valor==2){ //tercer if interno
                    lcd.print(valor);
                    delay(200);
                    irrecv.resume();
                    lcd.clear();
                    lcd.print("felicidades");

                       while (b==0){ //cuarto while
                         if (irrecv.decode(&results)){ //cuarto if
                           numero();
                            if (valor==9){ //cuarto if interno
                              x=1;
                              y=1;
                              a=1;
                              b=1;
                    } //cierra cuarto if interno


            
                   }
                   
            } //cierra primer if interno
                   }

      else { //del segundo if interno
        lcd.clear();
        lcd.print("Error");
        delay(1000);
        irrecv.resume();
        y=1;
        x=1;
        a=1;
      }

                }
              }
           }
      
      else { //del primer if interno
        lcd.clear();
        lcd.print("Error");
        delay(1000);
        irrecv.resume();
        y=1;
        x=1;
      } //cierra else del primer if interno
    
         }
        }
      }
            else { //del tercer if interno
              lcd.clear();
              lcd.print("Error");
              delay(1000);
              irrecv.resume();
              y=1;
            } //cierra else del tercer if interno
          
        } //cierra tercer if

      delay(200);
       } //cierra tercer while

     } //cierra segundo while



     MANADAAAAA
