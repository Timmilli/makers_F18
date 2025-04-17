#include "Adafruit_PCF8574.h"
#include "AllPotentiometerController.hpp"
#include "AllSwitchController.hpp"
#include "PotentiometerController.hpp"
#include "Switch.hpp"
#include "SwitchController.hpp"
#include <Arduino.h>
#define DCSBIOS_DEFAULT_SERIAL
#define DCSBIOS_DISABLE_SERVO
#include "Constants.h"
#include "DcsBios.h"

int switchAddresses[NB_SWITCH_CONTROLLER] = {0x20, 0x21, 0x22};

int controlPins[NB_POTENTIOMETER_CONTROLLER][3] = {{1, 2, 3}, {4, 5, 6}};
int z_pins[NB_POTENTIOMETER_CONTROLLER] = {1, 2};

Adafruit_PCF8574 ada_pcf;

AllSwitchController all_sc(NB_SWITCH_CONTROLLER, &ada_pcf);
AllPotentiometerController all_pc(NB_POTENTIOMETER_CONTROLLER, controlPins,
                                  z_pins);

void setup() {
  Serial.begin(115200);
  for (int i = 0; i < NB_SWITCH_CONTROLLER; i++) {
    all_sc.getController(i)->startPCF(switchAddresses[i]);
  }
}

void loop() {}
