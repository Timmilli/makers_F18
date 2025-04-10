#include "Switches.h"
#include "OwnPCF.h"

Switches::Switches(OwnPCF &pcf, unsigned int pin) : _pcf(pcf), _pin(pin) {}

unsigned int Switches::readState() { return _pcf.getState(_pin); }
