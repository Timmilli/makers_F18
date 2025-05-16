#ifndef __CONSTANTS_H__
#define __CONSTANTS_H__

#include "Arduino.h"

/* General macros */

#define MAX_NAME_LENGTH 32

/* PCF and Switch macros*/

// Amounts
#define NB_2SWITCHES 8
#define NB_3SWITCHES 0
#define NB_NSWITCHES 0

// Reading pins
#define FST_SIMPLE_READ_PIN 2
#define SCND_SIMPLE_READ_PIN 0

#define FRST_COMPLEX_READ_PIN 5
#define SCND_COMPLEX_READ_PIN 5
#define THRD_COMPLEX_READ_PIN 5
#define FRTH_COMPLEX_READ_PIN 5
#define FFTH_COMPLEX_READ_PIN 5
#define SXTH_COMPLEX_READ_PIN 5
#define SVTH_COMPLEX_READ_PIN 5
#define EGTH_COMPLEX_READ_PIN 5

// PCFs
#define PCF_AMOUNT 1

// Addresses are defined this way :
// 011     1(A2)(A1)(A0)

// 011    1000
// +-> 3  +-> 8
#define ADDR_FIRST_PCF 0x38
// 011    1001
// +-> 3  +-> 9
#define ADDR_SECOND_PCF 0x39
// 011    1010
// +-> 3  +-> 10
#define ADDR_THIRD_PCF 0x3A

/* Multiplex and Potentiometer macros */

#define MULTIPLEX_AMOUNT 0
#define NB_POTENTIOMETER 1

#define FIRST_MLTPLX_PIN 1
#define SECOND_MLTPLX_PIN 2
#define THIRD_MLTPLX_PIN 3
#define FOURTH_MLTPLX_PIN 4
#define FIFTH_MLTPLX_PIN 5
#define SIXTH_MLTPLX_PIN 6
#define SEVENTH_MLTPLX_PIN 7

// First multiplexer
#define FST_ADDR_ENABLE 1
#define ANALOG_READ_ADDR A0

// Potentiometer codes
#define FIRST_POTENTIOMETER_PIN P0 // Most significant bit
#define SECOND_POTENTIOMETER_PIN P1
#define THIRD_POTENTIOMETER_PIN P2 // Least significant bit

#endif // __CONSTANTS_H__