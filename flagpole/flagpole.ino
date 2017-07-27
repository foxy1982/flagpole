#include "NeoPixelBus.h"
#include "colourDefinitions.h"

#include "simpleChange.h"
#include "flashColours.h"
#include "fillWithStripes.h"

const uint16_t PixelCount = 90; 
const uint8_t PixelPin = 6;  // make sure to set this to the correct pin, ignored for Esp8266

HslColor _colourList[] = { hslRed, hslYellow, hslBlue };
const uint8_t ColourCount = 6;

// three element pixels, in different order and speeds
NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod> _strip(PixelCount, PixelPin);

void setup()
{
    // this resets all the neopixels to an off state
    _strip.Begin();
    _strip.Show();
}

void loop()
{
    //SimpleChange(_strip, _colourList, ColourCount);
    //FlashColours(_strip, _colourList, ColourCount, hslBlack);
    FillWithStripes(_strip, _colourList, ColourCount, hslBlack, PixelCount);
}
