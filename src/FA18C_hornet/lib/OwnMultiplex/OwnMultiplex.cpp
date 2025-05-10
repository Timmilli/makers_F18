#include "OwnMultiplex.hpp"
#include "Arduino.h"
#include "Constants.h"

float getPotentiometerValue(OwnPCF *oPCF, uint8_t index, unsigned int msb,
                            unsigned int midsb, unsigned int lsb) {
  float res = 0.0;
  switch (index) {
  case (0):
    oPCF->deactivatePin(msb);
    oPCF->deactivatePin(midsb);
    oPCF->deactivatePin(lsb);
    res = analogRead(ANALOG_READ_ADDR);
  case (1):
    oPCF->activatePin(lsb);
    res = analogRead(ANALOG_READ_ADDR);
    oPCF->deactivatePin(lsb);
    break;
  case (2):
    oPCF->activatePin(midsb);
    res = analogRead(ANALOG_READ_ADDR);
    oPCF->deactivatePin(midsb);
    break;
  case (3):
    oPCF->activatePin(midsb);
    oPCF->activatePin(lsb);
    res = analogRead(ANALOG_READ_ADDR);
    oPCF->deactivatePin(midsb);
    oPCF->deactivatePin(lsb);
    break;
  case (4):
    oPCF->activatePin(msb);
    res = analogRead(ANALOG_READ_ADDR);
    oPCF->deactivatePin(msb);
    break;
  case (5):
    oPCF->activatePin(msb);
    oPCF->activatePin(lsb);
    res = analogRead(ANALOG_READ_ADDR);
    res = analogRead(ANALOG_READ_ADDR);
    oPCF->deactivatePin(msb);
    oPCF->deactivatePin(midsb);
    break;
  case (7):
    oPCF->activatePin(msb);
    oPCF->activatePin(midsb);
    oPCF->activatePin(lsb);
    res = analogRead(ANALOG_READ_ADDR);
    oPCF->deactivatePin(msb);
    oPCF->deactivatePin(midsb);
    oPCF->deactivatePin(lsb);
    break;
  }
  return res;
}

OwnMultiplex::OwnMultiplex(OwnPCF *oPCF, unsigned int MSBit_pin,
                           unsigned int midBit_pin, unsigned int LSBit_pin,
                           byte pin_enable, byte pin_read)
    : _oPCF(oPCF), _msb(MSBit_pin), _midsb(midBit_pin), _lsb(LSBit_pin),
      _pin_enable(pin_enable), _pin_read(pin_read) {
  for (uint8_t i = 0; i < 8; i++) {
    _states[i] = 0.0;
  }
}

/*
void OwnMultiplex::startMultiplex() {
  pinMode(_pin_A, OUTPUT);
  pinMode(_pin_B, OUTPUT);
  pinMode(_pin_C, OUTPUT);
  digitalWrite(_pin_A, LOW);
  digitalWrite(_pin_B, LOW);
  digitalWrite(_pin_C, LOW);

  pinMode(_pin_enable, OUTPUT);
  digitalWrite(_pin_enable, LOW);
}*/

void OwnMultiplex::update() {
  for (uint8_t i = 0; i < 8; i++) {
    _states[i] = getPotentiometerValue(_oPCF, i, _msb, _midsb, _lsb);
  }
}

int OwnMultiplex::getState(unsigned int index) { return _states[index]; }