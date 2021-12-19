
#include <Keyboard.h>
int buttonValue;
void setup() {
  Keyboard.begin();
}

void loop() {
  buttonValue = 0;
  buttonValue = analogRead(A0);
}
