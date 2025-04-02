#include "Matrix.hpp"
#include <Arduino.h>
#include <cstdio>

/* MATRIX SETUP */
int nbCols = 6;
int colPins[] = {12, 14, 27, 26, 25, 33};
int nbRows = 3;
int rowPins[] = {16, 17, 18};
Matrix matrix(colPins, rowPins, nbCols, nbRows);

void setup() {
  Serial.begin(115200);
  matrix.setup();
}

void loop() {
  matrix.updateMatrix();
  if (Serial.read() == '!') {
    matrix.printAll();
  }
}
