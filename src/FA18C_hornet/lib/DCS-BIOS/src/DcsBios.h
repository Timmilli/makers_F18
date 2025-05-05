#ifndef __DCSBIOS_H
#define __DCSBIOS_H

#ifndef NULL
#define NULL 0
#endif

#include <stdint.h>

#ifdef DCSBIOS_FOR_STM32
#include <itoa.h>
#endif

#include "internal/Addresses.h"
#include "internal/ExportStreamListener.h"
#include "internal/PollingInput.h"
#include "internal/Protocol.h"

#ifndef USART0_RX_vect
#define USART0_RX_vect USART_RX_vect
#define USART0_TX_vect USART_TX_vect
#define USART0_UDRE_vect USART_UDRE_vect
#endif

#ifndef PRR0
#define PRR0 PRR
#endif

namespace DcsBios {
const unsigned char PIN_NC = 0xFF;
}

/*
The following is an ugly hack to work with the Arduino IDE's build system.
The DCS-BIOS Arduino Library is configured with #defines such as
DCSBIOS_RS485_MASTER or DCSBIOS_RS485_SLAVE <address>. To make sure these
defines are visible when compiling the code, we can't put it into a separate
translation unit.

Normally, those #defines would go in a separate "config.h" or you would use
compiler flags. But since Arduino libraries do not come with their own build
system, we are just putting everything into the header file.
*/
#ifdef DCSBIOS_DEFAULT_SERIAL
namespace DcsBios {
void setup();
void loop();
bool tryToSendDcsBiosMessage(const char *msg, const char *arg);
void resetAllStates();
} // namespace DcsBios
#endif

#include "internal/Buttons.h"
#include "internal/Encoders.h"
#include "internal/Leds.h"
#include "internal/Potentiometers.h"
#include "internal/RotarySyncingPotentiometer.h"
#include "internal/Switches.h"
#include "internal/SyncingSwitches.h"
#ifdef DCSBIOS_ENABLE_SERVO
#include "internal/Servos.h"
#endif
#include "internal/AnalogMultiPos.h"
#include "internal/BcdWheels.h"
#include "internal/Dimmer.h"
#include "internal/RotarySwitch.h"
#if defined(USE_MATRIX_SWITCHES) || defined(DCSBIOS_USE_MATRIX_SWITCHES)
#include "internal/MatrixSwitches.h"
#endif
#include "internal/DualModeButton.h"

namespace DcsBios {
template <unsigned int first, unsigned int second>
unsigned int piecewiseMap(unsigned int newValue) {
  return 0;
}

template <unsigned int from1, unsigned int to1, unsigned int from2,
          unsigned int to2, unsigned int... rest>
unsigned int piecewiseMap(unsigned int newValue) {
  if (newValue < from2) {
    return map(newValue, from1, from2, to1, to2);
  } else {
    return piecewiseMap<from2, to2, rest...>(newValue);
  }
}
} // namespace DcsBios

#ifndef DCSBIOS_RS485_MASTER
namespace DcsBios {
inline bool sendDcsBiosMessage(const char *msg, const char *arg) {
  while (!tryToSendDcsBiosMessage(msg, arg))
    ;
  return true;
}
} // namespace DcsBios

// // for backwards compatibility, can be removed when we have a proper place to
// // document this interface:
// inline bool sendDcsBiosMessage(const char *msg, const char *arg) {
//   while (!DcsBios::tryToSendDcsBiosMessage(msg, arg))
//     ;
//   return true;
// }
#endif

#endif // include guard
