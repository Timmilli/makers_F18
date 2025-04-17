#ifndef __SWITCHCONTROLLER_HPP__
#define __SWITCHCONTROLLER_HPP__

#include "Adafruit_PCF8574.h"
#include <Arduino.h>

#define NB_BUTTONS 8

class SwitchController {
private:
  Adafruit_PCF8574 *_pcf;
  unsigned int _buttons[NB_BUTTONS];

public:
  SwitchController(Adafruit_PCF8574 *pcf);
  void startPCF(int addr);
  void update();
  unsigned int getState(unsigned int pin);
};

#endif // __SWITCHCONTROLLER_HPP__
