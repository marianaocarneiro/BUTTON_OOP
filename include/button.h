//! include/button.h

#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

class BUTTON
{
private:
    uint8_t _pinButton;
    bool _currentStateButton = HIGH;
    bool _previousStateButton = HIGH;
    bool _press = false;
    bool _release = false;
    uint32_t _lest_ms = 0;
    uint32_t _timeDebounce_ms = 20;
    bool _lestStateAction = HIGH;

    uint32_t _elapseTime();

public:
    BUTTON(uint8_t pin);

    void begin();
    void update();
    bool pressed();
    bool released();
};

#endif