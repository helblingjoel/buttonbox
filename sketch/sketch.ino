
#include <Keyboard.h>
int buttonValue;
const int buttonPressCoolDownms = 500;

const int toggle0Pin = 0;
int toggle0State = 0;
int toggle0PreviousState = 0;

void setup() {
  Keyboard.begin();
  pinMode(toggle0Pin, INPUT);
}

void loop() {
  // Read states
  toggle0State = digitalRead(toggle0Pin);
  buttonValue = analogRead(A0);

  // Toggles
  if (toggle0State != toggle0PreviousState){
    toggle0PreviousState = toggle0State;
    Serial.println("Switch 0 toggled");
    delay(100);
  }

  
  // Buttons
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
