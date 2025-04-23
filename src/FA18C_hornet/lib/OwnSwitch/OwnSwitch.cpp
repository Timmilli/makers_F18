#include "OwnSwitch.hpp"
#include "OwnAdafruit_PCF8574.hpp"

OwnSwitch2Pos::OwnSwitch2Pos(OwnAdafruit_PCF8574 pcf, unsigned int pin)
    : _pcf(pcf), _pin(pin) {}

char OwnSwitch2Pos::readState() { return _pcf.getState(_pin); }

OwnSwitch3Pos::OwnSwitch3Pos(OwnAdafruit_PCF8574 pcf, unsigned int pinA,
                             unsigned int pinB)
    : _pcf(pcf), _pinA(pinA), _pinB(pinB) {}

char OwnSwitch3Pos::readState() {
  // TODO check each case
  return _pcf.getState(_pinA);
}