//this code is a modified version of https://github.com/Makuna/NeoPixelBus/issues/103
#ifndef NpbWrapper_h
#define NpbWrapper_h

// make sure we're using esp32 platform
#ifndef ESP8266
  #error This version of NbpWrapper.h only works with ESP8266 hardware.
#endif

#ifndef NUM_STRIPS
  #error Need to define number of LED strips using build flag -D NUM_STRIPS=3 for 3 LED strips
#endif

#ifndef PIXEL_COUNTS
  #error Need to define pixel counts using build flag -D PIXEL_COUNTS="25, 25, 25" for 3 LED strips with 25 LEDs each
#endif

#ifndef DATA_PINS
  #error Need to define data pins using build flag -D DATA_PINS="1, 2, 3" if LED strips are on data pins 1, 2, 3
#endif

// //PIN CONFIGURATION
#ifndef LEDPIN
  #define LEDPIN 2  // Legacy pin def required by some other portions of code. This pin is not used do drive LEDs.
#endif

#ifndef IR_PIN
  #define IR_PIN -1  //infrared pin (-1 to disable)  MagicHome: 4, H801 Wifi: 0
#endif

#ifndef RLYPIN
  #define RLYPIN 12  //pin for relay, will be set HIGH if LEDs are on (-1 to disable). Also usable for standby leds, triggers,...
#endif

#ifndef AUXPIN
  #define AUXPIN -1  //debug auxiliary output pin (-1 to disable)
#endif

#ifndef RLYMDE
  #define RLYMDE 1  //mode for relay, 0: LOW if LEDs are on 1: HIGH if LEDs are on
#endif

#include <NeoPixelBrightnessBus.h>

const uint8_t numStrips = NUM_STRIPS;  // max 4 strips allowed on esp8266
const uint16_t pixelCounts[numStrips] = {PIXEL_COUNTS}; // number of pixels on each strip
const uint8_t dataPins[numStrips] = {DATA_PINS}; // change these pins based on your board

#define PIXELFEATURE3 NeoGrbFeature
#define PIXELFEATURE4 NeoGrbwFeature

// ESP8266 has 1 Uart interfaces available to drive a strip of pixels
// For the other use bitBang
// Convenience #defines for creating NeoPixelBrightnessBus 
#define NeoPixelBrightnessBusGrb0 NeoPixelBrightnessBus<PIXELFEATURE3, NeoEsp8266Uart1Ws2813Method>
#define NeoPixelBrightnessBusGrb1 NeoPixelBrightnessBus<PIXELFEATURE3, NeoEsp8266BitBang800KbpsMethod>
#define NeoPixelBrightnessBusGrb2 NeoPixelBrightnessBus<PIXELFEATURE3, NeoEsp8266BitBang800KbpsMethod>
#define NeoPixelBrightnessBusGrb3 NeoPixelBrightnessBus<PIXELFEATURE3, NeoEsp8266Dma800KbpsMethod>
#define NeoPixelBrightnessBusGrbw0 NeoPixelBrightnessBus<PIXELFEATURE4, NeoEsp8266Uart1Ws2813Method>
#define NeoPixelBrightnessBusGrbw1 NeoPixelBrightnessBus<PIXELFEATURE4, NeoEsp8266BitBang800KbpsMethod>
#define NeoPixelBrightnessBusGrbw2 NeoPixelBrightnessBus<PIXELFEATURE4, NeoEsp8266BitBang800KbpsMethod>
#define NeoPixelBrightnessBusGrbw3 NeoPixelBrightnessBus<PIXELFEATURE4, NeoEsp8266Dma800KbpsMethod>

enum NeoPixelType
{
  NeoPixelType_None = 0,
  NeoPixelType_Grb  = 1,
  NeoPixelType_Grbw = 2,
  NeoPixelType_End  = 3
};

class NeoPixelWrapper
{
public:
  NeoPixelWrapper() :
    _type(NeoPixelType_None)
  {
    // On initialization fill in the pixelStripStartIdx array with the beginning index of each strip
    // relative to th entire array.
    uint16_t totalPixels = 0;
    for (uint8_t idx = 0; idx < numStrips; idx++)
    {
      pixelStripStartIdx[idx] = totalPixels;
      totalPixels += pixelCounts[idx];
    }
  }

  ~NeoPixelWrapper()
  {
    cleanup();
  }

  void Begin(NeoPixelType type, uint16_t pixelCount)
  {

    cleanup();

    _type = type;

    switch (_type)
    {
      case NeoPixelType_Grb:
      {
        for (uint8_t idx = 0; idx < numStrips; idx++)
        {
          switch (idx)
          {
            case 0: pGrb0 = new NeoPixelBrightnessBusGrb0(pixelCounts[idx], dataPins[idx]); pGrb0->Begin(); break;
            case 1: pGrb1 = new NeoPixelBrightnessBusGrb1(pixelCounts[idx], dataPins[idx]); pGrb1->Begin(); break;
            case 2: pGrb2 = new NeoPixelBrightnessBusGrb2(pixelCounts[idx], dataPins[idx]); pGrb2->Begin(); break;
            case 3: pGrb3 = new NeoPixelBrightnessBusGrb3(pixelCounts[idx], dataPins[idx]); pGrb3->Begin(); break;
          }
        }
        break;
      }

      case NeoPixelType_Grbw:
      {
        for (uint8_t idx = 0; idx < numStrips; idx++)
        {
          switch (idx)
          {
            case 0: pGrbw0 = new NeoPixelBrightnessBusGrbw0(pixelCounts[idx], dataPins[idx]); pGrbw0->Begin(); break;
            case 1: pGrbw1 = new NeoPixelBrightnessBusGrbw1(pixelCounts[idx], dataPins[idx]); pGrbw1->Begin(); break;
            case 2: pGrbw2 = new NeoPixelBrightnessBusGrbw2(pixelCounts[idx], dataPins[idx]); pGrbw2->Begin(); break;
            case 3: pGrbw3 = new NeoPixelBrightnessBusGrbw3(pixelCounts[idx], dataPins[idx]); pGrbw3->Begin(); break;
          }
        }
        break;
      }
    }
  }

  void Show()
  {
    byte b;
    switch (_type)
    {
      case NeoPixelType_Grb:
      {
        for (uint8_t idx = 0; idx < numStrips; idx++)
        {
          switch (idx)
          {
            case 0: pGrb0->Show(); break;
            case 1: pGrb1->Show(); break;
            case 2: pGrb2->Show(); break;
            case 3: pGrb3->Show(); break;
          }
        }
        break;
      }
      case NeoPixelType_Grbw:
      {
        for (uint8_t idx = 0; idx < numStrips; idx++)
        {
          switch (idx)
          {
            case 0: pGrbw0->Show(); break;
            case 1: pGrbw1->Show(); break;
            case 2: pGrbw2->Show(); break;
            case 3: pGrbw3->Show(); break;
          }
        }
        break;
      }
    }
  }

  void SetPixelColor(uint16_t indexPixel, RgbwColor color)
  {
    // figure out which strip this pixel index is on
    uint8_t stripIdx = 0;
    for (uint8_t idx = 0; idx < numStrips; idx++)
    {
      if (indexPixel >= pixelStripStartIdx[idx])
      {
        stripIdx = idx;
      }
      else
      {
        break;
      }
    }
    // subtract strip start index so we're addressing just this strip instead of all pixels on all strips
    indexPixel -= pixelStripStartIdx[stripIdx];
    switch (_type)
    {
      case NeoPixelType_Grb:
      {
        RgbColor c = RgbColor(color.R, color.G, color.B);
        switch (stripIdx)
        {
          case 0: pGrb0->SetPixelColor(indexPixel, c); break;
          case 1: pGrb1->SetPixelColor(indexPixel, c); break;
          case 2: pGrb2->SetPixelColor(indexPixel, c); break;
          case 3: pGrb3->SetPixelColor(indexPixel, c); break;
        }
        break;
      }
      case NeoPixelType_Grbw:
      {
        switch (stripIdx)
        {
          case 0: pGrbw0->SetPixelColor(indexPixel, color); break;
          case 1: pGrbw1->SetPixelColor(indexPixel, color); break;
          case 2: pGrbw2->SetPixelColor(indexPixel, color); break;
          case 3: pGrbw3->SetPixelColor(indexPixel, color); break;
        }
        break;
      }
    }
  }

  void SetBrightness(byte b)
  {
    switch (_type)
    {
      case NeoPixelType_Grb:
      {
        for (uint8_t idx = 0; idx < numStrips; idx++)
        {
          switch (idx)
          {
            case 0: pGrb0->SetBrightness(b); break;
            case 1: pGrb1->SetBrightness(b); break;
            case 2: pGrb2->SetBrightness(b); break;
            case 3: pGrb3->SetBrightness(b); break;
          }
        }
        break;
      }
      case NeoPixelType_Grbw:
      {
        for (uint8_t idx = 0; idx < numStrips; idx++)
        {
          switch (idx)
          {
            case 0: pGrbw0->SetBrightness(b); break;
            case 1: pGrbw1->SetBrightness(b); break;
            case 2: pGrbw2->SetBrightness(b); break;
            case 3: pGrbw3->SetBrightness(b); break;
          }
        }
        break;
      }
    }
  }

  // NOTE: Due to feature differences, some support RGBW but the method name
  // here needs to be unique, thus GetPixeColorRgbw
  RgbwColor GetPixelColorRgbw(uint16_t indexPixel) const
  {
    // figure out which strip this pixel index is on
    uint8_t stripIdx = 0;
    for (uint8_t idx = 0; idx < numStrips; idx++)
    {
      if (indexPixel >= pixelStripStartIdx[idx])
      {
        stripIdx = idx;
      }
      else
      {
        break;
      }
    }
    // subtract strip start index so we're addressing just this strip instead of all pixels on all strips
    indexPixel -= pixelStripStartIdx[stripIdx];
    switch (_type)
    {
    case NeoPixelType_Grb:
    {
      switch (stripIdx)
      {
        case 0: return pGrb0->GetPixelColor(indexPixel);
        case 1: return pGrb1->GetPixelColor(indexPixel);
        case 2: return pGrb2->GetPixelColor(indexPixel);
        case 3: return pGrb3->GetPixelColor(indexPixel);
      }
      break;
    }
    case NeoPixelType_Grbw:
      switch (stripIdx)
      {
        case 0: return pGrbw0->GetPixelColor(indexPixel);
        case 1: return pGrbw1->GetPixelColor(indexPixel);
        case 2: return pGrbw2->GetPixelColor(indexPixel);
        case 3: return pGrbw3->GetPixelColor(indexPixel);
      }
      break;
    }
    return 0;
  }

private:
  NeoPixelType _type;

  uint16_t pixelStripStartIdx[numStrips];

  // pointers for every possible type for up to 8 strips
  NeoPixelBrightnessBusGrb0 *pGrb0;
  NeoPixelBrightnessBusGrb1 *pGrb1;
  NeoPixelBrightnessBusGrb2 *pGrb2;
  NeoPixelBrightnessBusGrb3 *pGrb3;
  NeoPixelBrightnessBusGrbw0 *pGrbw0;
  NeoPixelBrightnessBusGrbw1 *pGrbw1;
  NeoPixelBrightnessBusGrbw2 *pGrbw2;
  NeoPixelBrightnessBusGrbw3 *pGrbw3;

  void cleanup()
  {
    switch (_type)
    {
      case NeoPixelType_Grb:
      {
        for (uint8_t idx = 0; idx < numStrips; idx++)
        {
          switch (idx)
          {
            case 0: delete pGrb0; pGrb0 = NULL; break;
            case 1: delete pGrb1; pGrb1 = NULL; break;
            case 2: delete pGrb2; pGrb2 = NULL; break;
            case 3: delete pGrb3; pGrb3 = NULL; break;
          }
        }
        break;
      }
      case NeoPixelType_Grbw:
      {
        for (uint8_t idx = 0; idx < numStrips; idx++)
        {
          switch (idx)
          {
            case 0: delete pGrbw0; pGrbw0 = NULL; break;
            case 1: delete pGrbw1; pGrbw1 = NULL; break;
            case 2: delete pGrbw2; pGrbw2 = NULL; break;
            case 3: delete pGrbw3; pGrbw3 = NULL; break;
          }
        }
      }
    }
  }
};
#endif
