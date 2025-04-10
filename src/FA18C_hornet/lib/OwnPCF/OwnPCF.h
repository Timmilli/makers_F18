#ifndef __OWNPCF_H__
#define __OWNPCF_H__

#include "Adafruit_PCF8574.h"
#include <Arduino.h>

#define NB_BUTTONS 8

class OwnPCF {
private:
  Adafruit_PCF8574 *_pcf;
  unsigned int _buttons[NB_BUTTONS];

public:
  OwnPCF(Adafruit_PCF8574 *pcf);
  void startPCF(int addr);
  void update();
  unsigned int getState(unsigned int pin);
};

#endif // __OWNPCF_H__
