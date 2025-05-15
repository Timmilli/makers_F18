# About

This file contains all the definitions for all switchs and potentiometers for the left and right panel.

Mainly to be used if the project is persued.

The names of the panels are fixed according to the cockpit image.

The names of the potentiometers and switches are set according to DcsBios definitions.

## Right pannel

### FCCS Panel 
`
OwnSwitch2Pos avCoolSw(PCF_TO_BE_REPLACED, PIN_TO_BE_REPLACED, "AV_COOL_SW", "msg", false, 50);
`

### ELEC Panel
`
OwnSwitch2Pos lGenSw(OwnPCFs[0], FIFTH_PIN, "L_GEN_SW", "msg", false, 50);
`

`
OwnSwitch3Pos batterySw(OwnPCFs[0], FIRST_PIN, "BATTERY_SW", "msg", 50);
`

`
OwnSwitch2Pos rGenSw(OwnPCFs[0], SIXTH_PIN, "R_GEN_SW", "msg", false, 50);
`

### ECS Panel
`
OwnSwitch3Pos ecsModeSw(OwnPCFs[0], SECOND_PIN, "ECS_MODE_SW", "msg", 50);
`

`
OwnPotentiometer cabinTemp(OwnMultiplexes[0], "msg", FIRST_MLTPLX_PIN, "CABIN_TEMP", false, 0, 1023);
`

`
OwnPotentiometer suitTemp(OwnMultiplexes[0], "msg", SECOND_MLTPLX_PIN, "SUIT_TEMP", false, 0, 1023);
`

`
OwnSwitch3Pos cabinPressSw(OwnPCFs[0], THIRD_PIN, "CABIN_PRESS_SW", "msg", 50);
`

`
OwnSwitch2Pos pitotHeatSw(OwnPCFs[0], SEVENTH_PIN, "PITOT_HEAT_SW", "msg", false, 50);
`

`
OwnSwitch3Pos engAntiiceSw(OwnPCFs[0], FOURTH_PIN, "ENG_ANTIICE_SW", "msg", 50);
`

`
OwnSwitchMultiPos bleedAirKnob(OwnPCFs[1], THIRD_PIN, "msg", "BLEED_AIR_KNOB", false);
`

### INTR LT Panel
`
OwnPotentiometer consolesDimmer(OwnMultiplexes[0], "msg", THIRD_MLTPLX_PIN, "CONSOLES_DIMMER", false, 0, 1023);
`

`
OwnPotentiometer instPnlDimmer(OwnMultiplexes[0], "msg", FOURTH_MLTPLX_PIN, "INST_PNL_DIMMER", false, 0, 1023);
`

`
OwnPotentiometer floodDimmer(OwnMultiplexes[0], "msg", FIFTH_MLTPLX_PIN, "FLOOD_DIMMER", false, 0, 1023);
`

`
OwnSwitch2Pos lightsTestSw(OwnPCFs[0], EIGHTH_PIN, "LIGHTS_TEST_SW", "msg", false, 50);
`

`
OwnPotentiometer warnCautionDimmer(OwnMultiplexes[0], "msg", SIXTH_MLTPLX_PIN, "WARN_CAUTION_DIMMER", false, 0, 1023);
`

`
OwnPotentiometer chartDimmer(OwnMultiplexes[0], "msg", SEVENTH_MLTPLX_PIN, "CHART_DIMMER", false, 0, 1023);
`

`
OwnSwitch3Pos cockkpitLightModeSw(OwnPCFs[1], FIRST_PIN, "COCKKPIT_LIGHT_MODE_SW", "msg", 50);
`

### DEFOG Panel
`
OwnSwitch3Pos wshieldAntiIceSw(PCF_to_be_replaced, PIN_to_be_replaced, "WSHIELD_ANTI_ICE_SW", "msg", 50);
`

`
OwnPotentiometer defogHandle(MULTIPLEXER_to_be_replaced, "msg", FIRST_PIN, "DEFOG_HANDLE", false, 0, 1023);
`

### SNSR Panel
`
OwnSwitch3Pos flirSw(OwnPCFs[2], FOURTH_PIN, "FLIR_SW", "msg", 50);
`

`
OwnSwitch2Pos ltdRSw(OwnPCFs[1], SECOND_PIN, "LTD_R_SW", "msg", false, 50);
`

`
OwnSwitch2Pos lstNflrSw(OwnPCFs[2], FIFTH_PIN, "LST_NFLR_SW", "msg", false, 50);
`

`
OwnSwitchMultiPos radarSw(OwnPCFs[1], FOURTH_PIN, "msg", "RADAR_SW", false);
`

`
OwnSwitchMultiPos insSw(OwnPCFs[1], FIFTH_PIN, "msg", "INS_SW", false);
`

### KY58 Panel
On this panel, only the fill cable slot lasts undifined as it surely won't be used.

`
OwnSwitchMultiPos ky58ModeSelect(OwnPCFs[1], SIXTH_PIN, "msg", "KY58_MODE_SELECT", false);
`

`
OwnSwitchMultiPos ky58FillSelect(OwnPCFs[1], SEVENTH_PIN, "msg", "KY58_FILL_SELECT", false);
`

`
OwnSwitchMultiPos ky58PowerSelect(OwnPCFs[1], EIGHTH_PIN, "KY58_POWER_SELECT", "msg", 50);
`

`
OwnPotentiometer ky58Volume(MULTIPLEXER_to_be_replaced, "msg", FIRST_PIN, "KY58_VOLUME", false, 0, 1023);
`



### FCS BIT Panel
`
OwnSwitch2Pos cbFcsChan3(PCF_to_be_replaced, PIN_to_be_replaced, "CB_FCS_CHAN3", "msg", false, 50);
`

`
OwnSwitch2Pos cbFcsChan4(PCF_to_be_replaced, PIN_to_be_replaced, "CB_FCS_CHAN4", "msg", false, 50);
`

`
OwnSwitch2Pos cbHoook(PCF_to_be_replaced, PIN_to_be_replaced, "CB_HOOOK", "msg", false, 50);
`

`
OwnSwitch2Pos cbLg(PCF_to_be_replaced, PIN_to_be_replaced, "CB_LG", "msg", false, 50);
`

`
OwnSwitch2Pos fcsBitSw(PCF_to_be_replaced, PIN_to_be_replaced, "FCS_BIT_SW", "msg", false, 50);
`

## Left Panel

### JETTISON Panel
`
OwnSwitch2Pos launchBarSw(PCF_to_be_replaced, PIN_to_be_replaced, "LAUNCH_BAR_SW", "msg", false, 50);
`

`
OwnSwitch3Pos flapSw(PCF_to_be_replaced, PIN_to_be_replaced, "FLAP_SW", "msg", 50);
`

`
OwnSwitch2Pos ldgTaxiSw(BCFTBR, PTBR, "LDG_TAXI_SW", "msg", false, 50);
`

`
OwnSwitch2Pos antiSkidSw(PCF_to_be_replaced, PIN_to_be_replaced, "ANTI_SKID_SW", "msg", false, 50);
`

`
OwnSwitch2Pos hookBypassSw(PCF_to_be_replaced, PIN_to_be_replaced, "HOOK_BYPASS_SW", "msg", false, 50);
`

`
OwnSwitch2Pos selJettBtn(PCF_to_be_replaced, PIN_to_be_replaced, "SEL_JETT_BTN", "msg", false, 50);
`

`
OwnSwitchMultiPos selJettKnob(PCF_to_be_replaced, PIN_to_be_replaced, "SEL_JETT_KNOB", "msg", 50);
`

### FIRE Panel
`
OwnSwitch3Pos fireTestSw(PCF_to_be_replaced, PIN_to_be_replaced, "FIRE_TEST_SW", "msg", 50);
`

### GND PWR Panel
`
OwnSwitch3Pos gndPwr1Sw(PCF_to_be_replaced, PIN_to_be_replaced, "GND_PWR_1_SW", "msg", 50);
`

`
OwnSwitch3Pos gndPwr2Sw(PCF_to_be_replaced, PIN_to_be_replaced, "GND_PWR_2_SW", "msg", 50);
`

`
OwnSwitch3Pos gndPwr3Sw(PCF_to_be_replaced, PIN_to_be_replaced, "GND_PWR_3_SW", "msg", 50);
`

`
OwnSwitch3Pos gndPwr4Sw(PCF_to_be_replaced, PIN_to_be_replaced, "GND_PWR_4_SW", "msg", 50);
`

`
OwnSwitch3Pos extPwrSw(PCF_to_be_replaced, PIN_to_be_replaced, "EXT_PWR_SW", "msg", 50);
`

### Gaz handle

I haven't worked on getting this monster working.

### EXT LIGHTS Panel
`
OwnSwitch3Pos strobeSw(PCF_to_be_replaced, PIN_to_be_replaced, "STROBE_SW", "msg", 50);
`

`
OwnSwitch2Pos intWngTankSw(PCF_to_be_replaced, PIN_to_be_replaced, "INT_WNG_TANK_SW", "msg", false, 50);
`

`
OwnPotentiometer formationDimmer(MULTIPLEXER_to_be_replaced, "msg", FIRST_PIN, "FORMATION_DIMMER", false, 0, 1023);
`

`
OwnPotentiometer positionDimmer(MULTIPLEXER_to_be_replaced, "msg", FIRST_PIN, "POSITION_DIMMER", false, 0, 1023);
`

### FUEL Panel
`
OwnSwitch3Pos probeSw(PCF_to_be_replaced, PIN_to_be_replaced, "PROBE_SW", "msg", 50);
`

`
OwnSwitch3Pos extWngTankSw(PCF_to_be_replaced, PIN_to_be_replaced, "EXT_WNG_TANK_SW", "msg", 50);
`

`
OwnSwitch3Pos extCntTankSw(PCF_to_be_replaced, PIN_to_be_replaced, "EXT_CNT_TANK_SW", "msg", 50);
`

`
OwnSwitch2Pos fuelDumpSw(PCF_to_be_replaced, PIN_to_be_replaced, "FUEL_DUMP_SW", "msg", false, 50);
`

### APU Panel
`
OwnSwitch2Pos apuFireBtn(PCF_to_be_replaced, PIN_to_be_replaced, "APU_FIRE_BTN", "msg", false, 50);
`

`
OwnSwitch3Pos engineCrankSw(PCF_to_be_replaced, PIN_to_be_replaced, "ENGINE_CRANK_SW", "msg", 50);
`

### ANT SEL Panel
`
OwnSwitch3Pos iffAntSelectSw(PCF_to_be_replaced, PIN_to_be_replaced, "IFF_ANT_SELECT_SW", "msg", 50);
`

`
OwnSwitch3Pos comm1AntSelectSw(PCF_to_be_replaced, PIN_to_be_replaced, "COMM1_ANT_SELECT_SW", "msg", 50);
`

### COMMUNICATION Panel
`
OwnSwitch3Pos comCommRelaySw(PCF_to_be_replaced, PIN_to_be_replaced, "COM_COMM_RELAY_SW", "msg", 50);
`

`
OwnSwitch3Pos comCommGXmtSw(PCF_to_be_replaced, PIN_to_be_replaced, "COM_COMM_G_XMT_SW", "msg", 50);
`

`
OwnSwitch2Pos comIlsUfcManSw(PCF_to_be_replaced, PIN_to_be_replaced, "COM_ILS_UFC_MAN_SW", "msg", false, 50);
`

`
OwnSwitch3Pos comCryptoSw(PCF_to_be_replaced, PIN_to_be_replaced, "COM_CRYPTO_SW", "msg", 50);
`

`
OwnSwitch3Pos comIffMode4Sw(PCF_to_be_replaced, PIN_to_be_replaced, "COM_IFF_MODE4_SW", "msg", 50);
`

`
OwnSwitch2Pos comIffMasterSw(PCF_to_be_replaced, PIN_to_be_replaced, "COM_IFF_MASTER_SW", "msg", false, 50);
`

`
OwnPotentiometer comAux(MULTIPLEXER_to_be_replaced, "msg", FIRST_PIN, "COM_AUX", false, 0, 1023);
`

`
OwnPotentiometer comIcs(MULTIPLEXER_to_be_replaced, "msg", FIRST_PIN, "COM_ICS", false, 0, 1023);
`

`
OwnPotentiometer comMidsA(MULTIPLEXER_to_be_replaced, "msg", FIRST_PIN, "COM_MIDS_A", false, 0, 1023);
`

`
OwnPotentiometer comMidsB(MULTIPLEXER_to_be_replaced, "msg", FIRST_PIN, "COM_MIDS_B", false, 0, 1023);
`

`
OwnPotentiometer comRwr(MULTIPLEXER_to_be_replaced, "msg", FIRST_PIN, "COM_RWR", false, 0, 1023);
`

`
OwnPotentiometer comTacan(MULTIPLEXER_to_be_replaced, "msg", FIRST_PIN, "COM_TACAN", false, 0, 1023);
`

`
OwnPotentiometer comVox(MULTIPLEXER_to_be_replaced, "msg", FIRST_PIN, "COM_VOX", false, 0, 1023);
`

`
OwnPotentiometer comWpn(MULTIPLEXER_to_be_replaced, "msg", FIRST_PIN, "COM_WPN", false, 0, 1023);
`

`
OwnSwitchMultiPos comIlsChannelSw(PCF_to_be_replaced, PIN_to_be_replaced, "COM_ILS_CHANNEL_SW", "msg", 50); 
`

This last multi-position switch needs to be studied further as it has 20 positions and the actual architecture only works with 8 positions at most.

### LOX Panel
`
OwnSwitch2Pos obogsSw(PCF_to_be_replaced, PIN_to_be_replaced, "OBOGS_SW", "msg", false, 50);
`

`
OwnPotentiometer oxyFlow(MULTIPLEXER_to_be_replaced, "msg", FIRST_PIN, "OXY_FLOW", false, 0, 1023);
`

### Mission Computer and Hydraulic Isolate Panel
`
OwnSwitch3Pos mcSw(PCF_to_be_replaced, PIN_to_be_replaced, "MC_SW", "msg", 50);
`

`
OwnSwitch2Pos hydIsolateOverrideSw(PCF_to_be_replaced, PIN_to_be_replaced, "HYD_ISOLATE_OVERRIDE_SW", "msg", false, 50);
`

## Front panel

This one hasn't been studied as the number of screens and motos involved makes it more complex.

Yet, buttons can works as 2 positions switches.

