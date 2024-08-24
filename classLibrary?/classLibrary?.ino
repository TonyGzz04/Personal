#ifndef classTry_h
#define classTry_h 
#include "Arduino.h"

class myclass {

  public:
    myclass(int pin);
    void function(int pwm);
  
  private:
    int _pin;

};

#endif
