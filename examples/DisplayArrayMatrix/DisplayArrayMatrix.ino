#include "LedControl.h"

/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 2 is connected to the DataIn 
 pin 8 is connected to the CLK 
 pin 3 is connected to LOAD 
 We have only a single MAX72XX.
 */
LedControl lc=LedControl(2,8,3,1);

const uint8_t maxBitmap[][8] = {
	{B00000000,B00111100,B00100100,B00100100,B00100100,B01101100,B01101100,B00000000},
	{B00000000,B01100110,B01100110,B00000000,B00000000,B00100100,B00011000,B00000000}
};

/* we always wait a bit between updates of the display */
unsigned long delaytime=100;

void setup() {
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,8);
  /* and clear the display */
  lc.clearDisplay(0);
}

void loop() { 
  lc.show(maxBitmap[0]);
	delay(1000);
	lc.show(maxBitmap[1]);
	delay(1000);
}
