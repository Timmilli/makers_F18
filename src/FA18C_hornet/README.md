# FA18C_hornet

This is the directory for the Platformio project.

It contains everything to make the software work.

## Organisation

FA18C\_hornet
|--lib
   |
   |--Adafruit\_BusIO
      |- ...
   |
   |--Adafruit\_PCF8574
      |- Adafruit\_PCF8574.h
      |- ...
   |
   |--Constants
      |- Constants.h
   |
   |--DCS-BIOS
      |--src
      |  |- DcsBios.h
      |  |--internal
      |  |  |- ...
      |- ...
   |
   |--OwnMultiplex
      |- OwnMultiplex.c
      |- OwnMultiplex.h
   |
   |--OwnPCF
      |- OwnPCF.c
      |- OwnPCF.h
   |
   |--OwnPotentiometer
      |- OwnPotentiometer.c
      |- OwnPotentiometer.h
   |
   |--OwnSwitch
      |- OwnSwitch.c
      |- OwnSwitch.h
   |
   |- README
|
|--src
   |- main.c
|- platformio.ini
|- README --> THIS FILE

## Usage

As everything is already preinstalled, only the main needs to be compiled and transfered on the ESP32.
