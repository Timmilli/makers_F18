#include "PotentiometerController.hpp"

PotentiometerController::PotentiometerController(int control_pins[], int z_pin)
    : _z_pin(z_pin) {
  for (int i = 0; i < 3; i++) {
    _control_pins[i] = control_pins[i];
  }
  for (int i = 0; i < 8; i++) {
    _states[i] = 0;
  }
}