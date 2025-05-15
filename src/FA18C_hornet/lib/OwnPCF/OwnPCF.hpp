#ifndef __OWNADAFRUIT_HPP__
#define __OWNADAFRUIT_HPP__

#include "PCF8574.h"

class OwnPCF {
private:
  PCF8574 *_pcf;

public:
  OwnPCF(PCF8574 *pcf);
  void startPCF();
  void activatePin(unsigned int index);
  void deactivatePin(unsigned int index);
};

#endif // include guard
