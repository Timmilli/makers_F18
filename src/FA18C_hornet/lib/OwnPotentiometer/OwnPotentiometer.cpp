#include "OwnPotentiometer.hpp"

OwnPotentiometer::OwnPotentiometer(OwnMultiplex *oMul, const char *msg,
                                   char pin, const char *name, bool reverse,
                                   unsigned int input_min,
                                   unsigned int input_max)
    : _oMul(oMul), _pin(pin) {}

unsigned int OwnPotentiometer::readState() { return _oMul->getState(_pin); }

char *OwnPotentiometer::getName() { return _name; }