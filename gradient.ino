#include <FastLED.h>

#define LED_PIN     11
#define NUM_LEDS    50
CRGB leds[NUM_LEDS];
int fadeLength = 8;
void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<WS2811, LED_PIN, RGB>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(255);
  Serial.begin(9600);
  Serial.println("hello");
 
  clearAllLEDs();
}

void loop() {
  // put your main code here, to run repeatedly:
leds[0] = CRGB(115,180,240);
for (int i =0; i < NUM_LEDS; i++){


  if (i%2 == 0){
    leds[i] = CRGB(67,52,235);
  }
  if (i%2 == 1){
    leds[i] = CRGB(235,52,107);
  }

  
  for (int j = 1; j < 10; j++){
    
   int index = i-j;
 
   if (index < 0){
    index = NUM_LEDS + index;
   }
   CRGB dimined = leds[index];
   dimined %= 256/fadeLength*j;
   leds[index] = dimined;
   
  }
  
  delay(100);
  FastLED.show();
}
  
}


void clearAllLEDs()
{
  for ( int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
  }
}