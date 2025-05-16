#include "Constants.h"
#include "OwnPCF.hpp"
#include "OwnSwitch.hpp"
#include "PCF8574.h"
#include <Arduino.h>

/* PCF setup*/

PCF8574 firstPCF(ADDR_FIRST_PCF);
OwnPCF firstoPCF(&firstPCF, "first PCF");
PCF8574 secondPCF(ADDR_SECOND_PCF);
OwnPCF secondoPCF(&secondPCF, "second PCF");
PCF8574 thirdPCF(ADDR_THIRD_PCF);
OwnPCF thirdoPCF(&thirdPCF, "third PCF");

/* Switch and potentiometer arrays */

/* Switch and potentiometer definitions */

// ELEC
OwnSwitch2Pos lGenSw(&firstoPCF, P4, "L_GEN_SW", "msg", false, 50);
OwnSwitch3Pos batterySw(&firstoPCF, P0, "BATTERY_SW", "msg", 50);
OwnSwitch2Pos rGenSw(&firstoPCF, P5, "R_GEN_SW", "msg", false, 50);

// ECS
OwnSwitch3Pos ecsModeSw(&firstoPCF, P1, "ECS_MODE_SW", "msg", 50);
// OwnPotentiometer cabinTemp(OwnMultiplexes[0], "msg", FIRST_MLTPLX_PIN,
//                            "CABIN_TEMP", false, 0, 1023);
// OwnPotentiometer suitTemp(OwnMultiplexes[0], "msg", SECOND_MLTPLX_PIN,
//                           "SUIT_TEMP", false, 0, 1023);
OwnSwitch3Pos cabinPressSw(&firstoPCF, P2, "CABIN_PRESS_SW", "msg", 50);
OwnSwitch2Pos pitotHeatSw(&firstoPCF, P6, "PITOT_HEAT_SW", "msg", false, 50);
OwnSwitch3Pos engAntiiceSw(&firstoPCF, P3, "ENG_ANTIICE_SW", "msg", 50);
OwnSwitchMultiPos bleedAirKnob(&secondoPCF, P2, "msg", "BLEED_AIR_KNOB", false);

// INTR LT
// OwnPotentiometer consolesDimmer(OwnMultiplexes[0], "msg", THIRD_MLTPLX_PIN,
//                                 "CONSOLES_DIMMER", false, 0, 1023);
// OwnPotentiometer instPnlDimmer(OwnMultiplexes[0], "msg", FOURTH_MLTPLX_PIN,
//                                "INST_PNL_DIMMER", false, 0, 1023);
// OwnPotentiometer floodDimmer(OwnMultiplexes[0], "msg", FIFTH_MLTPLX_PIN,
//                              "FLOOD_DIMMER", false, 0, 1023);
OwnSwitch2Pos lightsTestSw(&firstoPCF, P7, "LIGHTS_TEST_SW", "msg", false, 50);
// OwnPotentiometer warnCautionDimmer(OwnMultiplexes[0], "msg",
// SIXTH_MLTPLX_PIN,
//                                    "WARN_CAUTION_DIMMER", false, 0, 1023);
// OwnPotentiometer chartDimmer(OwnMultiplexes[0], "msg", SEVENTH_MLTPLX_PIN,
//                              "CHART_DIMMER", false, 0, 1023);
OwnSwitch3Pos cockkpitLightModeSw(&secondoPCF, P0, "COCKKPIT_LIGHT_MODE_SW",
                                  "msg", 50);

// SNSR
OwnSwitch3Pos flirSw(&thirdoPCF, P3, "FLIR_SW", "msg", 50);
OwnSwitch2Pos ltdRSw(&secondoPCF, P1, "LTD_R_SW", "msg", false, 50);
OwnSwitch2Pos lstNflrSw(&thirdoPCF, P4, "LST_NFLR_SW", "msg", false, 50);
OwnSwitchMultiPos radarSw(&secondoPCF, P3, "msg", "RADAR_SW", false);
OwnSwitchMultiPos insSw(&secondoPCF, P4, "msg", "INS_SW", false);

// KY 58
OwnSwitchMultiPos ky58ModeSelect(&secondoPCF, P5, "msg", "KY58_MODE_SELECT",
                                 false);
OwnSwitchMultiPos ky58FillSelect(&secondoPCF, P6, "msg", "KY58_FILL_SELECT",
                                 false);
OwnSwitchMultiPos ky58PowerSelect(&secondoPCF, P7, "KY58_POWER_SELECT", "msg",
                                  50);

/* Main code */

void setup() {
  Serial.begin(115200);

  // 2 and 3 position switches reading pin setup
  pinMode(FST_SIMPLE_READ_PIN, INPUT);
  pinMode(SCND_SIMPLE_READ_PIN, INPUT);

  // Multi position switches reading pin setup
  /*
  pinMode(FRST_COMPLEX_READ_PIN, INPUT);
  pinMode(SCND_COMPLEX_READ_PIN, INPUT);
  pinMode(THRD_COMPLEX_READ_PIN, INPUT);
  pinMode(FRTH_COMPLEX_READ_PIN, INPUT);
  pinMode(FFTH_COMPLEX_READ_PIN, INPUT);
  pinMode(SXTH_COMPLEX_READ_PIN, INPUT);
  pinMode(SVTH_COMPLEX_READ_PIN, INPUT);
  pinMode(EGTH_COMPLEX_READ_PIN, INPUT);
  */

  // Potentiometers reading pin setup
  /*
  pinMode(ANALOG_READ_ADDR, INPUT);
  */

  /* Switches setup */

  /* PCF setup */

  firstoPCF.startPCF();
  secondoPCF.startPCF();
  thirdoPCF.startPCF();
}

/* Main loop */

void loop() {
  Serial.println("Updating batterySw");
  batterySw.update();
  delay(500);
  Serial.println("Updating ecsModeSw");
  ecsModeSw.update();
  delay(500);
  Serial.println("Updating cabinPressSw");
  cabinPressSw.update();
  delay(500);
  Serial.println("Updating engAntiiceSw");
  engAntiiceSw.update();
  delay(500);
  Serial.println("Updating lGenSw");
  lGenSw.update();
  delay(500);
  Serial.println("Updating rGenSw");
  rGenSw.update();
  delay(500);
  Serial.println("Updating pitotHeatSw");
  pitotHeatSw.update();
  delay(500);
  Serial.println("Updating lightsTestSw");
  lightsTestSw.update();
  delay(500);

  if (Serial.read() == '!') {
    Serial.print("State (");
    Serial.print("batterySw");
    Serial.print("): ");
    Serial.println(batterySw.readState());

    Serial.print("State (");
    Serial.print("ecsModeSw");
    Serial.print("): ");
    Serial.println(ecsModeSw.readState());

    Serial.print("State (");
    Serial.print("cabinPressSw");
    Serial.print("): ");
    Serial.println(cabinPressSw.readState());

    Serial.print("State (");
    Serial.print("engAntiiceSw");
    Serial.print("): ");
    Serial.println(engAntiiceSw.readState());

    Serial.print("State (");
    Serial.print("lGenSw");
    Serial.print("): ");
    Serial.println(lGenSw.readState());

    Serial.print("State (");
    Serial.print("rGenSw");
    Serial.print("): ");
    Serial.println(rGenSw.readState());

    Serial.print("State (");
    Serial.print("pitotHeatSw");
    Serial.print("): ");
    Serial.println(pitotHeatSw.readState());

    Serial.print("State (");
    Serial.print("lightsTestSw");
    Serial.print("): ");
    Serial.println(lightsTestSw.readState());
  }
}