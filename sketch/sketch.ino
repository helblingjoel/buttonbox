
#include <Keyboard.h>
int buttonValue;
int buttonPressCoolDownms = 500;
void setup() {
  Keyboard.begin();
}

void loop() {
  buttonValue = analogRead(A0);

  if (buttonValue >= 200 && buttonValue <= 220) {
    buttonPress(0, analogRead(A0));
  }
  else if (buttonValue >= 240 && buttonValue <= 280) {
    buttonPress(1, analogRead(A0));
  }
  else if (buttonValue >= 300 && buttonValue <= 400) {
    buttonPress(2, analogRead(A0));
  }
  else if (buttonValue >= 490 && buttonValue <= 550) {
    buttonPress(3, analogRead(A0));
  }
  else if (buttonValue >= 1000) {
    buttonPress(4, analogRead(A0));
  }
}

void buttonPress(int buttonId, int entryReading) {
  Serial.println(buttonId);
  delay(buttonPressCoolDownms);
}
