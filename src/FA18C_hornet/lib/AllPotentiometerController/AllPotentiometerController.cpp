#include "AllPotentiometerController.hpp"

AllPotentiometerController::AllPotentiometerController(
    int nb, int controlPins[NB_POTENTIOMETER_CONTROLLER][3],
    int z_pins[NB_POTENTIOMETER_CONTROLLER])
    : _nb_controller(nb) {
  for (int i = 0; i < nb; i++) {
    _tab[i] = new PotentiometerController(controlPins[i], z_pin[i]);
  }
}

AllPotentiometerController::~AllPotentiometerController() {
  for (int i = 0; i < _nb_controller; i++) {
    delete _tab[i];
  }
}

PotentiometerController *AllPotentiometerController::getController(int index) {
  return _tab[index];
}

void AllPotentiometerController::print() {}