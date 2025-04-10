#include "AllPCF.hpp"
#include "Adafruit_PCF8574.h"

AllPCF::AllPCF(int nb, Adafruit_PCF8574 *pcf) : _nb(nb) {
  for (int i = 0; i < nb; i++) {
    _tab[i] = new OnePCF(pcf);
  }
}

AllPCF::~AllPCF() {
  for (int i = 0; i < _nb; i++) {
    delete _tab[i];
  }
}