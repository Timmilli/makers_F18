#include "Adafruit_PCF8574.h"
#include "AllPCF.hpp"
#include "OnePCF.hpp"
#include "Switch.hpp"
#include <Arduino.h>
#define DCSBIOS_DEFAULT_SERIAL
#define DCSBIOS_DISABLE_SERVO
#include "DcsBios.h"

#define NB_PCFS 3

int addresses[] = {0x20, 0x21, 0x22};

Adafruit_PCF8574 ada_pcf;

void setup() { Serial.begin(115200); }

void loop() {}
