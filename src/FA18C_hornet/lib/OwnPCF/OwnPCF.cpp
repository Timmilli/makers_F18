#include "OwnPCF.hpp"
#include "Adafruit_PCF8574.h"
#include "Arduino.h"

OwnPCF::OwnPCF(Adafruit_PCF8574 *pcf) : _pcf(pcf) {
  for (uint8_t i = 0; i < 8; i++) {
  }
}

void OwnPCF::startPCF(int addr) {
  if (!_pcf->begin(addr, &Wire)) {
    Serial.println("Couldn't find PCF8574");
    while (1)
      ;
  }
  for (uint8_t p = 0; p < 8; p++) {
    _pcf->pinMode(p, INPUT);
  }
}

void OwnPCF::activatePin(unsigned int index) { _pcf->pinMode(index, OUTPUT); }

void OwnPCF::deactivatePin(unsigned int index) { _pcf->pinMode(index, INPUT); }