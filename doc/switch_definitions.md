// FCCS Panel
OwnSwitch2Pos avCoolSw(OwnPCFs[0], 1, "AV_COOL_SW", "msg", false, 50);

// ELEC Panel
OwnSwitch3Pos batterySw(OwnPCFs[0], 1, 2, "BATTERY_SW", "msg", 50);
OwnSwitch2Pos lGenSw(OwnPCFs[0], 1, "L_GEN_SW", "msg", false, 50);
OwnSwitch2Pos rGenSw(OwnPCFs[0], 1, "R_GEN_SW", "msg", false, 50);

// ECS Panel
OwnSwitch3Pos ecsModeSw(OwnPCFs[0], 1, 2, "ECS_MODE_SW", "msg", 50);
OwnSwitch3Pos cabinPressSw(OwnPCFs[0], 1, 2, "CABIN_PRESS_SW", "msg", 50);
OwnSwitch3Pos engAntiiceSw(OwnPCFs[0], 1, 2, "ENG_ANTIICE_SW", "msg", 50);
OwnSwitch2Pos pitotHeatSw(OwnPCFs[0], 1, "PITOT_HEAT_SW", "msg", false, 50);

// INTR LT Panel
OwnSwitch3Pos cockkpitLightModeSw(OwnPCFs[0], 1, 2, "COCKKPIT_LIGHT_MODE_SW",
                                  "msg", 50);
OwnSwitch2Pos lightsTestSw(OwnPCFs[0], 1, "LIGHTS_TEST_SW", "msg", false, 50);
OwnPotentiometer chartDimmer(OwnMultiplexes[0], "msg", FIRST_PIN,
                             "CHART_DIMMER", false, 0, 1023);
OwnPotentiometer consolesDimmer(OwnMultiplexes[0], "msg", FIRST_PIN,
                                "CONSOLES_DIMMER", false, 0, 1023);
OwnPotentiometer floodDimmer(OwnMultiplexes[0], "msg", FIRST_PIN,
                             "FLOOD_DIMMER", false, 0, 1023);
OwnPotentiometer instPnlDimmer(OwnMultiplexes[0], "msg", FIRST_PIN,
                               "INST_PNL_DIMMER", false, 0, 1023);
OwnPotentiometer warnCautionDimmer(OwnMultiplexes[0], "msg", FIRST_PIN,
                                   "WARN_CAUTION_DIMMER", false, 0, 1023);

// DEFOG Panel
OwnSwitch3Pos wshieldAntiIceSw(OwnPCFs[0], 1, 2, "WSHIELD_ANTI_ICE_SW", "msg",
                               50);
OwnPotentiometer defogHandle(OwnMultiplexes[0], "msg", FIRST_PIN,
                             "DEFOG_HANDLE", false, 0, 1023);

// SNSR Panel
OwnSwitch3Pos flirSw(OwnPCFs[0], 1, 2, "FLIR_SW", "msg", 50);
OwnSwitch2Pos ltdRSw(OwnPCFs[0], 1, "LTD_R_SW", "msg", false, 50);
OwnSwitch2Pos lstNflrSw(OwnPCFs[0], 1, "LST_NFLR_SW", "msg", false, 50);
// TODO include multi-position switches

// KY58 Panel
OwnSwitch3Pos ky58PowerSelect(OwnPCFs[0], 1, 2, "KY58_POWER_SELECT", "msg",
                              false, 50);
OwnPotentiometer ky58Volume(OwnMultiplexes[0], "msg", FIRST_PIN, "KY58_VOLUME",
                            false, 0, 1023);
// TODO include multi-position switches

// FCS BIT Panel
OwnSwitch2Pos fcsBitSw(OwnPCFs[0], 1, "FCS_BIT_SW", "msg", false, 50);

// JETTISON Panel
OwnSwitch2Pos launchBarSw(OwnPCFs[0], 1, "LAUNCH_BAR_SW", "msg", false, 50);
OwnSwitch3Pos flapSw(OwnPCFs[0], 1, 2, "FLAP_SW", "msg", 50);
OwnSwitch2Pos ldgTaxiSw(OwnPCFs[0], 1, "LDG_TAXI_SW", "msg", false, 50);
OwnSwitch2Pos antiSkidSw(OwnPCFs[0], 1, "ANTI_SKID_SW", "msg", false, 50);
OwnSwitch2Pos hookBypassSw(OwnPCFs[0], 1, "HOOK_BYPASS_SW", "msg", false, 50);

// FIRE Panel
OwnSwitch3Pos fireTestSw(OwnPCFs[0], 1, 2, "FIRE_TEST_SW", "msg", 50);

// GND PWR Panel
OwnSwitch3Pos gndPwr1Sw(OwnPCFs[0], 1, 2, "GND_PWR_1_SW", "msg", 50);
OwnSwitch3Pos gndPwr2Sw(OwnPCFs[0], 1, 2, "GND_PWR_2_SW", "msg", 50);
OwnSwitch3Pos gndPwr3Sw(OwnPCFs[0], 1, 2, "GND_PWR_3_SW", "msg", 50);
OwnSwitch3Pos gndPwr4Sw(OwnPCFs[0], 1, 2, "GND_PWR_4_SW", "msg", 50);
OwnSwitch3Pos extPwrSw(OwnPCFs[0], 1, 2, "EXT_PWR_SW", "msg", 50);

// EXT LIGHTS Panel
OwnSwitch3Pos strobeSw(OwnPCFs[0], 1, 2, "STROBE_SW", "msg", 50);
OwnSwitch2Pos intWngTankSw(OwnPCFs[0], 1, "INT_WNG_TANK_SW", "msg", false, 50);
OwnPotentiometer formationDimmer(OwnMultiplexes[0], "msg", FIRST_PIN,
                                 "FORMATION_DIMMER", false, 0, 1023);
OwnPotentiometer positionDimmer(OwnMultiplexes[0], "msg", FIRST_PIN,
                                "POSITION_DIMMER", false, 0, 1023);

// FUEL Panel
OwnSwitch3Pos probeSw(OwnPCFs[0], 1, 2, "PROBE_SW", "msg", 50);
OwnSwitch3Pos extWngTankSw(OwnPCFs[0], 1, 2, "EXT_WNG_TANK_SW", "msg", 50);
OwnSwitch3Pos extCntTankSw(OwnPCFs[0], 1, 2, "EXT_CNT_TANK_SW", "msg", 50);
OwnSwitch2Pos fuelDumpSw(OwnPCFs[0], 1, "FUEL_DUMP_SW", "msg", false, 50);

// APU Panel
OwnSwitch2Pos apuFireBtn(OwnPCFs[0], 1, "APU_FIRE_BTN", "msg", false, 50);
OwnSwitch3Pos engineCrankSw(OwnPCFs[0], 1, 2, "ENGINE_CRANK_SW", "msg", 50);

// ANT SEL Panel
OwnSwitch3Pos iffAntSelectSw(OwnPCFs[0], 1, 2, "IFF_ANT_SELECT_SW", "msg", 50);
OwnSwitch3Pos comm1AntSelectSw(OwnPCFs[0], 1, 2, "COMM1_ANT_SELECT_SW", "msg",
                               50);

// COMMUNICATION Panel
OwnSwitch3Pos comCommRelaySw(OwnPCFs[0], 1, 2, "COM_COMM_RELAY_SW", "msg", 50);
OwnSwitch3Pos comCommGXmtSw(OwnPCFs[0], 1, 2, "COM_COMM_G_XMT_SW", "msg", 50);
OwnSwitch2Pos comIlsUfcManSw(OwnPCFs[0], 1, "COM_ILS_UFC_MAN_SW", "msg", false,
                             50);
OwnSwitch3Pos comCryptoSw(OwnPCFs[0], 1, 2, "COM_CRYPTO_SW", "msg", 50);
OwnSwitch3Pos comIffMode4Sw(OwnPCFs[0], 1, 2, "COM_IFF_MODE4_SW", "msg", 50);
OwnSwitch2Pos comIffMasterSw(OwnPCFs[0], 1, "COM_IFF_MASTER_SW", "msg", false,
                             50);
OwnPotentiometer comAux(OwnMultiplexes[0], "msg", FIRST_PIN, "COM_AUX", false,
                        0, 1023);
OwnPotentiometer comIcs(OwnMultiplexes[0], "msg", FIRST_PIN, "COM_ICS", false,
                        0, 1023);
OwnPotentiometer comMidsA(OwnMultiplexes[0], "msg", FIRST_PIN, "COM_MIDS_A",
                          false, 0, 1023);
OwnPotentiometer comMidsB(OwnMultiplexes[0], "msg", FIRST_PIN, "COM_MIDS_B",
                          false, 0, 1023);
OwnPotentiometer comRwr(OwnMultiplexes[0], "msg", FIRST_PIN, "COM_RWR", false,
                        0, 1023);
OwnPotentiometer comTacan(OwnMultiplexes[0], "msg", FIRST_PIN, "COM_TACAN",
                          false, 0, 1023);
OwnPotentiometer comVox(OwnMultiplexes[0], "msg", FIRST_PIN, "COM_VOX", false,
                        0, 1023);
OwnPotentiometer comWpn(OwnMultiplexes[0], "msg", FIRST_PIN, "COM_WPN", false,
                        0, 1023);
// TODO include multi-position switch

// LOX Panel
OwnSwitch2Pos obogsSw(OwnPCFs[0], 1, "OBOGS_SW", "msg", false, 50);
OwnPotentiometer oxyFlow(OwnMultiplexes[0], "msg", FIRST_PIN, "OXY_FLOW", false,
                         0, 1023);

// Mission Computer and Hydraulic Isolate Panel
OwnSwitch3Pos mcSw(OwnPCFs[0], 1, 2, "MC_SW", "msg", 50);
OwnSwitch2Pos hydIsolateOverrideSw(OwnPCFs[0], 1, "HYD_ISOLATE_OVERRIDE_SW",
                                   "msg", false, 50);