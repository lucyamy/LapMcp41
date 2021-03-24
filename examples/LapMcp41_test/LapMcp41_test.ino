#include <LapMcp41.h>

/*
  MCP41XXX test
  Increments the value of a pot once per second, repeatedly.
  This will reset to 0 once it hits 256.

  This example code is in the public domain.
 */

// SPI chip select on pin 4
int ss = 4;

LapMcp41 pot(ss);

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pot.
  pot.begin();
}

// the loop routine runs over and over again forever:
void loop() {
  static byte p = 0;
  pot.write(p++);               // Set the pot's value
  delay(1000);                // wait for a second
}
