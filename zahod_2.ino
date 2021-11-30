#include "FastLED.h"

#define LED_PIN     4
#define NUM_LEDS 300
#define COLOR_ORDER GRB
#define CHIPSET     WS2813

  static uint8_t heatIndex = 0; // start out at 0

DEFINE_GRADIENT_PALETTE(zahod) {
  0,     0,  0,  0,   
  128,   255, 255,  255,   
  255,   255, 0, 0
}; 

CRGBPalette16 myPal;
// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() {

  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness( 255 );
  myPal = zahod;
}
void loop() {


  // current gradient palette color index


  // HeatColors_p is a gradient palette built in to FastLED
  // that fades from black to red, orange, yellow, white
  // feel free to use another palette or define your own custom one
  CRGB color = ColorFromPalette(myPal, heatIndex);

  // fill the entire strip with the current color
  fill_solid(leds, NUM_LEDS, color);

  // slowly increase the heat
  EVERY_N_MILLISECONDS(100) {
    // stop incrementing at 255, we don't want to overflow back to 0
//    if (heatIndex <= 255) {
      heatIndex++;
  }

    

    FastLED.show();
  }
