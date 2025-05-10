#ifndef __CONSTANTS_H__
#define __CONSTANTS_H__

#include "Arduino.h"

/* General macros */

#define MAX_NAME_LENGTH 32

/* PCF and Switch macros*/

// Amounts
#define NB_2SWITCHES 6
#define NB_3SWITCHES 6
#define NB_NSWITCHES 6

// Communication pins
#define SDA_PIN 1
#define SCL_PIN 2

// Reading pins
#define FST_SIMPLE_READ_PIN 3
#define SCND_SIMPLE_READ_PIN 4

#define FST_COMPLEX_READ_PIN 5
#define SCND_COMPLEX_READ_PIN 5
#define THRD_COMPLEX_READ_PIN 5
#define FRTH_COMPLEX_READ_PIN 5
#define FFTH_COMPLEX_READ_PIN 5
#define SXTH_COMPLEX_READ_PIN 5
#define SVTH_COMPLEX_READ_PIN 5
#define EGTH_COMPLEX_READ_PIN 5

// PCFs
#define PCF_AMOUNT 3

#define ADDR_FIRST_PCF 0x20
#define ADDR_SECOND_PCF 0x21
#define ADDR_THIRD_PCF 0x22

#define FIRST_PIN 1
#define SECOND_PIN 2
#define THIRD_PIN 3
#define FOURTH_PIN 4
#define FIFTH_PIN 5
#define SIXTH_PIN 6
#define SEVENTH_PIN 7
#define EIGHTH_PIN 8

/* Multiplex and Potentiometer macros */

#define MULTIPLEX_AMOUNT 1
#define NB_POTENTIOMETER 7

// First multiplexer
#define FST_ADDR_ENABLE 1
#define ANALOG_READ_ADDR A0

// Potentiometer codes
#define FIRST_POTENTIOMETER_PIN 1 // Most significant bit
#define SECOND_POTENTIOMETER_PIN 2
#define THIRD_POTENTIOMETER_PIN 3 // Least significant bit

#endif // __CONSTANTS_H__