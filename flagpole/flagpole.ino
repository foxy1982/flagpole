#include "NeoPixelBus.h"
#include "colourDefinitions.h"

#include "simpleChange.h"
#include "flashColours.h"
#include "fillWithStripes.h"
#include "morseMessage.h"

const uint16_t StartPixel = 60;
const uint16_t PixelCount = 90; 
const uint8_t PixelPin = 6;  // make sure to set this to the correct pin, ignored for Esp8266

HslColor _colourList[] = { hslYellow, hslRed, hslGreen };
const uint8_t ColourCount = 3;

// three element pixels, in different order and speeds
NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod> _strip(PixelCount + StartPixel + 1, PixelPin);

void setup()
{
    Serial.begin(115200);
    while (!Serial); // wait for serial attach

    Serial.println("Initializing...");
    Serial.flush();
  
    // this resets all the neopixels to an off state
    _strip.Begin();
    _strip.Show();
}

void loop()
{
  SimpleChange(_strip, _colourList, ColourCount, StartPixel, PixelCount);
  FillWithStripes(_strip, _colourList, ColourCount, hslBlack, StartPixel, PixelCount);
  FlashColours(_strip, _colourList, ColourCount, hslBlack, StartPixel, PixelCount);
  MorseMessage(_strip, hslBlack, hslBlue, StartPixel, PixelCount);
}
