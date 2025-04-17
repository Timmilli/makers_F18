#ifndef __ALLSWITCHCONTROLLER_HPP__
#define __ALLSWITCHCONTROLLER_HPP__

#include "Adafruit_PCF8574.h"
#include "Constants.h"
#include "SwitchController.hpp"

class AllSwitchController {
private:
  int _nb;
  SwitchController *_tab[MAX_CONTROLLER_NUMBER];

public:
  AllSwitchController(int nb, Adafruit_PCF8574 *pcf);
  ~AllSwitchController();
  SwitchController *getController(int index);
  void print();
};

#endif // __ALLSWITCHCONTROLLER_HPP__
