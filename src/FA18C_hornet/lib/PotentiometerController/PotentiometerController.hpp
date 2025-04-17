#ifndef __POTENTIOMETERCONTROLLER_HPP__
#define __POTENTIOMETERCONTROLLER_HPP__

class PotentiometerController {
private:
  float _states[8];
  int _control_pins[3];
  int _z_pin;

public:
  PotentiometerController(int control_pins[], int z_pin);
  int getState(unsigned int pin);
  void update();
};

#endif // __POTENTIOMETERCONTROLLER_HPP__