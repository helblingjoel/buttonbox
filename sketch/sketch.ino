#include <Joystick.h>
#include <Keyboard.h>

// Buttons
int buttonValue;
const int buttonPressCoolDownms = 500;

// Pin ID, Current State, Previous State
int toggle0[3] = [0, 0, 0];
int toggle1[3] = [1, 0, 0];
int toggle2[3] = [2, 0, 0];
int toggle3[3] = [3, 0, 0];
int toggle4[3] = [4, 0, 0];

// Keyboard keys
#define KEYCODE_F13 0x68
#define KEYCODE_F14 0x69
#define KEYCODE_F15 0x6A
#define KEYCODE_F16 0x6B
#define KEYCODE_F17 0x6C
#define KEYCODE_F18 0x6D
#define KEYCODE_F19 0x6E
#define KEYCODE_F20 0x6F
#define KEYCODE_F21 0x70
#define KEYCODE_F22 0x71
#define KEYCODE_F23 0x72
#define KEYCODE_F24 0x73
#define KEYCODE_SHIFT 0x81

void setup() {
  Keyboard.begin();
  pinMode(toggle0[0], INPUT);
  pinMode(toggle1[0], INPUT);
  pinMode(toggle2[0], INPUT);
  pinMode(toggle3[0], INPUT);
  pinMode(toggle4[0], INPUT);
}

void loop() {
  // Read states
  toggle0[1] = digitalRead(toggle0[0]);
  toggle1[1] = digitalRead(toggle1[0]);
  toggle2[1] = digitalRead(toggle2[0]);
  toggle3[1] = digitalRead(toggle3[0]);
  toggle4[1] = digitalRead(toggle4[0]);
  buttonValue = analogRead(A0);

  // Toggle 0
  if (toggle0[1] != toggle0[2]){
    toggleSwitch(0);
    toggle0[1] = toggle0[2];
  }
  // Toggle 1
  if (toggle1[1] != toggle1[2]){
    toggleSwitch(1);
    toggle1[1] = toggle1[2];
  }
  // Toggle 2
  if (toggle2[1] != toggle2[2]){
    toggleSwitch(2);
    toggle2[1] = toggle2[2];
  }
  // Toggle 3
  if (toggle3[1] != toggle3[2]){
    toggleSwitch(3);
    toggle3[1] = toggle3[2];
  }
  // Toggle 4
  if (toggle4[1] != toggle4[2]){
    toggleSwitch(4);
    toggle4[1] = toggle4[2];
  }
  
  // Buttons
  if (buttonValue >= 200 && buttonValue <= 220)
    buttonPress(0);
  else if (buttonValue >= 240 && buttonValue <= 280) 
    buttonPress(1);
  else if (buttonValue >= 300 && buttonValue <= 400) 
    buttonPress(2);
  else if (buttonValue >= 490 && buttonValue <= 550) 
    buttonPress(3);
  else if (buttonValue >= 1000) 
    buttonPress(4);
}

void toggleSwitch(int switchId){
  /*
    If the previous state is bigger than 0 i.e. the switches are in 
    one state over the other, also hold shift down.
    Regardless, press their associated key for 100ms and let go
  */
  switch(switchId){
    case 0:
      if (toggle0[2] > 0)
        Keyboard.press(KEYCODE_SHIFT);
      Keyboard.press(KEYCODE_F18);
      delay(100);
      Keyboard.releaseAll();
      break;
    case 1:
      if (toggle1[2] > 0)
        Keyboard.press(KEYCODE_SHIFT);
      Keyboard.press(KEYCODE_F19);
      delay(100);
      Keyboard.releaseAll();
      break;
    case 2:
      if (toggle2[2] > 0)
        Keyboard.press(KEYCODE_SHIFT);
      Keyboard.press(KEYCODE_F19);
      delay(100);
      Keyboard.releaseAll();
      break;
    case 3:
      if (toggle3[2] > 0)
        Keyboard.press(KEYCODE_SHIFT);
      Keyboard.press(KEYCODE_F20);
      delay(100);
      Keyboard.releaseAll();
      break;
    case 4:
      if (toggl4[2] > 0)
        Keyboard.press(KEYCODE_SHIFT);
      Keyboard.press(KEYCODE_F21);
      delay(100);
      Keyboard.releaseAll();
      break;
  }
  delay(100);
  Keyboard.releaseAll();
}

void buttonPress(int buttonId) {
  switch(buttonId){
    case 0:
      Keyboard.press(KEYCODE_F13)
      break;
    case 1:
      Keyboard.press(KEYCODE_F14);
      break;
    case 2:
      Keyboard.press(KEYCODE_F15);
      break;
    case 3:
      Keyboard.press(KEYCODE_F16);
      break;
    case 4:
      Keyboard.press(KEYCODE_F17);
      break;
  }
  delay(100);
  Keyboard.releaseAll();
  delay(buttonPressCoolDownms);
}
