#ifndef __OWNPOTENTIOMETER_HPP__
#define __OWNPOTENTIOMETER_HPP__

#include "Constants.h"
#include "OwnMultiplex.hpp"

class OwnPotentiometer {
private:
  OwnMultiplex *_oMul;
  unsigned int _pin;
  char _name[MAX_NAME_LENGTH];

public:
  OwnPotentiometer(OwnMultiplex *oMul, const char *msg, char pin,
                   const char *name, bool reverse, unsigned int input_min,
                   unsigned int input_max);
  unsigned int readState();
  char *getName();
};

#endif // include guard