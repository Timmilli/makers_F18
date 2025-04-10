#include <Arduino.h>
#include "Adafruit_PCF8574.h"
#include "OwnPCF.h"
#include "Switches.h"

#define NB_PCFS 1

int addresses[] = {0x00};

Adafruit_PCF8574 ada_pcf;
OwnPCF opcf(&ada_pcf);
Switches swb0(opcf, 0);
Switches swb1(opcf, 1);
Switches swb2(opcf, 2);


void setup() {
  Serial.begin(115200);
  for (int i = 0; i < NB_PCFS; i++)
    opcf.startPCF(addresses[i]);
}

void loop() {
  opcf.update();
  delay(100);
}
