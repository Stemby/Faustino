#include <Keyboard.h>

#define BUTTON 7
#define DEBOUNCE_DELAY 499

long timecode = 0;

void setup() {
  pinMode(BUTTON, INPUT);
}

void loop() {
  if (digitalRead(BUTTON)) {
    if ((millis() - timecode) > DEBOUNCE_DELAY) {
      timecode = millis();
      Keyboard.begin();
      Keyboard.write('n');
    }
  }
}
