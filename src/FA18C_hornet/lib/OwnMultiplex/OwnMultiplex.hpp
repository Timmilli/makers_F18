#ifndef __OWNMULTIPLEX_HPP__
#define __OWNMULTIPLEX_HPP__

#include "Arduino.h"
#include "OwnPCF.hpp"

class OwnMultiplex {
private:
  OwnPCF *_oPCF;
  // Most, mid and least significant bits
  unsigned int _msb, _midsb, _lsb;
  byte _pin_enable;
  byte _pin_read;
  float _states[8];

public:
  OwnMultiplex(OwnPCF *oPCF, unsigned int MSBit_pin, unsigned int midBit_pin,
               unsigned int LSBit_pin, byte pin_enable, byte pin_read);
  void startMultiplex(); // TODO check cuz not sure if this is to be kept
  void update();
  int getState(unsigned int index);
};

#endif // include guard