#ifndef __SWITCH_H__
#define __SWITCH_H__

#include "OnePCF.hpp"
#include <Arduino.h>

class Switch {
private:
  OnePCF &_pcf;
  unsigned int _pin;

public:
  Switch(OnePCF &pcf, unsigned int pin);
  unsigned int readState();
};

#endif // __SWITCH_H__
