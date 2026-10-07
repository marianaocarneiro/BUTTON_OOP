//! src/button.cpp

#include "button.h"

BUTTON::BUTTON(uint8_t pin):_pinButton(pin)
{}

void BUTTON::begin()
{
pinMode(_pinButton, INPUT_PULLUP);
}

void BUTTON::update()
{
  
}

bool BUTTON::pressed()
{

}

bool BUTTON::released()
{
    
}