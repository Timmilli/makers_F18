#define DCSBIOS_DEFAULT_SERIAL
#include "DcsBios.h"

#include "Constants.h"
#include "OwnPCF.hpp"
#include "OwnSwitch.hpp"
#include <Arduino.h>

/* PCF Setup*/

Adafruit_PCF8574 pcf;

int addresses[PCF_AMOUNT] = {0x20, 0x21, 0x22};
OwnPCF *OwnPCFs[PCF_AMOUNT];

OwnSwitch2Pos *switches2Pos[NB_SWITCHES];
OwnSwitch3Pos *switches3Pos[NB_SWITCHES];

/* Main code */

void setup() {
  while (!Serial) {
    delay(10);
  }
  Serial.begin(115200);

  int nb_addr = sizeof(addresses) / sizeof(addresses[0]);
  for (int i = 0; i < PCF_AMOUNT; i++) {
    OwnPCFs[i] = new OwnPCF(&pcf);
    OwnPCFs[i]->startPCF(addresses[i]);
    OwnPCFs[i]->update();
  }

  /* Switches setup */

  OwnSwitch3Pos ufcMasterCaution(OwnPCFs[0], 1, 2, "ufcMasterCaution", "msg",
                                 50);
  /* Potentiometer setup */

  /*DcsBios setup function*/
  // DcsBios::setup();
}

void loop() {
  for (int i = 0; i < PCF_AMOUNT; i++) {
    OwnPCFs[i]->update();
  }
  delay(30);

  DcsBios::loop();

  if (Serial.read() == '!') {
    for (int i = 0; i < NB_SWITCHES; i++) {
      Serial.print("Switch ");
      Serial.print(switches2Pos[i]->getName());
    }
  }
}
