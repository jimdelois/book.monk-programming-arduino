#include <Bounce2.h>

const int PIN_IN = 5;
const int PIN_LED = 13;

int ledValue;
Bounce bouncer = Bounce();

void setup() {
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_IN, INPUT_PULLUP);
  ledValue = LOW;
  bouncer.attach(PIN_IN);
}

void loop() {
  // OLD CODE, illustrating bouncing issues...
//  float switchOpen = digitalRead(PIN_IN);
//  if (!switchOpen) {
//    ledValue = !ledValue;
//    digitalWrite(PIN_LED, ledValue);
//  }

  // LOW is effectively the same as !switchOpen, above
  if (bouncer.update() && bouncer.read() == LOW) {
    ledValue = !ledValue;
    digitalWrite(PIN_LED, ledValue);
  }
}
