//--//--------------//--//
//  //   SkyWrist   //  //
//--//--------------//--//

//Sullivan Dawson

//---// Libraries //---//
/*
    These are needed to use
    classes from Bounce2,
    NeoPixel, & Tinysnore.
    Buttons, Sleep mode,
    & any of the neopixels.
*/

#include <Bounce2.h>
#include <Adafruit_NeoPixel.h>
#include "tinysnore.h"

//---// Global Vars //---//
/*
   These are variables that
   are used throughout classes
   and the main file. Declaring
   them here means they are
   recognized throughout.
*/

int state = -1;  //-----------------------------------------// "state" Represents the current state of the what, starting -1.
Adafruit_NeoPixel strip(15, 0, NEO_GRB + NEO_KHZ800);  //---// Creates a new Neopixel strip.
int buttonPins[2] = {2, 3};  //-----------------------------// Declares and Initialized a list of button pins.
Bounce * buttons = new Bounce[2];  //-----------------------// Declaring and Initializing with the Bounce2 library for buts.
boolean butFirst1 = true;  //-------------------------------// Boolean if first button mode has been used.
boolean butFirst2 = true;  //-------------------------------// Boolean if first button mode has been used.
boolean butEdit1 = false;  //-------------------------------// Boolean if Edit mode is enabled for one of the buttons.
boolean butEdit2 = false;  //-------------------------------// Boolean if Edit mode is enabled for one of the buttons.
int sunPos = 12;  //----------------------------------------// Int that tracks the sun or moon position.
boolean timeStop = false;  //-------------------------------// Boolean if timer should be stopped.
boolean but1Pressed = false;  //----------------------------// Boolean if but 1 has been pressed last.
boolean but2Pressed = false;  //----------------------------// Boolean if but 2 has been pressed last.
boolean lightningStrike = false;  //------------------------// Boolean if Lightning has struck.
int curHoursOld = 0;  //------------------------------------// Int keeps track of previous hours. To be reset.
boolean butPressed = false;  //-----------------------------// Boolean if a button (not specific) has been pressed.
boolean iWantToSleep = true;  //----------------------------// Boolean a last ditch effort to get fallAsleep() to trigger once.
long sleepTimer = 0;  //------------------------------------// Long for holding current time since last sleepInterval.
long sleepInterval = 30000;  //-----------------------------// Long how long to wait after last button press for sleep to trigger.

//-// Time Stuff //-//

int curSeconds = 0;
int curMinutes = 0;
int curHours = 0;

//-----// SETUP //-----//
/*
   Runs Code once at the
   start of the program.
*/

void setup() {

  start();

}

//-----// LOOP //-----//
/*
   Runs Code repeatedly
   and is the main form
   of code being used for
   the program.
*/

void loop() {

  updateTime();
  updateButtons(1);
  updateButtons(2);
  states();

  fallAsleep();

}

//---// Functoins //---//

void start() {    //Runs code in Setup func (Just to keep it more condensed)

  initButtons();
  initNeopixels();
  strip.setBrightness(15);
  strip.clear();

}

void states() {    //State machine that stores the many states of the program

  switch (state) {
    case -1: fallAsleep();  break;
    case 0: stateTime();    break;
    case 1: stateWet();     break;
    case 2: stateSky();     break;
    case 3: stateSet();     break;
  }

}
