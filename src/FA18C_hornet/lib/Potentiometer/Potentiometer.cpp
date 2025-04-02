#include "Potentiometer.hpp"
#include <string>

Potentiometer::Potentiometer(std::string name, unsigned int max_pos)
    : _name(name), _position(0), _max_pos(max_pos) {}

unsigned int Potentiometer::getPosition() { return _position; }

bool Potentiometer::setPosition(unsigned int new_position) {
  if (new_position <= _max_pos) {
    _position = new_position;
    return 1;
  } else {
    return 0;
  }
}
