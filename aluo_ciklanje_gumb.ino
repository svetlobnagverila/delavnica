#include <FastLED.h>

#define NUM_LEDS  60
#define LED_PIN   6
#define BRIGHTNESS 20

CRGB leds[NUM_LEDS];


int gumb = 3 ;     //pin na katerem je touch senzor
int stevec = 0;   //stanje stevca, zacetno stanje je 0

int stanjegumba = 0;
int zadnjestanjegumba = 0;


void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);   //jakost svetlobe
  pinMode(gumb, INPUT);         //definiramo gumb kot INPUT
}

void loop() {

  stanjegumba = digitalRead(gumb);

  if (stanjegumba != zadnjestanjegumba) {
    if (stanjegumba == HIGH) {
      stevec++;
    }
  }
  zadnjestanjegumba = stanjegumba;

  if (stevec == 0) {
    fill_solid(leds, NUM_LEDS, CRGB( 255, 0, 0));     // prvo stanje
  }

  if (stevec == 1) {
    fill_solid(leds, NUM_LEDS, CRGB(0, 255, 255));    // drugo stanje ob pritisku na gumb
  }

  if (stevec == 2) {
    fill_solid(leds, NUM_LEDS, CRGB::Blue);           // tretje stanje ob pritisku na gumb
  }
 FastLED.show();

if (stevec == 3) {                                    // ko pride stevec do 3, se vrne nazaj na 0
  stevec = 0;
}

}
