#include <FastLED.h>

#define NUM_LEDS  60    // stevilo LEDic v traku
#define LED_PIN   6     // PIN na katerem je LED trak

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);   
  FastLED.setBrightness(50);    // SVETLOST LED TRAKU
}

void loop() {

  fill_solid(leds, NUM_LEDS, CRGB::White);
  FastLED.show();
  delay(random(3000,5000));   // random(min, max) = ukaz bo trajal nakljucno vrednost milisekund med vrednostima v oklepaju
  
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  FastLED.show();
  delay(random(5,30));

    fill_solid(leds, NUM_LEDS, CRGB::White);
  FastLED.show();
  delay(random(1000,3000));

    fill_solid(leds, NUM_LEDS, CRGB::Black);
  FastLED.show();
  delay(random(10,50));

  fill_solid(leds, NUM_LEDS, CRGB(255, 255, 255));
  FastLED.show();
  delay(random(2000,4000));
  
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  FastLED.show();
  delay(random(5,30));

    fill_solid(leds, NUM_LEDS, CRGB(100, 100, 100));    // CRGB(100, 100, 100) je zmanjsana jakost bele. CRGB(0, 0, 0) je ugasnjen trak, CRGB(255, 255, 255) je MAX WHITE
  FastLED.show();
  delay(random(50,100));

    fill_solid(leds, NUM_LEDS, CRGB::Black);
  FastLED.show();
  delay(random(20,60));

    fill_solid(leds, NUM_LEDS, CRGB(100, 100, 100));
  FastLED.show();
  delay(random(5,30));

    fill_solid(leds, NUM_LEDS, CRGB::White);
  FastLED.show();
  delay(random(50,100));

    fill_solid(leds, NUM_LEDS, CRGB::Black);
  FastLED.show();
  delay(random(20,60));

      fill_solid(leds, NUM_LEDS, CRGB::White);
  FastLED.show();
  delay(random(50,100));

      fill_solid(leds, NUM_LEDS, CRGB(100, 100, 100));
  FastLED.show();
  delay(random(20,60));
  

}
