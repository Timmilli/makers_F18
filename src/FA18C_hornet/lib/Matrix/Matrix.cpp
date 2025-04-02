#include "Matrix.hpp"
#include <Arduino.h>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

int Matrix::cantor_pairing_function(int x, int y) {
  return (x * x + x + 2 * x * y + 3 * y + y * y) / 2;
}

void Matrix::cantor_unpairing_function(int *x, int *y, const int z) {
  int w = floor((sqrt(8 * z + 1) - 1) / 2);
  int t = (w * w + w) / 2;
  *y = z - t;
  *x = w - *y;
}

void Matrix::getSwitchNamesViaFile(std::map<int, std::string> *m,
                                   const char *filename) {

  std::ifstream file(filename); // Change this to your file name
  if (!file) {
    std::cerr << "Error opening file!\n";
    return;
  }

  std::string line;
  while (std::getline(file, line)) {
    std::stringstream ss(line);
    char discard; // To discard unwanted characters like '(', ',', ')'
    int x, y;
    std::string label;

    // Extract integer values
    ss >> discard >> x >> discard >> y >> discard; // (x,y),

    // Extract label (removing surrounding parentheses)
    std::getline(ss >> std::ws, label, ')');
    label = label.substr(2); // Remove leading '('

    // Pretty sure this line causes all my issues :/
    (*m)[cantor_pairing_function(x, y)] = label; // Store in map
  }

  file.close();
}

Matrix::Matrix(const int *colPins, const int *rowPins, int nbCols, int nbRows) {
  _nbRows = nbRows;
  _nbCols = nbCols;

  std::map<int, std::string> m{
      {cantor_pairing_function(12, 16), "LGEN"},
      {cantor_pairing_function(12, 17), "RGEN"},
      {cantor_pairing_function(12, 18), "ANTI ICE PILOT"}};

  for (int c = 0; c < nbCols; c++) {
    _cols[c] = colPins[c];
    for (int r = 0; r < nbRows; r++) {
      if (c == 0)
        _rows[r] = rowPins[r];
      std::string name = m[cantor_pairing_function(_cols[c], _rows[r])];
      _matrix[c][r] = Switch(name);
    }
  }
}

void Matrix::setup() {
  for (int x = 0; x < _nbRows; x++) {
    Serial.print(this->getConnectedRowPin(x));
    Serial.println(" as input");
    pinMode(this->getConnectedRowPin(x), INPUT);
  }

  for (int x = 0; x < _nbCols; x++) {
    Serial.print(this->getConnectedColPin(x));
    Serial.println(" as input-pullup");
    pinMode(this->getConnectedColPin(x), INPUT_PULLUP);
  }
}

void Matrix::setValue(int colIndex, int rowIndex, int value) {
  _matrix[colIndex][rowIndex].setValue(value);
}
int Matrix::getValue(int colIndex, int rowIndex) {
  return _matrix[colIndex][rowIndex].getValue();
}

int Matrix::getConnectedRowPin(int row) { return _rows[row]; }
int Matrix::getConnectedColPin(int col) { return _cols[col]; }

void Matrix::updateMatrix() {
  // iterate the columns
  for (int colIndex = 0; colIndex < _nbCols; colIndex++) {
    // col: set to output to low
    int curCol = this->getConnectedColPin(colIndex);
    pinMode(curCol, OUTPUT);
    digitalWrite(curCol, LOW);

    // row: interate through the rows
    for (int rowIndex = 0; rowIndex < _nbRows; rowIndex++) {
      int rowCol = this->getConnectedRowPin(rowIndex);
      pinMode(rowCol, INPUT_PULLUP);
      int oldValue = this->getValue(colIndex, rowIndex);
      int newValue = digitalRead(rowCol);
      if (newValue != oldValue) {
        this->printOne(colIndex, rowIndex, oldValue, newValue);
        this->setValue(colIndex, rowIndex, newValue);
      }
      pinMode(rowCol, INPUT);
    }
    // disable the column
    pinMode(curCol, INPUT);
  }
}

void Matrix::printOne(int colIndex, int rowIndex, int oldValue, int newValue) {
  Serial.print("Updating ");
  Serial.print(_matrix[colIndex][rowIndex].getName().c_str());
  Serial.print(": ");
  Serial.print(oldValue);
  Serial.print(" -> ");
  Serial.println(newValue);
}

void Matrix::printAll() {
  Serial.println("Printing the matrix");
  for (int r = -1; r < _nbRows; r++) {
    if (r > -1) {
      Serial.print(_rows[r]);
      Serial.print('\t');
    }
    for (int c = 0; c < _nbCols; c++) {
      if (r == -1) {
        Serial.print('\t');
        Serial.print(_cols[c]);
      } else {
        Serial.print(_matrix[c][r].getValue());
        Serial.print('\t');
      }
    }
    Serial.println("");
  }
}

/* MATRIX
    1   2   3   4   5   6
7 --+---+---+---+---+---+-
    |   |   |   |   |   |
8---+---+---+---+---+---+-
    |   |   |   |   |   |
9---+---+---+---+---+---+-
*/
