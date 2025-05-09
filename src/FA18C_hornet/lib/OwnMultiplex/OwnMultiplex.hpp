#ifndef __OWNMULTIPLEX_HPP__
#define __OWNMULTIPLEX_HPP__

#include "Arduino.h"

class OwnMultiplex {
private:
  byte _pin_A;
  byte _pin_B;
  byte _pin_C;
  byte _pin_enable;
  byte _pin_read;
  int _states[8];

public:
  OwnMultiplex(byte addr_A, byte addr_B, byte addr_C, byte pin_enable,
               byte pin_read);
  void startMultiplex();
  void update();
  int getState(unsigned int index);
};

#endif // include guard