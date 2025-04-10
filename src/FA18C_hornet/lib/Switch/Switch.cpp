#include "Switch.hpp"
#include "OnePCF.hpp"

Switch::Switch(OnePCF &pcf, unsigned int pin) : _pcf(pcf), _pin(pin) {}

unsigned int Switch::readState() { return _pcf.getState(_pin); }
