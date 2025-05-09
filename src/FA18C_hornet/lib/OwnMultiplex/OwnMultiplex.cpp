#include "OwnMultiplex.hpp"
#include "Arduino.h"

OwnMultiplex::OwnMultiplex(byte addr_A, byte addr_B, byte addr_C,
                           byte pin_enable, byte pin_read)
    : _pin_A(addr_A), _pin_B(addr_B), _pin_C(addr_C), _pin_enable(pin_enable),
      _pin_read(pin_read) {
  for (byte i = 0; i < 8; i++) {
    digitalWrite(_pin_A, bitRead(i, 0));
    digitalWrite(_pin_B, bitRead(i, 1));
    digitalWrite(_pin_C, bitRead(i, 2));

    _states[i] = analogRead(_pin_read);
  }
}

void OwnMultiplex::startMultiplex() {
  pinMode(_pin_A, OUTPUT);
  pinMode(_pin_B, OUTPUT);
  pinMode(_pin_C, OUTPUT);
  digitalWrite(_pin_A, LOW);
  digitalWrite(_pin_B, LOW);
  digitalWrite(_pin_C, LOW);

  pinMode(_pin_enable, OUTPUT);
  digitalWrite(_pin_enable, LOW);
}

void OwnMultiplex::update() {
  for (byte i = 0; i < 8; i++) {
    digitalWrite(_pin_A, bitRead(i, 0));
    digitalWrite(_pin_B, bitRead(i, 1));
    digitalWrite(_pin_C, bitRead(i, 2));

    _states[i] = analogRead(_pin_read);
  }
}

int OwnMultiplex::getState(unsigned int index) { return _states[index]; }