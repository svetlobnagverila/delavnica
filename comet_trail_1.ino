
#include "FastLED.h"
#define NUM_LEDS 60
#define chipset NEOPIXEL 
#define Data_pin 6
 
#define BRIGHTEST 100  // the BRIGHTEST range is from 0 to 255.

CRGB leds[NUM_LEDS];

//pre-declaration of functions
void cd77_sinelon_oneway();
void cd77_sinelon();


void setup() { 
 delay(2000); // power-up safety delay  
 FastLED.addLeds<chipset, Data_pin>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip ); 
 FastLED.setBrightness(BRIGHTEST);
 
} 

void loop () {

    cd77_sinelon_oneway(40, CRGB::White, 2);   // Prva vrednost = HUTROST, druga vrednost = BARVA, tretja vrednost = DOLŽINA TRAILA

} 
 

void cd77_sinelon_oneway(uint8_t BPM, CRGB color, uint8_t fadeby)
{
  // a colored dot going in one direction with fading tail
  fadeToBlackBy( leds, NUM_LEDS, fadeby);  //change fadeby to smaller or larger number to adjust the length of the tail.
  uint8_t u= beat8(BPM,0); //BPM will allow you to adjust the speed the dot is moving.
  uint16_t pos=map(u,0,255,0,NUM_LEDS);
 leds[pos] = color;
 FastLED.show();
}


// this function is from FastLED DemoReel100 example
void cd77_sinelon(uint8_t BPM, CRGB color )
{
  // a colored dot sweeping back and forth, with fading tail
  fadeToBlackBy( leds, NUM_LEDS, 20); //change 20 to smaller or larger number to adjust the length of the tail.
 uint16_t pos = beatsin16(BPM,0,NUM_LEDS); //BPM will allow you to adjust the speed the dot is moving.
  leds[pos] = color;
  FastLED.show();
}
