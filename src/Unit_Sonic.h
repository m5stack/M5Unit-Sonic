#ifndef _UNIT_SONIC_H_
#define _UNIT_SONIC_H_

#include "Arduino.h"
#include "Wire.h"

class SONIC_I2C {
   private:
    uint8_t _addr;
    TwoWire* _wire;
    uint8_t _scl;
    uint8_t _sda;
    uint8_t _speed;

   public:
    void begin(TwoWire* wire = &Wire, uint8_t addr = 0x57, uint8_t sda = 21,
               uint8_t scl = 22, uint32_t speed = 200000L);
    float getDistance();
};

class SONIC_IO {
   private:
    uint8_t _trig;
    uint8_t _echo;

   public:
    void begin(uint8_t trig = 26, uint8_t echo = 36);
    float getDuration();
    float getDistance();
};

#endif