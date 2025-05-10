#ifndef __OWNSWITCH_HPP__
#define __OWNSWITCH_HPP__

#define DCSBIOS_DEFAULT_SERIAL
#include "DcsBios.h"

#include "Constants.h"
#include "OwnPCF.hpp"

class OwnSwitch2Pos : public DcsBios::Switch2Pos {
private:
  OwnPCF *_oPCF;
  unsigned int _pin;
  char _name[MAX_NAME_LENGTH];

public:
  OwnSwitch2Pos(OwnPCF *pcf, unsigned int pin, const char *name,
                const char *msg, bool reverse, unsigned long debounceDelay);
  char readState();
  char *getName();
};

class OwnSwitch3Pos : public DcsBios::Switch3Pos {
private:
  OwnPCF *_oPCF;
  unsigned int _pin;
  char _name[MAX_NAME_LENGTH];

public:
  OwnSwitch3Pos(OwnPCF *pcf, unsigned int pin, const char *name,
                const char *msg, unsigned long debounceDelay);
  char readState();
  char *getName();
};

class OwnSwitchMultiPos : public DcsBios::SwitchMultiPos {
private:
  OwnPCF *_oPCF;
  unsigned int _pin;
  char _name[MAX_NAME_LENGTH];

public:
  OwnSwitchMultiPos(OwnPCF *oPCF, unsigned int pin, const char *msg,
                    const char *name, bool reverse);
  char readState();
  char *getName();
};

#endif // include guard
