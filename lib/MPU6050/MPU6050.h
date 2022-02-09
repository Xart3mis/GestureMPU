#ifndef __MPU6050_H__
#define __MPU6050_H__

#include <Arduino.h>

#include "i2c_utils.h"
#include "types.hpp"

class MPU6050
{
private:
  int16_t Temperature;
  Vector GyroRaw, AccelRaw;
  uint8_t _address;

  i2c_utils i2c;

public:
  void Init();

  Vector GetAccel();
  Vector GetGyro();

  int16_t GetTemperature();

  void poll();

  MPU6050(uint8_t address);
  ~MPU6050();
};
#endif // __MPU6050_H__