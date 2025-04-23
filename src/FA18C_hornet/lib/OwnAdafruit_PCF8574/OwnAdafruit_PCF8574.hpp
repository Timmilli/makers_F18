#ifndef __OWNADAFRUIT_HPP__
#define __OWNADAFRUIT_HPP__

#include "Adafruit_PCF8574.h"

class OwnAdafruit_PCF8574 {
private:
  Adafruit_PCF8574 *_pcf;
  unsigned int _states[8];

public:
  OwnAdafruit_PCF8574(Adafruit_PCF8574 *pcf);
  void startPCF(int addr);
  void update();
  unsigned int getState(unsigned int index);
};

#endif // include guard
