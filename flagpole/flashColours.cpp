#include "NeoPixelBus.h"

void FlashColours(NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod> &strip, HslColor colourList[], uint8_t colourCount, HslColor black, uint8_t startPixel, uint8_t pixelCount) {
  int maxLoops = 4;
  for (int outer = 0; outer < maxLoops; outer++)
  { 
    for (int i = 0; i < colourCount; i++)
    {
      strip.ClearTo(colourList[i], startPixel, startPixel + pixelCount);
      strip.Show();
      delay(500);
      strip.ClearTo(black);
      strip.Show();
      delay(250);
    }
  }
}

