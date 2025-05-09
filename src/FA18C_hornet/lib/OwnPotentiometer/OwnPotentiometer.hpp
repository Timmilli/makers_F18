#ifndef __OWNPOTENTIOMETER_HPP__
#define __OWNPOTENTIOMETER_HPP__

#define DCSBIOS_DEFAULT_SERIAL
#include "DcsBios.h"

#include "Constants.h"
#include "OwnMultiplex.hpp"

class OwnPotentiometer : public DcsBios::Potentiometer {
private:
  OwnMultiplex *_oMul;
  unsigned int _pin;
  char _name[MAX_NAME_LENGTH];

public:
  OwnPotentiometer(OwnMultiplex *oMul, const char *msg, char pin, char *name,
                   bool reverse = false, unsigned int input_min = 0,
                   unsigned int input_max = 1023);
  unsigned int readState();
  char *getName();
};

#endif // include guard