#include "NeoPixelBus.h"

String message = ".... .- .--. .--. -.--   -... .. .-. - .... -.. .- -.--   -.- .- .-. .-..";

void Pad(String *message, uint8_t padCount)
{
  for (int i = 0; i < padCount; i++)
  {
      *message += " ";
  }
}

void ConvertToBoolArray(String message, bool *outputArray)
{
  uint8_t arrayCounter = 0;

  for (int i = 0; i < message.length(); i++)
  {
    switch (message[i])
    {
      case ' ':
        break;
      case '.':
        outputArray[arrayCounter] = true;
        arrayCounter++;
        break;
      case '-':
        outputArray[arrayCounter] = true;
        arrayCounter++;
        outputArray[arrayCounter] = true;
        arrayCounter++;
        break;   
    }
    outputArray[arrayCounter] = false;
    arrayCounter++;
    Serial.println(arrayCounter);
  } 
}

uint8_t CountNumberOfHyphens(String message)
{
  uint8_t count = 0;

  for (int i = 0; i < message.length(); i++)
  {
    if (message.charAt(i) == '-')
    {
      count++;
    }
  }

  return count;
}

void MorseMessage(NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod> &strip, HslColor backgroundColour, HslColor foregroundColour, uint8_t pixelCount)
{
  String fullMessage = "";

  Pad(&fullMessage, pixelCount);
  fullMessage += message;
  Pad(&fullMessage, pixelCount);

  uint16_t boolArrayLength = (2 * pixelCount) + (2 * message.length()) + CountNumberOfHyphens(message) - 1;

  bool boolArray[boolArrayLength];

  ConvertToBoolArray(fullMessage, boolArray);

  for (int frameCounter = 0; frameCounter < boolArrayLength - pixelCount; frameCounter++)
  {
    strip.ClearTo(backgroundColour);
    for (int i = 0; i < pixelCount; i++)
    {
      if (boolArray[frameCounter + i])
      {
        strip.SetPixelColor(i, foregroundColour);
      }
    }
    strip.Show();
    delay(1000);
  }
}

