#define DCSBIOS_DEFAULT_SERIAL
#include "DcsBios.h"

#include "Constants.h"
#include "OwnMultiplex.hpp"
#include "OwnPCF.hpp"
#include "OwnPotentiometer.hpp"
#include "OwnSwitch.hpp"
#include <Arduino.h>

/* PCF setup*/

Adafruit_PCF8574 pcf;

int addresses[PCF_AMOUNT] = {ADDR_FIRST_PCF, ADDR_SECOND_PCF, ADDR_THIRD_PCF};
OwnPCF *OwnPCFs[PCF_AMOUNT];

/* Multiplex setup */

OwnMultiplex *OwnMultiplexes[MULTIPLEX_AMOUNT];

/* Switch and potentiometer arrays */

void *switches[NB_2SWITCHES + NB_3SWITCHES + NB_NSWITCHES];
OwnPotentiometer *potentiometers[NB_POTENTIOMETER];

/* Switch and potentiometer definitions */

// TODO Verify all attribution with hardware

// ELEC
OwnSwitch2Pos lGenSw(OwnPCFs[0], FIFTH_PIN, "L_GEN_SW", "msg", false, 50);
OwnSwitch3Pos batterySw(OwnPCFs[0], FIRST_PIN, "BATTERY_SW", "msg", 50);
OwnSwitch2Pos rGenSw(OwnPCFs[0], SIXTH_PIN, "R_GEN_SW", "msg", false, 50);

// ECS
OwnSwitch3Pos ecsModeSw(OwnPCFs[0], SECOND_PIN, "ECS_MODE_SW", "msg", 50);
OwnPotentiometer cabinTemp(OwnMultiplexes[0], "msg", FIRST_MLTPLX_PIN,
                           "CABIN_TEMP", false, 0, 1023);
OwnPotentiometer suitTemp(OwnMultiplexes[0], "msg", SECOND_MLTPLX_PIN,
                          "SUIT_TEMP", false, 0, 1023);
OwnSwitch3Pos cabinPressSw(OwnPCFs[0], THIRD_PIN, "CABIN_PRESS_SW", "msg", 50);
OwnSwitch2Pos pitotHeatSw(OwnPCFs[0], SEVENTH_PIN, "PITOT_HEAT_SW", "msg",
                          false, 50);
OwnSwitch3Pos engAntiiceSw(OwnPCFs[0], FOURTH_PIN, "ENG_ANTIICE_SW", "msg", 50);
OwnSwitchMultiPos bleedAirKnob(OwnPCFs[1], THIRD_PIN, "msg", "BLEED_AIR_KNOB",
                               false);

// INTR LT
OwnPotentiometer consolesDimmer(OwnMultiplexes[0], "msg", THIRD_MLTPLX_PIN,
                                "CONSOLES_DIMMER", false, 0, 1023);
OwnPotentiometer instPnlDimmer(OwnMultiplexes[0], "msg", FOURTH_MLTPLX_PIN,
                               "INST_PNL_DIMMER", false, 0, 1023);
OwnPotentiometer floodDimmer(OwnMultiplexes[0], "msg", FIFTH_MLTPLX_PIN,
                             "FLOOD_DIMMER", false, 0, 1023);
OwnSwitch2Pos lightsTestSw(OwnPCFs[0], EIGHTH_PIN, "LIGHTS_TEST_SW", "msg",
                           false, 50);
OwnPotentiometer warnCautionDimmer(OwnMultiplexes[0], "msg", SIXTH_MLTPLX_PIN,
                                   "WARN_CAUTION_DIMMER", false, 0, 1023);
OwnPotentiometer chartDimmer(OwnMultiplexes[0], "msg", SEVENTH_MLTPLX_PIN,
                             "CHART_DIMMER", false, 0, 1023);
OwnSwitch3Pos cockkpitLightModeSw(OwnPCFs[1], FIRST_PIN,
                                  "COCKKPIT_LIGHT_MODE_SW", "msg", 50);

// SNSR
OwnSwitch3Pos flirSw(OwnPCFs[2], FOURTH_PIN, "FLIR_SW", "msg", 50);
OwnSwitch2Pos ltdRSw(OwnPCFs[1], SECOND_PIN, "LTD_R_SW", "msg", false, 50);
OwnSwitch2Pos lstNflrSw(OwnPCFs[2], FIFTH_PIN, "LST_NFLR_SW", "msg", false, 50);
OwnSwitchMultiPos radarSw(OwnPCFs[1], FOURTH_PIN, "msg", "RADAR_SW", false);
OwnSwitchMultiPos insSw(OwnPCFs[1], FIFTH_PIN, "msg", "INS_SW", false);

// KY 58
OwnSwitchMultiPos ky58ModeSelect(OwnPCFs[1], SIXTH_PIN, "msg",
                                 "KY58_MODE_SELECT", false);
OwnSwitchMultiPos ky58FillSelect(OwnPCFs[1], SEVENTH_PIN, "msg",
                                 "KY58_FILL_SELECT", false);
OwnSwitchMultiPos ky58PowerSelect(OwnPCFs[1], EIGHTH_PIN, "KY58_POWER_SELECT",
                                  "msg", 50);

/* Main code */

void setup() {
  while (!Serial) {
    delay(10);
  }
  Serial.begin(115200);

  /* PCF setup */
  for (int i = 0; i < PCF_AMOUNT; i++) {
    OwnPCFs[i] = new OwnPCF(&pcf);
    OwnPCFs[i]->startPCF(addresses[i]);
  }

  /* Switches setup */
  int i = 0;
  // 2 pos
  switches[i++] = (void *)&lGenSw;
  switches[i++] = (void *)&rGenSw;
  switches[i++] = (void *)&pitotHeatSw;
  switches[i++] = (void *)&lightsTestSw;
  switches[i++] = (void *)&ltdRSw;
  switches[i++] = (void *)&lstNflrSw;
  // 3 pos
  switches[i++] = (void *)&batterySw;
  switches[i++] = (void *)&ecsModeSw;
  switches[i++] = (void *)&cabinPressSw;
  switches[i++] = (void *)&engAntiiceSw;
  switches[i++] = (void *)&cockkpitLightModeSw;
  switches[i++] = (void *)&flirSw;
  // multi pos(void *)
  switches[i++] = (void *)&bleedAirKnob;
  switches[i++] = (void *)&insSw;
  switches[i++] = (void *)&radarSw;
  switches[i++] = (void *)&ky58FillSelect;
  switches[i++] = (void *)&ky58ModeSelect;
  switches[i++] = (void *)&ky58PowerSelect;

  /* Potentiometer setup */
  i = 0;
  potentiometers[i++] = &cabinTemp;
  potentiometers[i++] = &suitTemp;
  potentiometers[i++] = &chartDimmer;
  potentiometers[i++] = &consolesDimmer;
  potentiometers[i++] = &floodDimmer;
  potentiometers[i++] = &instPnlDimmer;
  potentiometers[i++] = &warnCautionDimmer;

  OwnMultiplexes[0] = new OwnMultiplex(
      OwnPCFs[2], FIRST_POTENTIOMETER_PIN, SECOND_POTENTIOMETER_PIN,
      THIRD_POTENTIOMETER_PIN, FST_ADDR_ENABLE, ANALOG_READ_ADDR);

  /*DcsBios setup function*/
  // Unused as it only repeats 'Serial.begin'
  // DcsBios::setup();
}

/* Main loop */

void loop() {
  for (int i = 0; i < NB_2SWITCHES + NB_3SWITCHES + NB_NSWITCHES; i++) {
    if (i < NB_2SWITCHES) {
      ((OwnSwitch2Pos *)switches)[i].update();
    } else if (i < NB_2SWITCHES + NB_3SWITCHES) {
      ((OwnSwitch3Pos *)switches)[i].update();
    } else {
      ((OwnSwitchMultiPos *)switches)[i].update();
    }
  }
  for (int i = 0; i < MULTIPLEX_AMOUNT; i++) {
    OwnMultiplexes[i]->update();
  }
  delay(50);

  DcsBios::loop();

  if (Serial.read() == '!') {
    for (int i = 0; i < NB_2SWITCHES + NB_3SWITCHES + NB_NSWITCHES; i++) {
      if (i < NB_2SWITCHES) {
        Serial.print("Switch ");
        Serial.print(((OwnSwitch2Pos *)switches)[i].getName());
        Serial.print(": ");
        Serial.print(((OwnSwitch2Pos *)switches)[i].readState());
        Serial.println();
      } else if (i < NB_2SWITCHES + NB_3SWITCHES) {
        Serial.print("Switch ");
        Serial.print(((OwnSwitch3Pos *)switches)[i].getName());
        Serial.print(": ");
        Serial.print(((OwnSwitch3Pos *)switches)[i].readState());
        Serial.println();
      } else {
        Serial.print("Switch ");
        Serial.print(((OwnSwitchMultiPos *)switches)[i].getName());
        Serial.print(": ");
        Serial.print(((OwnSwitchMultiPos *)switches)[i].readState());
        Serial.println();
      }
    }
    for (int i = 0; i < MULTIPLEX_AMOUNT; i++) {
      Serial.print("Potentiometer ");
      Serial.print(potentiometers[i]->getName());
      Serial.print(": ");
      Serial.print(potentiometers[i]->readState());
      Serial.println();
    }
  }
}