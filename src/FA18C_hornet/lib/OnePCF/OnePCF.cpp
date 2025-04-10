#include "OnePCF.hpp"
#include "Adafruit_PCF8574.h"

OnePCF::OnePCF(Adafruit_PCF8574 *pcf) : _pcf(pcf) {
  for (unsigned int i = 0; i < NB_BUTTONS; i++) {
    _buttons[i] = 0;
  }
}

unsigned int OnePCF::getState(unsigned int pin) { return _buttons[pin]; }

void OnePCF::startPCF(int addr) {
  if (!_pcf->begin(addr, &Wire)) {
    Serial.println("Couldn't find PCF8574");
    while (1)
      ;
  }
  for (uint8_t p = 0; p < NB_BUTTONS; p++) {
    _pcf->pinMode(p, INPUT_PULLUP);
  }
}

void OnePCF::update() {
  for (int p = 0; p < NB_BUTTONS; p++) {
    _buttons[p] = _pcf->digitalRead(p);
  }
}