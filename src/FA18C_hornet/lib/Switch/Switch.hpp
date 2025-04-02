#ifndef __SWITCH_HPP__
#define __SWITCH_HPP__

#include <string>

class Switch {
private:
  std::string _name;
  int _value;

public:
  Switch();
  Switch(const std::string name);

  std::string getName();

  void setValue(int value);
  int getValue();
};

#endif // __SWITCH_HPP__
