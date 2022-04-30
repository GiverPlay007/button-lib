#ifndef _BUTTON_HPP_
#define _BUTTON_HPP_

class Button
{
  public:
    Button(byte pin, int debounceDelay = 80);

    void pool();

    bool isPressed();
    bool isPressedOnce();

  private:
    byte pin;
    
    unsigned long debounceDelay;
    unsigned int lastTime;

    bool lastState;
    bool pressed;
    bool pressedOnce;
};

#endif