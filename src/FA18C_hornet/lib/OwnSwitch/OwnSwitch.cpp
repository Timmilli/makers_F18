#include "OwnSwitch.hpp"
#include "OwnPCF.hpp"

int switchCase(char stateA, char stateB) {
  if (stateA == 1)
    return 1;
  if (stateB == 1)
    return 2;
  return 0;
}

int findHighPin() {
  if (digitalRead(FRST_COMPLEX_READ_PIN) == HIGH)
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
    : _oPCF(pcf), _pin(pin), _lastState(0) {}

int OwnSwitch2Pos::readState() { return _lastState; }
void OwnSwitch2Pos::update() {
  _oPCF->activatePin(_pin);
  int newState = digitalRead(FST_SIMPLE_READ_PIN);
  delay(10);
  _oPCF->deactivatePin(_pin);
  if (newState != _lastState) {
    Serial.print("from: ");
    Serial.print(_lastState);
    Serial.print("; to: ");
    Serial.println(newState);
    _lastState = newState;
  }
}
char *OwnSwitch2Pos::getName() { return _name; }

OwnSwitch3Pos::OwnSwitch3Pos(OwnPCF *pcf, unsigned int pin, const char *name,
                             const char *msg, unsigned long debounceDelay)
    : _oPCF(pcf), _pin(pin), _lastState(0) {
  _oPCF->activatePin(_pin);
  _oPCF->deactivatePin(_pin);
}

int OwnSwitch3Pos::readState() { return _lastState; }
void OwnSwitch3Pos::update() {
  _oPCF->activatePin(_pin);
  int newState = switchCase(digitalRead(FST_SIMPLE_READ_PIN),
                            digitalRead(SCND_SIMPLE_READ_PIN));
  delay(10);
  _oPCF->deactivatePin(_pin);
  if (newState != _lastState) {
    Serial.print("from: ");
    Serial.print(_lastState);
    Serial.print("; to: ");
    Serial.println(newState);
    _lastState = newState;
  }
}
char *OwnSwitch3Pos::getName() { return _name; }

OwnSwitchMultiPos::OwnSwitchMultiPos(OwnPCF *oPCF, unsigned int pin,
                                     const char *msg, const char *name,
                                     bool reverse)
    : _oPCF(oPCF), _pin(pin), _lastState(0) {}

int OwnSwitchMultiPos::readState() { return _lastState; }

void OwnSwitchMultiPos::update() {
  _oPCF->activatePin(_pin);
  int newState = findHighPin();
  delay(10);
  _oPCF->deactivatePin(_pin);
  if (newState != _lastState) {
    Serial.print("from: ");
    Serial.print(_lastState);
    Serial.print("; to: ");
    Serial.println(newState);
    _lastState = newState;
  }
}
char *OwnSwitchMultiPos::getName() { return _name; }
