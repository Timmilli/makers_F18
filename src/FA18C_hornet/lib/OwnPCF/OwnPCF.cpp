#include "OwnPCF.hpp"
#include "Arduino.h"
#include "PCF8574.h"

OwnPCF::OwnPCF(PCF8574 *pcf, const char *name) : _pcf(pcf) {}

char *OwnPCF::getName() { return _name; }

void OwnPCF::startPCF() {
  if (!_pcf->begin()) {
    Serial.println("Couldn't find PCF8574");
  } else {
    Serial.print("PCF8574 (");
    Serial.print(_name);
    Serial.println(") is started");
  }
  for (uint8_t p = 0; p < 8; p++) {
    _pcf->pinMode(p, OUTPUT);
    _pcf->digitalWrite(p, LOW);
  }
}

void OwnPCF::activatePin(unsigned int index) {
  _pcf->digitalWrite(index, HIGH);
}

void OwnPCF::deactivatePin(unsigned int index) {
  _pcf->digitalWrite(index, LOW);
}