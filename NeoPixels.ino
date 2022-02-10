//---// NeoPixel Functions //---//

//-// InitNeopixels //-//
/*
   Initializes all things
   needed for neopixels
   to work.
*/

void initNeopixels() {
  strip.begin();
  strip.clear();
  strip.show();
  strip.setBrightness(15);
}

//-// AllNeopixels //-//
/*
   This function colors all
   pixels on the strand to
   be a certain c color.
*/

void allNeopixels(int c) {
  strip.clear();
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, Wheel(c));
  }
  strip.show();
}

//-// Wheel //-//
/*
   This Funtion takes in an int
   and returns a uint32_t to be
   used for coloring pixels.
*/

uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if (WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
