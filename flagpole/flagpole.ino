#include "NeoPixelBus.h"
#include "colourDefinitions.h"

#include "simpleChange.h"

const uint16_t PixelCount = 3; 
const uint8_t PixelPin = 6;  // make sure to set this to the correct pin, ignored for Esp8266

HslColor _colourList[] = { hslRed, hslWhite, hslBlue };
const uint8_t ColourCount = 3;

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
    SimpleChange(_strip, _colourList, ColourCount);
}
