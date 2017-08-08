#include "NeoPixelBus.h"

String message = ".... .- .--. .--. -.--   -... .. .-. - .... -.. .- -.--   -.- .- .-. .-..";
//String message = ".... .- .--. .--. -.--   -... .. .-. - .... -.. .- -.--";


void Pad(String *message, int padCount)
{
  for (int i = 0; i < padCount; i++)
  {
      *message += " ";
  }
}

void ConvertToBoolArray(String *message, bool *outputArray)
{
  int arrayCounter = 0;

  Serial.println(*message);

  for (int i = 0; i < message->length(); i++)
  {
    switch ((*message)[i])
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
  } 
  Serial.println(arrayCounter);
}

int CountNumberOfCharacters(String message, char character)
{
  int count = 0;

  for (int i = 0; i < message.length(); i++)
  {
    if (message.charAt(i) == character)
    {
      count++;
    }
  }
  return count;  
}

void MorseMessage(NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod> &strip, HslColor backgroundColour, HslColor foregroundColour, uint8_t startPixel, uint8_t pixelCount)
{
  String fullMessage = "";

  Pad(&fullMessage, pixelCount);
  fullMessage += message;
  Pad(&fullMessage, pixelCount);

  int numberOfSpaces = CountNumberOfCharacters(fullMessage, ' ');
  Serial.print("numberOfSpaces: ");
  Serial.println(numberOfSpaces);

  int numberOfDots = CountNumberOfCharacters(fullMessage, '.');
  Serial.print("numberOfDots: ");
  Serial.println(numberOfDots);

  int numberOfDashes = CountNumberOfCharacters(fullMessage, '-');
  Serial.print("numberOfDashes: ");
  Serial.println(numberOfDashes);
  
  int boolArrayLength = numberOfSpaces + (2 * numberOfDots) + (3 * numberOfDashes);

  Serial.println(fullMessage);
  Serial.print("message.length(): ");
  Serial.println(message.length());
  Serial.print("fullMessage.length(): ");
  Serial.println(fullMessage.length());
  Serial.print("boolArrayLength: ");
  Serial.println(boolArrayLength);
  
  bool boolArray[boolArrayLength];

  Serial.println(fullMessage);
  ConvertToBoolArray(&fullMessage, boolArray);

  Serial.println();
  for (int i = 0; i < boolArrayLength; i++)
  {
    if (boolArray[i]) {
      Serial.print(1);
    } else {
      Serial.print(0);
    }
  }
  Serial.println();

  for (int frameCounter = 0; frameCounter < boolArrayLength - pixelCount; frameCounter++)
  {
    strip.ClearTo(backgroundColour);
    for (int i = 0; i < pixelCount; i++)
    {
      if (boolArray[frameCounter + i])
      {
        strip.SetPixelColor(startPixel + i, foregroundColour);
      }
    }
    strip.Show();
    delay(500);
  }
}

