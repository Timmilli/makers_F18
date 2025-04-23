#ifndef __OWNSWITCH_HPP__
#define __OWNSWITCH_HPP__

#include "DcsBios.h"
#include "OwnAdafruit_PCF8574.hpp"

class OwnSwitch2Pos : public DcsBios::Switch2Pos {
private:
  OwnAdafruit_PCF8574 _pcf;
  unsigned int _pin;

public:
  OwnSwitch2Pos(OwnAdafruit_PCF8574 pcf, unsigned int pin);
  char readState();
};

class OwnSwitch3Pos : public DcsBios::Switch3Pos {
private:
  OwnAdafruit_PCF8574 _pcf;
  unsigned int _pinA, _pinB;

public:
  OwnSwitch3Pos(OwnAdafruit_PCF8574 pcf, unsigned int pinA, unsigned int pinB);
  char readState();
};

#endif // include guard
