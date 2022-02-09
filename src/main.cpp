#include <Arduino.h>
#include <Wire.h>

#include "MPU6050.h"

MPU6050 mpu = MPU6050(0x68);

void setup()
{
#ifdef ARDUINO_ARCH_STM32
  Wire.setSDA(PB9);
  Wire.setSCL(PB8);
#endif // ARDUINO_ARCH_STM32

  Wire.begin();
  Serial.begin(115200);
  mpu.Init();
}

void loop()
{
  mpu.poll();
  Serial.println(mpu.GetAccel().AxisX);
}