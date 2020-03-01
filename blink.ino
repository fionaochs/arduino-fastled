#include <FastLED.h>

#define LED_PIN     11
#define NUM_LEDS    50
CRGB leds[NUM_LEDS];
bool blink = false;


void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<WS2811, LED_PIN, RGB>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(255);
  clearAllLEDs();
}

void loop() {
  // put your main code here, to run repeatedly:

  blink = !blink;
  
  CRGB evenColor = (blink ? CRGB::Red : CRGB::Green);
  CRGB oddColor = (blink ? CRGB::Green : CRGB::Red);
  
  for ( int i = 0; i < NUM_LEDS; i++) {
    if (i%2 == 0)
      leds[i] = evenColor;
    else
      leds[i] = oddColor;
  }

  FastLED.show();
  delay(1000);

  
}

void clearAllLEDs()
{
  for ( int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
  }
}