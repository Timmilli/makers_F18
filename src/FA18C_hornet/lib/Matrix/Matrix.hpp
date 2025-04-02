#ifndef __MATRIX_HPP_
#define __MATRIX_HPP_

#include "Switch.hpp"
#include <map>
#include <string>

#define MAX_ROWS 5
#define MAX_COLS 10

class Matrix {
private:
  int _nbRows;
  int _nbCols;
  int _rows[MAX_ROWS];
  int _cols[MAX_COLS];
  Switch _matrix[MAX_COLS][MAX_ROWS];

  int cantor_pairing_function(int x, int y);
  void cantor_unpairing_function(int *x, int *y, const int z);

  void getSwitchNamesViaFile(std::map<int, std::string> *m,
                             const char *filename);

public:
  Matrix(const int *colPins, const int *rowPins, int nbCols, int nbRows);

  void setup();

  void setValue(int rowIndex, int colIndex, int value);
  int getValue(int rowIndex, int colIndex);

  int getConnectedRowPin(int row);
  int getConnectedColPin(int col);

  void updateMatrix();

  void printOne(int colIndex, int rowIndex, int oldValue, int newValue);
  void printAll();
};

#endif // __MATRIX_HPP_
