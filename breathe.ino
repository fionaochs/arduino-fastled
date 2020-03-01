 
#define LED_PIN 11                         
#define NUM_LEDS 50
#define LED_TYPE NEOPIXEL
#define MIN_BRIGHTNESS 8                  
#define MAX_BRIGHTNESS 65                   
 
struct CRGB leds[NUM_LEDS];
 
void setup()
{
  FastLED.addLeds<WS2811, LED_PIN, RGB>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
    FastLED.setBrightness(MAX_BRIGHTNESS);
    FastLED.clear();
}

int hue = 0;
int divisor = 40;
void loop () {
 float breath = (exp(sin(millis()/5000.0*PI)) - 0.36787944)*200.0;
 //5000 is speed of breathing
 //200 is transition between min and max brightness
 breath = map(breath, 0, 255, MIN_BRIGHTNESS, MAX_BRIGHTNESS);
 FastLED.setBrightness(breath);
 fill_rainbow(leds, NUM_LEDS, (hue++/divisor));
 if(hue == (255 * divisor)) {
   hue = 0;
 }
 FastLED.show();
 delay(5);
}