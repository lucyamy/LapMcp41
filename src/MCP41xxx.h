#ifndef _LAPMCP41_H_
#define _LAPMCP41_H_

#include <Arduino.h>

#define LAPMCP41_NOP1  B00000000
#define LAPMCP41_WRITE B00010000
#define LAPMCP41_SHDN  B00100000
#define LAPMCP41_NOP2  B00110000

#define LAPMCP41_NOPOT B00000000
#define LAPMCP41_POT0  B00000001
#define LAPMCP41_POT2  B00000010
#define LAPMCP41_BOTH  B00000011

class LAPMCP41 {
  private:
    uint8_t _ss;
    void sendCommand(uint8_t pot, uint8_t command, uint8_t value);

  public:
    LapMcp41(uint8_t ss);
    void begin(void);
    void shutdown(void);
    void shutdown(uint8_t pot);
    void write(uint8_t value);
    void write(uint8_t pot, uint8_t value);
};

#endif
