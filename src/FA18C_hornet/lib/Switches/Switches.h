#ifndef __SWITCHES_H__
#define __SWITCHES_H__

#include "OwnPCF.h"
#include <Arduino.h>

class Switches {
private:
  OwnPCF &_pcf;
  unsigned int _pin;

public:
  Switches(OwnPCF &pcf, unsigned int pin);
  unsigned int readState();
};

#endif // __SWITCHES_H__
