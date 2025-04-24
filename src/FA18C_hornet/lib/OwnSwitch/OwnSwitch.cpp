#include "OwnSwitch.hpp"
#include "OwnPCF.hpp"

char switchCase(char stateA, char stateB) {
  if (stateA == 1)
    return 1;
  if (stateB == 1)
    return 2;
  return 0;
}

OwnSwitch2Pos::OwnSwitch2Pos(OwnPCF *pcf, unsigned int pin, const char *name,
                             const char *msg, bool reverse,
                             unsigned long debounceDelay)
    : _oPCF(pcf), _pin(pin) {
  strncpy(_name, name, MAX_NAME_LENGTH);
  char lastState = _oPCF->getState(_pin);
  setAttributes(msg, lastState, reverse, debounceDelay);
}

char OwnSwitch2Pos::readState() { return _oPCF->getState(_pin); }
char *OwnSwitch2Pos::getName() { return _name; }

OwnSwitch3Pos::OwnSwitch3Pos(OwnPCF *pcf, unsigned int pinA, unsigned int pinB,
                             const char *name, const char *msg,
                             unsigned long debounceDelay)
    : _oPCF(pcf), _pinA(pinA), _pinB(pinB) {
  strncpy(_name, name, MAX_NAME_LENGTH);
  char lastState = switchCase(_oPCF->getState(_pinA), _oPCF->getState(_pinB));
  setAttributes(msg, lastState, debounceDelay);
}

char OwnSwitch3Pos::readState() {
  return switchCase(_oPCF->getState(_pinA), _oPCF->getState(_pinB));
}
char *OwnSwitch3Pos::getName() { return _name; }