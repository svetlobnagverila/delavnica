#include "FastLED.h"

#define NUM_LEDS 60
#define DATA_PIN 6
CRGB leds[NUM_LEDS];

uint8_t val = 0;    // zacetna vrednost parametra "val" ki je spremenljivka za vrednost VALUE v ukazu CHSV(HUE, SATURATION, VALUE)
int fade = 1;       // velikost koraka za katerega se spreminja vrednost VAL
int speed = 15;     // zacetna vrednost parametra SPEED, ki definira hitrost spreminjanja spremenljivke VAL

void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
  FastLED.setBrightness(50);   // jakost svetlobe (0-255)
}

void loop() {

  if (val < 255) {    // dokler je vrednost val manjsa od maksimalne
    //    val++;
    delay(speed);     // vsake "speed" milisekund
    fill_solid(leds, NUM_LEDS, CHSV(97, 240, val));  // spremeni vrednost "val"
  }

  FastLED.show();

  val = val + fade;   // vrednosti val dodaj vrednost fade

  if ( val == 255)    // ko vrednost val doseže maksimalno
  {
    delay(7000);      // se ustavi za 7 sekund
    fade = -fade ;    // in obrni vrednost "fade", kar pomeni, da bo sel value navzdol
    speed = 30;       // hitrost spreminjanja spremenljivke val pri "izdihanju" 


  }

  if (val == 0) {   // ko val doseze vrednost 0 (takrat je trak ugasnjen)
    fade = -fade;   // obrni smer val v narascanje
    speed = 15;;    // s hitrostjo 15 milisekund / korak    (15 milisekund x 255 korakov = 3825 milisekund = 3.8 sekunde )

  }


}
