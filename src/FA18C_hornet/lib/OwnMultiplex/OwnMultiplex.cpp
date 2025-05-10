#include "OwnMultiplex.hpp"
#include "Arduino.h"
#include "Constants.h"

float getPotentiometerValue(OwnPCF *oPCF, uint8_t index) {
  float res = 0.0;
  switch (index) {
  case (0):
    oPCF->deactivatePin(FIRST_POTENTIOMETER_PIN);
    oPCF->deactivatePin(SECOND_POTENTIOMETER_PIN);
    oPCF->deactivatePin(THIRD_POTENTIOMETER_PIN);
    res = analogRead(ANALOG_READ_ADDR);
  case (1):
    oPCF->activatePin(THIRD_POTENTIOMETER_PIN);
    res = analogRead(ANALOG_READ_ADDR);
    oPCF->deactivatePin(THIRD_POTENTIOMETER_PIN);
    break;
  case (2):
    oPCF->activatePin(SECOND_POTENTIOMETER_PIN);
    res = analogRead(ANALOG_READ_ADDR);
    oPCF->deactivatePin(SECOND_POTENTIOMETER_PIN);
    break;
  case (3):
    oPCF->activatePin(SECOND_POTENTIOMETER_PIN);
    oPCF->activatePin(THIRD_POTENTIOMETER_PIN);
    res = analogRead(ANALOG_READ_ADDR);
    oPCF->deactivatePin(SECOND_POTENTIOMETER_PIN);
    oPCF->deactivatePin(THIRD_POTENTIOMETER_PIN);
    break;
  case (4):
    oPCF->activatePin(FIRST_POTENTIOMETER_PIN);
    res = analogRead(ANALOG_READ_ADDR);
    oPCF->deactivatePin(FIRST_POTENTIOMETER_PIN);
    break;
  case (5):
    oPCF->activatePin(FIRST_POTENTIOMETER_PIN);
    oPCF->activatePin(THIRD_POTENTIOMETER_PIN);
    res = analogRead(ANALOG_READ_ADDR);
    oPCF->deactivatePin(FIRST_POTENTIOMETER_PIN);
    oPCF->deactivatePin(THIRD_POTENTIOMETER_PIN);
    break;
  case (6):
    oPCF->activatePin(FIRST_POTENTIOMETER_PIN);
    oPCF->activatePin(SECOND_POTENTIOMETER_PIN);
    res = analogRead(ANALOG_READ_ADDR);
    oPCF->deactivatePin(FIRST_POTENTIOMETER_PIN);
    oPCF->deactivatePin(SECOND_POTENTIOMETER_PIN);
    break;
  case (7):
    oPCF->activatePin(FIRST_POTENTIOMETER_PIN);
    oPCF->activatePin(SECOND_POTENTIOMETER_PIN);
    oPCF->activatePin(THIRD_POTENTIOMETER_PIN);
    res = analogRead(ANALOG_READ_ADDR);
    oPCF->deactivatePin(FIRST_POTENTIOMETER_PIN);
    oPCF->deactivatePin(SECOND_POTENTIOMETER_PIN);
    oPCF->deactivatePin(THIRD_POTENTIOMETER_PIN);
    break;
  }
  return res;
}

OwnMultiplex::OwnMultiplex(OwnPCF *oPCF, byte pin_enable, byte pin_read)
    : _oPCF(oPCF), _pin_enable(pin_enable), _pin_read(pin_read) {
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
    _states[i] = getPotentiometerValue(_oPCF, i);
  }
}

int OwnMultiplex::getState(unsigned int index) { return _states[index]; }