#ifndef __POTENTIOMETER_HPP__
#define __POTENTIOMETER_HPP__

#include <string>

class Potentiometer {
private:
  std::string _name;
  unsigned int _position;
  unsigned int _max_pos;

public:
  Potentiometer(std::string name, unsigned int max_pos);

  unsigned int getPosition();
  bool setPosition(unsigned int new_position);
};

#endif // __POTENTIOMETER_HPP__
