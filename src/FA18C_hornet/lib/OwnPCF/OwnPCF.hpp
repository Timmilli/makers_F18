#ifndef __OWNADAFRUIT_HPP__
#define __OWNADAFRUIT_HPP__

#include "Adafruit_PCF8574.h"

class OwnPCF {
private:
  Adafruit_PCF8574 *_pcf;

public:
  OwnPCF(Adafruit_PCF8574 *pcf);
  void startPCF(int addr);
  void activatePin(unsigned int index);
  void deactivatePin(unsigned int index);
};

#endif // include guard
