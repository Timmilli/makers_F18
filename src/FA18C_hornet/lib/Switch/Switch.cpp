#include "Switch.hpp"
#include "SwitchController.hpp"

Switch::Switch(SwitchController &pcf, unsigned int pin)
    : _pcf(pcf), _pin(pin) {}

unsigned int Switch::readState() { return _pcf.getState(_pin); }
