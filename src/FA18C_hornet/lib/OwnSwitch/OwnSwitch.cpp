#include "OwnSwitch.hpp"
#include "OwnPCF.hpp"

char switchCase(char stateA, char stateB) {
  if (stateA == 1)
    return 1;
  if (stateB == 1)
    return 2;
  return 0;
}

char findHighPin() {
  if (digitalRead(FST_COMPLEX_READ_PIN) == HIGH)
    return 0;
  else if (digitalRead(SCND_COMPLEX_READ_PIN) == HIGH)
    return 1;
  else if (digitalRead(THRD_COMPLEX_READ_PIN) == HIGH)
    return 2;
  else if (digitalRead(FRTH_COMPLEX_READ_PIN) == HIGH)
    return 3;
  else if (digitalRead(FFTH_COMPLEX_READ_PIN) == HIGH)
    return 4;
  else if (digitalRead(SXTH_COMPLEX_READ_PIN) == HIGH)
    return 5;
  else if (digitalRead(SVTH_COMPLEX_READ_PIN) == HIGH)
    return 6;
  else if (digitalRead(EGTH_COMPLEX_READ_PIN) == HIGH)
    return 7;
  return 8;
}

OwnSwitch2Pos::OwnSwitch2Pos(OwnPCF *pcf, unsigned int pin, const char *name,
                             const char *msg, bool reverse,
                             unsigned long debounceDelay)
    : _oPCF(pcf), _pin(pin), _lastState(0) {
  strncpy(_name, name, MAX_NAME_LENGTH);
  _oPCF->activatePin(_pin);
  char lastState = digitalRead(FST_SIMPLE_READ_PIN);
  _oPCF->deactivatePin(_pin);
  setAttributes(msg, lastState, reverse, debounceDelay);
}

char OwnSwitch2Pos::readState() { return _lastState; }
void OwnSwitch2Pos::update() {
  _oPCF->activatePin(_pin);
  _lastState = digitalRead(FST_SIMPLE_READ_PIN);
  _oPCF->deactivatePin(_pin);
}
char *OwnSwitch2Pos::getName() { return _name; }

OwnSwitch3Pos::OwnSwitch3Pos(OwnPCF *pcf, unsigned int pin, const char *name,
                             const char *msg, unsigned long debounceDelay)
    : _oPCF(pcf), _pin(pin), _lastState(0) {
  strncpy(_name, name, MAX_NAME_LENGTH);
  _oPCF->activatePin(_pin);
  char lastState = switchCase(digitalRead(FST_SIMPLE_READ_PIN),
                              digitalRead(SCND_SIMPLE_READ_PIN));
  _oPCF->deactivatePin(_pin);

  setAttributes(msg, lastState, debounceDelay);
}

char OwnSwitch3Pos::readState() { return _lastState; }
void OwnSwitch3Pos::update() {
  _oPCF->activatePin(_pin);
  _lastState = switchCase(digitalRead(FST_SIMPLE_READ_PIN),
                          digitalRead(SCND_SIMPLE_READ_PIN));
  _oPCF->deactivatePin(_pin);
}
char *OwnSwitch3Pos::getName() { return _name; }

OwnSwitchMultiPos::OwnSwitchMultiPos(OwnPCF *oPCF, unsigned int pin,
                                     const char *msg, const char *name,
                                     bool reverse)
    : _oPCF(oPCF), _pin(pin), _lastState(0) {
  setAttributes(msg, reverse);
}

char OwnSwitchMultiPos::readState() { return _lastState; }

void OwnSwitchMultiPos::update() {
  _oPCF->activatePin(_pin);
  _lastState = findHighPin();
  _oPCF->deactivatePin(_pin);
}
char *OwnSwitchMultiPos::getName() { return _name; }
