# LapMcp41 Arduino driver Library

## Introduction

The MCP41XXX and MCP42XXX devices are 256-position, digital potentiometers available in 10k, 50k and 100k resistance versions. The MCP41XXX is a single-channel device and is offered in an 8-pin PDIP or SOIC package. The MCP42XXX contains two independent channels in a 14-pin PDIP, SOIC or TSSOP package. The wiper position of the MCP41XXX/42XXX varies linearly and is controlled via the SPI interface. A software shutdown feature is provided that disconnects the “A” terminal from the resistor stack and simultaneously connects the wiper to the “B” terminal. During shutdown mode, the contents of the wiper register can be changed and the potentiometer returns from shutdown to the new value. The wiper is reset to the mid-scale position (80h) upon power-up. The MCP42XXX SPI interface includes both the SI and SO pins, allowing daisy-chaining of multiple devices.

The LapMcp41 library functions can be passed a **pot** parameter to identify which potentiometer is to be used. This number is **zero** for the first pot, and **one** for the other pot in the chip if the MCP42XXX dual potentiometer is used. Subsequent chips in the daisy chain, if present, are given increasing pot numbers. Note that the MCP41XXX cannot be daisy chained, though it can appear as the last device in such a chain.

**LapMcp41** is invoked as:
 
LapMcp41(uint8_t ss);
---------------------

The ss argument is the pin used as the SPI chip select.

The functions provided by **LapMcp41** are:

void begin();
-------------
This must be called before using any other function. It initialises the SPI system, and sets up the select pin.

void shutdown();
--------------------
void shutdown(uint8_t pot);
---------------------------
Shuts down the pot as outlined in the introduction.

void write(uint8_t value);
--------------------------
void write(uint8_t pot, uint8_t value);
---------------------------------------
Writes the 0-255 value to the pot.

