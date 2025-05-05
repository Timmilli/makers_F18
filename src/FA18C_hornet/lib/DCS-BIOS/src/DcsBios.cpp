#include "DcsBios.h"

namespace DcsBios {
void setup() { Serial.begin(250000); }
void loop() {
  ProtocolParser parser;
  while (Serial.available()) {
    parser.processChar(Serial.read());
  }
  PollingInput::pollInputs();
  ExportStreamListener::loopAll();
}
bool tryToSendDcsBiosMessage(const char *msg, const char *arg) {
  Serial.write(msg);
  Serial.write(' ');
  Serial.write(arg);
  Serial.write('\n');
  DcsBios::PollingInput::setMessageSentOrQueued();
  return true;
}
void resetAllStates() { PollingInput::resetAllStates(); }
} // namespace DcsBios