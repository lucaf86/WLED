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

#ifndef IRPIN

  #define IRPIN -1  //infrared pin (-1 to disable)  MagicHome: 4, H801 Wifi: 0
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
#include "const.h"

const uint8_t numStrips = NUM_STRIPS;  // max 4 strips allowed on esp8266
const uint16_t pixelCounts[numStrips] = {PIXEL_COUNTS}; // number of pixels on each strip
const uint8_t dataPins[numStrips] = {DATA_PINS}; // change these pins based on your board

#define PIXELFEATURE3 NeoGrbFeature
#define PIXELFEATURE4 NeoGrbwFeature

// ESP8266 has 1 Uart interfaces available to drive a strip of pixels
// For the other use bitBang
// Convenience #defines for creating NeoPixelBrightnessBus 
#define NeoPixelBrightnessBusGrb0 NeoPixelBrightnessBus<PIXELFEATURE3, NeoEsp8266Uart1Ws2813Method>
//#define NeoPixelBrightnessBusGrb0 NeoPixelBrightnessBus<PIXELFEATURE3, NeoEsp8266BitBang800KbpsMethod>
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
  //  switch (_type)
  //  {
  //    case NeoPixelType_Grb:
  //    {
        for (uint8_t idx = 0; idx < numStrips; idx++)
        {
          switch (idx)
          {
            case 0: pGrb0->Show(); ESP8266_MULTISTRIP_YIELD; break;
            case 1: pGrb1->Show(); ESP8266_MULTISTRIP_YIELD; break;
            case 2: pGrb2->Show(); ESP8266_MULTISTRIP_YIELD; break;
            case 3: pGrb3->Show(); ESP8266_MULTISTRIP_YIELD; break;
          }
        }
  //      break;
  //    }
  //    case NeoPixelType_Grbw:
  //    {
  //      for (uint8_t idx = 0; idx < numStrips; idx++)
  //      {
  //        switch (idx)
  //        {
  //          case 0: pGrbw0->Show(); break;
  //          case 1: pGrbw1->Show(); break;
  //          case 2: pGrbw2->Show(); break;
  //          case 3: pGrbw3->Show(); break;
  //        }
  //      }
  //      break;
  //    }
  //  }
  }

  /** 
   * This will return true if enough time has passed since the last time Show() was called. 
   * This also means that calling Show() will not cause any undue waiting. If the method for 
   * the defined bus is hardware that sends asynchronously, then call CanShow() will let 
   * you know if it has finished sending the data from the last Show().
   */
  bool CanShow()
  {
    bool canShow = true;
    //switch (_type)
    //{
    //  case NeoPixelType_Grb:
    //  {
        for (uint8_t idx = 0; idx < numStrips; idx++)
        {
          switch (idx)
          {
            case 0: canShow &= pGrb0->CanShow(); break;
            case 1: canShow &= pGrb1->CanShow(); break;
            case 2: canShow &= pGrb2->CanShow(); break;
            case 3: canShow &= pGrb3->CanShow(); break;
          }
        }
    //    break;
    //  }
 /*     case NeoPixelType_Grbw:
      {
        for (uint8_t idx = 0; idx < numStrips; idx++)
        {
          switch (idx)
          {
            case 0: canShow &= pGrbw0->CanShow(); break;
            case 1: canShow &= pGrbw1->CanShow(); break;
            case 2: canShow &= pGrbw2->CanShow(); break;
            case 3: canShow &= pGrbw3->CanShow(); break;
          }
        }
        break;
      }*/
    //}
    return canShow;
  }

  void SetPixelColorRaw(uint16_t indexPixel, RgbwColor c)
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
        RgbColor rgb = RgbColor(c.R, c.G, c.B);
        switch (stripIdx)
        {
          case 0: pGrb0->SetPixelColor(indexPixel, rgb); break;
          case 1: pGrb1->SetPixelColor(indexPixel, rgb); break;
          case 2: pGrb2->SetPixelColor(indexPixel, rgb); break;
          case 3: pGrb3->SetPixelColor(indexPixel, rgb); break;
        }
        break;
      }
      case NeoPixelType_Grbw:
      {
        switch (stripIdx)
        {
          case 0: pGrbw0->SetPixelColor(indexPixel, c); break;
          case 1: pGrbw1->SetPixelColor(indexPixel, c); break;
          case 2: pGrbw2->SetPixelColor(indexPixel, c); break;
          case 3: pGrbw3->SetPixelColor(indexPixel, c); break;
        }
        break;
      }
    }
  }

  void SetPixelColor(uint16_t indexPixel, RgbwColor c)
  {
    /*
    Set pixel color with necessary color order conversion.
    */

    RgbwColor col;

    uint8_t co = _colorOrder;
    #ifdef COLOR_ORDER_OVERRIDE
    if (indexPixel >= COO_MIN && indexPixel < COO_MAX) co = COO_ORDER;
    #endif

    //reorder channels to selected order
    switch (co)
    {
      case  0: col.G = c.G; col.R = c.R; col.B = c.B; break; //0 = GRB, default
      case  1: col.G = c.R; col.R = c.G; col.B = c.B; break; //1 = RGB, common for WS2811
      case  2: col.G = c.B; col.R = c.R; col.B = c.G; break; //2 = BRG
      case  3: col.G = c.R; col.R = c.B; col.B = c.G; break; //3 = RBG
      case  4: col.G = c.B; col.R = c.G; col.B = c.R; break; //4 = BGR
      default: col.G = c.G; col.R = c.B; col.B = c.R; break; //5 = GBR
    }
    col.W = c.W;

    SetPixelColorRaw(indexPixel, col);
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


  void SetColorOrder(byte colorOrder)
  {
    _colorOrder = colorOrder;
  }

  uint8_t GetColorOrder()
  {
    return _colorOrder;
  }

  RgbwColor GetPixelColorRaw(uint16_t indexPixel) const
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

  // NOTE: Due to feature differences, some support RGBW but the method name
  // here needs to be unique, thus GetPixeColorRgbw
  uint32_t GetPixelColorRgbw(uint16_t indexPixel) const
  {
    RgbwColor col = GetPixelColorRaw(indexPixel);
    uint8_t co = _colorOrder;
    #ifdef COLOR_ORDER_OVERRIDE
    if (indexPixel >= COO_MIN && indexPixel < COO_MAX) co = COO_ORDER;
    #endif

    switch (co)
    {
      //                    W               G              R               B
      case  0: return ((col.W << 24) | (col.G << 8) | (col.R << 16) | (col.B)); //0 = GRB, default
      case  1: return ((col.W << 24) | (col.R << 8) | (col.G << 16) | (col.B)); //1 = RGB, common for WS2811
      case  2: return ((col.W << 24) | (col.B << 8) | (col.R << 16) | (col.G)); //2 = BRG
      case  3: return ((col.W << 24) | (col.B << 8) | (col.G << 16) | (col.R)); //3 = RBG
      case  4: return ((col.W << 24) | (col.R << 8) | (col.B << 16) | (col.G)); //4 = BGR
      case  5: return ((col.W << 24) | (col.G << 8) | (col.B << 16) | (col.R)); //5 = GBR
    }

    return 0;

  }

private:
  NeoPixelType _type;
  byte _colorOrder = 0;

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
