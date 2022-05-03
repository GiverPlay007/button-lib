#include <Arduino.h>
#include <stdio.h>
#include "Button.h"

Button::Button(byte pin, int debounceDelay)
{
  pinMode(pin, INPUT);
  
  this->pin = pin;
  pressed = false;
  pressedOnce = false;
  lastState = false;
  lastTime = 0;
}

void Button::pool()
{
  unsigned long now = millis();
  bool state = digitalRead(pin);

  pressed = false;
  pressedOnce = false;

  if(now - lastTime > debounceDelay && state)
  {
    pressed = true;
    pressedOnce = !lastState;
  }

  if(state != lastState)
  {
    lastTime = now;
  }

  lastState = pressed;
}

bool Button::isPressed()
{
  return this->pressed;
}

bool Button::isPressedOnce()
{
  return this->pressedOnce;
}
