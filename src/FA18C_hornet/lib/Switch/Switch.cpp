#include "Switch.hpp"
#include <string>

Switch::Switch() : _name(""), _value(0) {}
Switch::Switch(const std::string name) : _name(name), _value(0) {}

std::string Switch::getName() { return _name; }

void Switch::setValue(int value) { _value = value; }
int Switch::getValue() { return _value; }
