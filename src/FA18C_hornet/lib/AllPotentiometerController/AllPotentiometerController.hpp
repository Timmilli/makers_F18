#ifndef __ALLPOTENTIOMETERCONTROLLER_HPP__
#define __ALLPOTENTIOMETERCONTROLLER_HPP__

#include "Constants.h"
#include "PotentiometerController.hpp"

class AllPotentiometerController {
private:
  int _nb_controller;
  PotentiometerController *_tab[MAX_CONTROLLER_NUMBER];

public:
  AllPotentiometerController(int nb,
                             int controlPins[NB_POTENTIOMETER_CONTROLLER][3],
                             int z_pins[NB_POTENTIOMETER_CONTROLLER]);
  ~AllPotentiometerController();
  PotentiometerController *getController(int index);
  void print();
};

#endif // __ALLPOTENTIOMETERCONTROLLER_HPP__