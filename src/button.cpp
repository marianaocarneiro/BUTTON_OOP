//! src/button.cpp

#include "button.h"

BUTTON::BUTTON(uint8_t pin) : _pinButton(pin)
{
}

void BUTTON::begin()
{
    pinMode(_pinButton, INPUT_PULLUP);
}

void BUTTON::update()
{
    _press = false;
    _release = false;

    _currentStateButton = digitalRead(_pinButton);

    if (_currentStateButton != _previousStateButton)
    {
        _previousStateButton = _currentStateButton;
        _lest_ms = millis();
        return;
    }

    if (_elapseTime() < _timeDebounce_ms)
        return;

    if (_currentStateButton == _lestStateAction)
        return;

    _lestStateAction = _currentStateButton;

    const bool buttonPress = !_currentStateButton;

    buttonPress
        ? _press = true
        : _release = true;
}

// void BUTTON::update()
// {
//     _press = false;
//     _release = false;

//     _currentStateButton = digitalRead(_pinButton);

//     if (_currentStateButton != _previousStateButton)
//     {
//         _previousStateButton = _currentStateButton;
//         _lest_ms = millis();
//     }

//     else if (_elapseTime() > _timeDebounce_ms)
//     {
//         const bool actionPerformed = (_lestStateAction == _currentStateButton);
//         if (!actionPerformed)
//         {
//             _lestStateAction = _currentStateButton;

//             const bool buttonPress = !_currentStateButton;

//             buttonPress
//                 ? _press = true
//                 : _release = true;
//         }
//     }
// }

bool BUTTON::pressed()
{
    return _press;
}

bool BUTTON::released()
{
    return _release;
}

uint32_t BUTTON::_elapseTime()
{
    return millis() - _lest_ms;
}