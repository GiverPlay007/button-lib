#ifndef _BUTTON_H_
#define _BUTTON_H_

class Button
{
  public:
    Button(byte pin, int debounceDelay = 80);

    void poll();

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