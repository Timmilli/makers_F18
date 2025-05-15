#ifndef __OWNADAFRUIT_HPP__
#define __OWNADAFRUIT_HPP__

#include "Constants.h"
#include "PCF8574.h"

class OwnPCF {
private:
  PCF8574 *_pcf;
  char _name[MAX_NAME_LENGTH];

public:
  OwnPCF(PCF8574 *pcf, const char *name);
  char *getName();
  void startPCF();
  void activatePin(unsigned int index);
  void deactivatePin(unsigned int index);
};

#endif // include guard
