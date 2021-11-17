#ifndef __SONIC_I2C_H
#define __SONIC_I2C_H

#include "Arduino.h"
#include "Wire.h"

class SONIC_I2C 
{
private:
  uint8_t _addr;
  TwoWire* _wire;
  uint8_t _scl;
  uint8_t _sda;
  uint8_t _speed;
public:
  void begin(TwoWire* wire = &Wire, uint8_t addr = 0x57, uint8_t sda = 21, uint8_t scl = 22, uint32_t speed = 200000L);
  float getDistance();
};

#endif
