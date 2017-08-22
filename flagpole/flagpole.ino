#include "NeoPixelBus.h"
#include "colourDefinitions.h"

#include "simpleChange.h"
#include "flashColours.h"
#include "fillWithStripes.h"
#include "morseMessage.h"

const uint16_t StartPixel = 60;
const uint16_t PixelCount = 90; 
const uint8_t PixelPin = 6;  // make sure to set this to the correct pin, ignored for Esp8266

HslColor _colourList[] = { hslRed, hslOrange, hslYellow, hslGreen, hslBlue, hslPurple };
const uint8_t ColourCount = 6;

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

void Clear(uint16_t delayMs)
{
  _strip.ClearTo(hslBlack);
  _strip.Show();
  delay(delayMs);
}

void loop()
{
  SimpleChange(_strip, _colourList, ColourCount, StartPixel, PixelCount);
  Clear(1000);
  MorseMessage(_strip, hslBlack, hslRed, StartPixel, PixelCount);
  Clear(1000);
  FillWithStripes(_strip, _colourList, ColourCount, hslBlack, StartPixel, PixelCount);
  Clear(1000);
  MorseMessage(_strip, hslBlack, hslOrange, StartPixel, PixelCount);
  Clear(1000);
  FlashColours(_strip, _colourList, ColourCount, hslBlack, StartPixel, PixelCount);
  Clear(1000);
  MorseMessage(_strip, hslBlack, hslYellow, StartPixel, PixelCount);
  Clear(1000);

  SimpleChange(_strip, _colourList, ColourCount, StartPixel, PixelCount);
  Clear(1000);
  MorseMessage(_strip, hslBlack, hslGreen, StartPixel, PixelCount);
  Clear(1000);
  FillWithStripes(_strip, _colourList, ColourCount, hslBlack, StartPixel, PixelCount);
  Clear(1000);
  MorseMessage(_strip, hslBlack, hslBlue, StartPixel, PixelCount);
  Clear(1000);
  FlashColours(_strip, _colourList, ColourCount, hslBlack, StartPixel, PixelCount);
  Clear(1000);
  MorseMessage(_strip, hslBlack, hslPurple, StartPixel, PixelCount);
  Clear(1000);
}
