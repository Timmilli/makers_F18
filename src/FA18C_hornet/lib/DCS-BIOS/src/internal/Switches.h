#ifndef __DCSBIOS_SWITCHES_H
#define __DCSBIOS_SWITCHES_H

#include "Arduino.h"
#include <math.h>

namespace DcsBios {
template <unsigned long pollIntervalMs = POLL_EVERY_TIME>
class Switch2PosT : PollingInput, public ResettableInput {
private:
  const char *msg_;
  char debounceSteadyState_;
  int lastState_;
  bool reverse_;
  unsigned long debounceDelay_;
  unsigned long lastDebounceTime = 0;

  void resetState() { lastState_ = (lastState_ == 0) ? -1 : 0; }

  void pollInput() {
    int state = readState();
    if (reverse_)
      state = !state;

    unsigned long now = millis();

    if (state != debounceSteadyState_) {
      lastDebounceTime = now;
      debounceSteadyState_ = state;
    }

    if ((now - lastDebounceTime) >= debounceDelay_) {
      if (debounceSteadyState_ != lastState_) {
        if (tryToSendDcsBiosMessage(msg_, state == HIGH ? "0" : "1")) {
          lastState_ = debounceSteadyState_;
        }
      }
    }
  }

public:
  Switch2PosT() : PollingInput(pollIntervalMs) {}

  Switch2PosT(const char *msg, bool reverse = false,
              unsigned long debounceDelay = 50)
      : PollingInput(pollIntervalMs) {
    msg_ = msg;
    debounceDelay_ = debounceDelay;
    reverse_ = reverse;

    if (reverse_)
      lastState_ = !lastState_;
  }

  void setAttributes(const char *msg, int lastState, bool reverse,
                     unsigned long debounceDelay) {
    msg_ = msg;
    debounceDelay_ = debounceDelay;
    reverse_ = reverse;

    lastState_ = lastState;
    if (reverse_)
      lastState_ = !lastState_;
  }

  void SetControl(const char *msg) { msg_ = msg; }

  virtual int readState();

  void resetThisState() { this->resetState(); }
};
typedef Switch2PosT<> Switch2Pos;

template <unsigned long pollIntervalMs = POLL_EVERY_TIME,
          unsigned long coverDelayMs = 200>
class SwitchWithCover2PosT : PollingInput, public ResettableInput {
private:
  const char *switchMsg_;
  const char *coverMsg_;
  char pin_;
  int lastState_;
  char switchState_;
  bool reverse_;
  unsigned long debounceDelay_;
  unsigned long lastDebounceTime = 0;

  enum switchCoverStateEnum { stOFF_CLOSED = 0, stOFF_OPEN = 1, stON_OPEN = 2 };

  switchCoverStateEnum switchCoverState_;
  unsigned long lastSwitchStateTime;

  void resetState() {
    lastState_ = (lastState_ == 0) ? -1 : 0;

    if (switchState_ && !reverse_)
      switchCoverState_ = stOFF_CLOSED;
    else
      switchCoverState_ = stON_OPEN;
    lastSwitchStateTime = millis();
  }

  void pollInput() {
    char state = digitalRead(pin_);
    if (reverse_)
      state = !state;
    if (state != lastState_) {
      lastDebounceTime = millis();
    }

    if (state != switchState_ &&
        (millis() - lastDebounceTime) > debounceDelay_) {
      // Switch has debounced and changed state
      if (millis() - lastSwitchStateTime > coverDelayMs) {
        // Switch/cover delay has been satisfied.
        if (state) {
          // Closing/turning off
          switch (switchCoverState_) {
          case stON_OPEN:
            if (tryToSendDcsBiosMessage(switchMsg_, "0")) {
              switchCoverState_ = stOFF_OPEN;
              lastSwitchStateTime = millis();
            }
            break;

          case stOFF_OPEN:
            if (tryToSendDcsBiosMessage(coverMsg_, "0")) {
              switchCoverState_ = stOFF_CLOSED;
              lastSwitchStateTime = millis();
              switchState_ = state;
            }
            break;

          case stOFF_CLOSED:
            // Converged on steady state.  Good.
            break;
          }
        } else {
          // Opening/turning on
          switch (switchCoverState_) {
          case stOFF_CLOSED:
            if (tryToSendDcsBiosMessage(coverMsg_, "1")) {
              switchCoverState_ = stOFF_OPEN;
              lastSwitchStateTime = millis();
            }
            break;

          case stOFF_OPEN:
            if (tryToSendDcsBiosMessage(switchMsg_, "1")) {
              switchCoverState_ = stON_OPEN;
              lastSwitchStateTime = millis();
              switchState_ = state;
            }
            break;

          case stON_OPEN:
            // Converged on steady state.  Good.
            break;
          }
        }
      }
    }

    lastState_ = state;
  }

public:
  SwitchWithCover2PosT(const char *switchMessage, const char *coverMessage,
                       char pin, bool reverse = false,
                       unsigned long debounceDelay = 50)
      : PollingInput(pollIntervalMs) {
    switchMsg_ = switchMessage;
    coverMsg_ = coverMessage;
    pin_ = pin;
    pinMode(pin_, INPUT_PULLUP);
    switchState_ = digitalRead(pin_);
    lastState_ = switchState_;
    reverse_ = reverse;
    debounceDelay_ = debounceDelay;

    resetState();
  }

  void resetThisState() { this->resetState(); }
};
typedef SwitchWithCover2PosT<> SwitchWithCover2Pos;

template <unsigned long pollIntervalMs = POLL_EVERY_TIME>
class Switch3PosT : PollingInput, public ResettableInput {
private:
  const char *msg_;
  int lastState_;
  char debounceSteadyState_;
  unsigned long debounceDelay_;
  unsigned long lastDebounceTime = 0;

  void resetState() { lastState_ = (lastState_ == 0) ? -1 : 0; }
  void pollInput() {
    int state = readState();
    unsigned long now = millis();
    if (state != debounceSteadyState_) {
      lastDebounceTime = now;
      debounceSteadyState_ = state;
    }

    if ((now - lastDebounceTime) >= debounceDelay_) {
      if (state != lastState_) {
        if (state == 0) {
          if (tryToSendDcsBiosMessage(msg_, "0"))
            lastState_ = state;
        } else if (state == 1) {
          if (tryToSendDcsBiosMessage(msg_, "1"))
            lastState_ = state;
        } else if (state == 2) {
          if (tryToSendDcsBiosMessage(msg_, "2"))
            lastState_ = state;
        }
      }
    }
  }

public:
  Switch3PosT() : PollingInput(pollIntervalMs) {}
  Switch3PosT(const char *msg, unsigned long debounceDelay = 50)
      : PollingInput(pollIntervalMs) {
    msg_ = msg;
    lastState_ = readState();
    debounceSteadyState_ = lastState_;
    debounceDelay_ = debounceDelay;
  }

  virtual int readState();

  void setAttributes(const char *msg, int lastState,
                     unsigned long debounceDelay = 50) {
    msg_ = msg;
    lastState_ = lastState;
    debounceSteadyState_ = lastState_;
    debounceDelay_ = debounceDelay;
  }

  void SetControl(const char *msg) { msg_ = msg; }

  void resetThisState() { this->resetState(); }
};
typedef Switch3PosT<> Switch3Pos;

template <unsigned long pollIntervalMs = POLL_EVERY_TIME>
class SwitchMultiPosT : PollingInput, public ResettableInput {
private:
  const char *msg_;
  const byte *pins_;
  char numberOfPins_;
  int lastState_;
  bool reverse_;
  void resetState() { lastState_ = (lastState_ == 0) ? -1 : 0; }
  void pollInput() {
    int state = readState();
    if (state != lastState_) {
      char buf[7];
      utoa(state, buf, 10);
      if (tryToSendDcsBiosMessage(msg_, buf))
        lastState_ = state;
    }
  }

public:
  SwitchMultiPosT() : PollingInput(pollIntervalMs), lastState_(0) {}
  SwitchMultiPosT(const char *msg, const byte *pins, char numberOfPins,
                  bool reverse = false)
      : PollingInput(pollIntervalMs), lastState_(0) {
    msg_ = msg;
    pins_ = pins;
    reverse_ = reverse;
    numberOfPins_ = numberOfPins;
    unsigned char i;
    for (i = 0; i < numberOfPins; i++) {
      if (pins[i] != PIN_NC)
        pinMode(pins[i], INPUT_PULLUP);
    }
    lastState_ = readState();
  }

  virtual int readState();

  void setAttributes(const char *msg, bool reverse) {
    msg_ = msg;
    reverse_ = reverse;
  }

  void SetControl(const char *msg) { msg_ = msg; }

  void resetThisState() { this->resetState(); }
};
typedef SwitchMultiPosT<> SwitchMultiPos;

} // namespace DcsBios

#endif