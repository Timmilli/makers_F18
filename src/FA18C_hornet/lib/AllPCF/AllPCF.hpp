#ifndef __ALLPCF_HPP__
#define __ALLPCF_HPP__

#include "Adafruit_PCF8574.h"
#include "OnePCF.hpp"

#define MAX_PCF_NUMBER 10

class AllPCF {
private:
  int _nb;
  OnePCF *_tab[MAX_PCF_NUMBER];

public:
  AllPCF(int nb, Adafruit_PCF8574 *pcf);
  ~AllPCF();
  void print();
};

#endif // __ALLPCF_HPP__