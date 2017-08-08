#include "NeoPixelBus.h"

void FillWithStripes(NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod> &strip, HslColor colourList[], uint8_t colourCount, HslColor black, uint8_t startPixel, uint8_t pixelCount) {
  strip.ClearTo(black);
  strip.Show();

  uint16_t stripeSize = pixelCount / colourCount;
  
  for (int stripeNumber = 0; stripeNumber < colourCount; stripeNumber++)
  {
    uint16_t stripeStart = stripeNumber * (stripeSize + 1); 
    for (int frameCount = pixelCount; frameCount > stripeStart; frameCount--)
    {
      strip.SetPixelColor(startPixel + frameCount - 1, colourList[stripeNumber]);
      strip.Show();
      delay(100);
    }
    delay(500);
  }
}

