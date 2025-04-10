#ifndef __ONEPCF_H__
#define __ONEPCF_H__

#include "Adafruit_PCF8574.h"
#include <Arduino.h>

#define NB_BUTTONS 8

class OnePCF {
private:
  Adafruit_PCF8574 *_pcf;
  unsigned int _buttons[NB_BUTTONS];

public:
  OnePCF(Adafruit_PCF8574 *pcf);
  void startPCF(int addr);
  void update();
  unsigned int getState(unsigned int pin);
};

#endif // __ONEPCF_H__
