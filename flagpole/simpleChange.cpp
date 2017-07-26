#include "NeoPixelBus.h"

void SimpleChange(NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod> &strip, HslColor colourList[], uint8_t colourCount) {
  for (int i = 0; i < colourCount; i++)
  {
    strip.ClearTo(colourList[i]);
    strip.Show();
    delay(3000);
  }
}

