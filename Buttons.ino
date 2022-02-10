//---// Button Functions //---//

//-// InitButtons //-//
/*
   This function initializes all needed
   things for buttons to work correctly.
*/

void initButtons() {
  for (int i = 0; i < 2; i++) {
    buttons[i].attach(buttonPins[i], INPUT);
    buttons[i].interval(25);
  }
}

//-// UpdateButtons //-//
/*
  This function serves as everything
  the program needs from the outputs
  of the buttons. Most output a
  boolean or int change as a result.
*/

void updateButtons(int butNum) {
  if (butNum == 2) {
    buttons[0].update();
    if (buttons[0].rose()) {

      sleepTimer = 0;

      but2Pressed = true;
      but1Pressed = false;

      butPressed = true;

      butEdit2 = false;

      if (butEdit1 == false) {

        if (butFirst2 == true) {

          state = 0;
          butEdit2 = false;
          butFirst2 = false;
        }
        else {
          state = 1;
          butEdit2 = true;
          butFirst2 = true;
        }
      }

      else {
        timeStop = true;
        curSeconds = 0;
        curMinutes = 0;
        curHours += 1;
      }

      butPressed = false;

    }
  }
  if (butNum == 1) {
    buttons[1].update();
    if (buttons[1].rose()) {

      sleepTimer = 0;

      but1Pressed = true;
      but2Pressed = false;

      butPressed = true;

      butEdit1 = false;

      if (butEdit2 == false) {
        timeStop = false;

        if (butFirst1 == true) {

          state = 2;
          butEdit1 = false;
          butFirst1 = false;
        }
        else {
          state = 3;
          butEdit1 = true;
          butFirst1 = true;
        }
      }

      else {

        lightningStrike = true;

      }

      butPressed = false;

    }
  }
}
