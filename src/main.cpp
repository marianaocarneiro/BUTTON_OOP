#include <Arduino.h>

#include "button.h"

BUTTON BOOT(0);

void setup()
{
  BOOT.begin();
  Serial.begin(9600);
}

void loop()
{
  BOOT.update();

  if (BOOT.pressed())
  {
    Serial.println("FUNCIONOU!");
  }
}
