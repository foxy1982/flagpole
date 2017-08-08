#include "NeoPixelBus.h"

void SimpleChange(NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod> &strip, HslColor colourList[], uint8_t colourCount, uint8_t startPixel, uint8_t pixelCount) {
  for (int i = 0; i < colourCount; i++)
  {
    Serial.println(startPixel);
    Serial.println(pixelCount);
    Serial.println("***");
    strip.ClearTo(colourList[i], startPixel, startPixel + pixelCount);
    strip.Show();
    delay(3000);
  }
}

