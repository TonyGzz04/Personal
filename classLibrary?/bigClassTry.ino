#include "Arduino.h"
#include "classTry.h"

myclass::myclass(int pin){
  pinMode(pin,OUTPUT);
  _pin = pin;
}

void myclass::function(int pwm){
  
}