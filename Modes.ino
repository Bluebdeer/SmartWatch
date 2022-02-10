//---// States Functions //---//

//-// FallAsleep //-//
/*
   This funtion is meant to
   trigger the sleep state a
   specified amount of time
   since the last button input.
   However, despite the attempts
   with booleans beneath, it
   refuses to behave in this way.
*/

void fallAsleep() {
  if (butPressed == false) {
    if (iWantToSleep == true) {
      sleepTimer = 0;
      iWantToSleep = false;
    }
    if (millis() - sleepTimer > sleepInterval) {
      strip.clear(); strip.show();  // Clear out NeoPixel Display
      snore(5000);                 // Go to Sleep for 5 Seconds
      sleepTimer = millis();
    }
  }
  if (butPressed == true) {
    iWantToSleep = true;
  }
}

//-// UpdateTime //-//
/*
   This function updates
   the overall time of
   the program. Keeping
   track of and converting
   seconds, minutes, & hours.
*/

void updateTime() {

  if (timeStop == false) {
    curSeconds = millis() / 100;
  }

  if (curSeconds >= 60) {

    curSeconds = 0;
    curMinutes += 1;

    if (curMinutes >= 60) {

      curMinutes = 0;
      curHours += 1;

      if (curHours > 24) {

        curHours = 0;
        curMinutes = 0;
        curSeconds = 0;

      }
    }
  }

  sunPos = curHours;

}

//-// SKY STATE //-//
/*
   This state has the individual
   frames for each hour of the
   sky state. This is very
   inefficient, but I had the
   storage space to spare.
*/

void stateSky() {
  int sunColorNum = 45;
  int moonColorNum = 200;

  if (sunPos == 0) {
    allNeopixels(198);
    strip.setBrightness(15);
    strip.setPixelColor(5, 255);
    strip.setPixelColor(5, Wheel(sunColorNum));
    strip.show();
  }
  if (sunPos == 1) {
    allNeopixels(188);
    strip.setPixelColor(5, 255);
    strip.setPixelColor(5, Wheel(sunColorNum));
    strip.setPixelColor(4, 255);
    strip.setPixelColor(4, Wheel(sunColorNum));
    strip.show();
  }
  if (sunPos == 2) {
    allNeopixels(178);
    strip.setPixelColor(4, 255);
    strip.setPixelColor(4, Wheel(sunColorNum));
    strip.show();
  }
  if (sunPos == 3) {
    allNeopixels(168);
    strip.setPixelColor(4, 255);
    strip.setPixelColor(4, Wheel(sunColorNum));
    strip.setPixelColor(3, 255);
    strip.setPixelColor(3, Wheel(sunColorNum));
    strip.show();
  }
  if (sunPos == 4) {
    allNeopixels(158);
    strip.setPixelColor(3, 255);
    strip.setPixelColor(3, Wheel(sunColorNum));
    strip.show();
  }
  if (sunPos == 5) {
    allNeopixels(138);
    strip.setPixelColor(3, 255);
    strip.setPixelColor(3, Wheel(sunColorNum));
    strip.setPixelColor(2, 255);
    strip.setPixelColor(2, Wheel(sunColorNum));
    strip.show();
  }
  if (sunPos == 6) {
    allNeopixels(128);
    strip.setPixelColor(2, 255);
    strip.setPixelColor(2, Wheel(sunColorNum));
    strip.show();
  }
  if (sunPos == 7) {
    allNeopixels(138);
    strip.setPixelColor(2, 255);
    strip.setPixelColor(2, Wheel(sunColorNum));
    strip.setPixelColor(1, 255);
    strip.setPixelColor(1, Wheel(sunColorNum));
    strip.show();
  }
  if (sunPos == 8) {
    allNeopixels(158);
    strip.setPixelColor(1, 255);
    strip.setPixelColor(1, Wheel(sunColorNum));
    strip.show();
  }
  if (sunPos == 9) {
    allNeopixels(168);
    strip.setPixelColor(1, 255);
    strip.setPixelColor(1, Wheel(sunColorNum));
    strip.setPixelColor(0, 255);
    strip.setPixelColor(0, Wheel(sunColorNum));
    strip.show();
  }
  if (sunPos == 10) {
    allNeopixels(178);
    strip.setPixelColor(0, 255);
    strip.setPixelColor(0, Wheel(sunColorNum));
    strip.show();
  }
  if (sunPos == 11) {
    allNeopixels(188);
    strip.setPixelColor(0, 255);
    strip.setPixelColor(0, Wheel(sunColorNum));
    strip.setPixelColor(9, 255);
    strip.setPixelColor(9, Wheel(sunColorNum));
    strip.show();
  }
  if (sunPos == 12) {
    allNeopixels(198);
    strip.setPixelColor(9, 255);
    strip.setPixelColor(9, Wheel(sunColorNum));
    strip.show();
  }

  //-//

  if (sunPos == 13) {
    strip.setBrightness(0);
    allNeopixels(198);
    strip.setBrightness(15);
    strip.setPixelColor(5, 255);
    strip.setPixelColor(5, Wheel(moonColorNum));
    strip.show();
  }
  if (sunPos == 14) {
    strip.setBrightness(0);
    allNeopixels(188);
    strip.setBrightness(15);
    strip.setPixelColor(5, 255);
    strip.setPixelColor(5, Wheel(moonColorNum));
    strip.setPixelColor(4, 255);
    strip.setPixelColor(4, Wheel(moonColorNum));
    strip.show();
  }
  if (sunPos == 15) {
    strip.setBrightness(0);
    allNeopixels(178);
    strip.setBrightness(15);
    strip.setPixelColor(4, 255);
    strip.setPixelColor(4, Wheel(moonColorNum));
    strip.show();
  }
  if (sunPos == 16) {
    strip.setBrightness(0);
    allNeopixels(168);
    strip.setBrightness(15);
    strip.setPixelColor(4, 255);
    strip.setPixelColor(4, Wheel(moonColorNum));
    strip.setPixelColor(3, 255);
    strip.setPixelColor(3, Wheel(moonColorNum));
    strip.show();
  }
  if (sunPos == 17) {
    strip.setBrightness(0);
    allNeopixels(158);
    strip.setBrightness(15);
    strip.setPixelColor(3, 255);
    strip.setPixelColor(3, Wheel(moonColorNum));
    strip.show();
  }
  if (sunPos == 18) {
    strip.setBrightness(0);
    allNeopixels(138);
    strip.setBrightness(15);
    strip.setPixelColor(3, 255);
    strip.setPixelColor(3, Wheel(moonColorNum));
    strip.setPixelColor(2, 255);
    strip.setPixelColor(2, Wheel(moonColorNum));
    strip.show();
  }
  if (sunPos == 19) {
    strip.setBrightness(0);
    allNeopixels(128);
    strip.setBrightness(15);
    strip.setPixelColor(2, 255);
    strip.setPixelColor(2, Wheel(moonColorNum));
    strip.show();
  }
  if (sunPos == 20) {
    strip.setBrightness(0);
    allNeopixels(138);
    strip.setBrightness(15);
    strip.setPixelColor(2, 255);
    strip.setPixelColor(2, Wheel(moonColorNum));
    strip.setPixelColor(1, 255);
    strip.setPixelColor(1, Wheel(moonColorNum));
    strip.show();
  }
  if (sunPos == 21) {
    strip.setBrightness(0);
    allNeopixels(158);
    strip.setBrightness(15);
    strip.setPixelColor(1, 255);
    strip.setPixelColor(1, Wheel(moonColorNum));
    strip.show();
  }
  if (sunPos == 22) {
    strip.setBrightness(0);
    allNeopixels(168);
    strip.setBrightness(15);
    strip.setPixelColor(1, 255);
    strip.setPixelColor(1, Wheel(moonColorNum));
    strip.setPixelColor(0, 255);
    strip.setPixelColor(0, Wheel(moonColorNum));
    strip.show();
  }
  if (sunPos == 23) {
    strip.setBrightness(0);
    allNeopixels(178);
    strip.setBrightness(15);
    strip.setPixelColor(0, 255);
    strip.setPixelColor(0, Wheel(moonColorNum));
    strip.show();
  }
  if (sunPos == 24) {
    strip.setBrightness(0);
    allNeopixels(188);
    strip.setBrightness(15);
    strip.setPixelColor(0, 255);
    strip.setPixelColor(0, Wheel(moonColorNum));
    strip.setPixelColor(9, 255);
    strip.setPixelColor(9, Wheel(moonColorNum));
    strip.show();
  }
}

//-// SET STATE //-//
/*
   This state allows the
   user to set the time
   while viewing the SKY state.
*/

void stateSet() {
  stateSky();
}

//-// TIME STATE //-//
/*
   This state shows the
   minutes in the current
   hour. This being 4mins
   per LED lighting up.
*/

void stateTime() {
  strip.clear();
  for (int i = 0; i < map(curMinutes, 15, 60, 0, strip.numPixels()); i++) {
    strip.setPixelColor(i, Wheel(150));
  }
  strip.show();
}

//-// WET STATE //-//
/*
   This state displays
   a raincloud with small
   droplets of rain falling.
   The user can press the
   activation button to
   cause lightning to strike
   randomly in 1 of 4 locations.
   This is my personal favorite
   mode as it is very chill.
*/

void stateWet() {
  if (lightningStrike == false) {
    strip.clear();
    strip.setBrightness(6);
    for (int i = 0; i < 5; i++) {
      strip.setPixelColor(i, 255, 255, 255);
    }
    if (curHours > curHoursOld) {
      strip.setBrightness(15);
      strip.setPixelColor(int(random(5, 14)), 0, 0, 100);
      strip.setPixelColor(int(random(5, 14)), 0, 0, 100);
      strip.setPixelColor(int(random(5, 14)), 0, 0, 100);
    }
    strip.show();
  }
  else {
    strip.clear();
    strip.setBrightness(6);
    for (int i = 0; i < 5; i++) {
      strip.setPixelColor(i, 255, 255, 255);
    }

    int strikePlace = int(random(1, 5));

    strip.setBrightness(50);
    if (strikePlace == 1) {
      strip.setPixelColor(9, 0, 255, 255);
      strip.setPixelColor(11, 0, 255, 255);
    }
    if (strikePlace == 2) {
      strip.setPixelColor(7, 0, 255, 255);
      strip.setPixelColor(13, 0, 255, 255);
    }
    if (strikePlace == 3) {
      strip.setPixelColor(7, 0, 255, 255);
      strip.setPixelColor(11, 0, 255, 255);
    }
    if (strikePlace == 4) {
      strip.setPixelColor(6, 0, 255, 255);
      strip.setPixelColor(14, 0, 255, 255);
    }
    lightningStrike = false;
    strip.show();
  }

  curHoursOld = curHours;
}
