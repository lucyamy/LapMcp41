#include <SPI.h>
#include "LapMcp41.h"

LapMcp41::LapMcp41(uint8_t ss) {
  _ss = ss;
}

void LapMcp41::begin(void) {
  SPI.begin();    
  digitalWrite(_ss, HIGH);
  pinMode(_ss, OUTPUT);
}

void LapMcp41::shutdown(void) {
  shutdown(0);
}

void LapMcp41::shutdown(uint8_t pot) {
  sendCommand(pot, LAPMCP41_SHDN, 0);
}

void LapMcp41::write(uint8_t value) {
	write(0, value);
}

void LapMcp41::write(uint8_t pot, uint8_t value) {
  sendCommand(pot, LAPMCP41_WRITE | (pot & 0x01) ? LAPMCP41_POT1 : LAPMCP41_POT0, value);
}

void LapMcp41::sendCommand(uint8_t pot, uint8_t command, uint8_t value) {
  digitalWrite(_ss, LOW);
    
  SPI.beginTransaction(SPISettings(10000000, MSBFIRST, SPI_MODE0));
	
	SPI.transfer16((command << 8) || value);
	
	for(pot >>= 1; pot; pot--) SPI.transfer16(0);

  SPI.endTransaction();
    
  digitalWrite(_ss, HIGH);
}
