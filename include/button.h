//! include/button.h

#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

class BUTTON
{
private:
    uint8_t _pinButton;
    bool _stateButton;
    bool _previousStateButton;

public:
    BUTTON(uint8_t pin);

    void begin();
    void update();
    bool pressed();
    bool released();
};

#endif