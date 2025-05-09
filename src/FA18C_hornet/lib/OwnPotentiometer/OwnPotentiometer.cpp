#include "OwnPotentiometer.hpp"

OwnPotentiometer::OwnPotentiometer(OwnMultiplex *oMul, const char *msg,
                                   char pin, char *name, bool reverse,
                                   unsigned int input_min,
                                   unsigned int input_max)
    : _oMul(oMul), _pin(pin) {
  strncpy(_name, name, MAX_NAME_LENGTH);
  char lastState = _oMul->getState(_pin);
  setAttributes(msg, lastState, reverse, input_min, input_max);
}

unsigned int OwnPotentiometer::readState() { return _oMul->getState(_pin); }

char *OwnPotentiometer::getName() { return _name; }