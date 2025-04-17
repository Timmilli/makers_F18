#include "AllSwitchController.hpp"
#include "Adafruit_PCF8574.h"
#include "SwitchController.hpp"

AllSwitchController::AllSwitchController(int nb, Adafruit_PCF8574 *pcf)
    : _nb(nb) {
  for (int i = 0; i < nb; i++) {
    _tab[i] = new SwitchController(pcf);
  }
}

AllSwitchController::~AllSwitchController() {
  for (int i = 0; i < _nb; i++) {
    delete _tab[i];
  }
}

SwitchController *AllSwitchController::getController(int index) {
  return _tab[index];
}
