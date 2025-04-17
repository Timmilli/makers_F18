#ifndef __SWITCH_HPP__
#define __SWITCH_HPP__

#include "SwitchController.hpp"
#include <Arduino.h>

class Switch {
private:
  SwitchController &_pcf;
  unsigned int _pin;

public:
  Switch(SwitchController &pcf, unsigned int pin);
  unsigned int readState();
};

#endif // __SWITCH_HPP__
