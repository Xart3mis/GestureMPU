#ifndef MPU6050_IMPLEMENTATION
#define MPU6050_IMPLEMENTATION

#include <Arduino.h>
#include <Wire.h>

struct Vector {
  int16_t AxisX;
  int16_t AxisY;
  int16_t AxisZ;
} Vector;

class MPU6050
{
private:
  int16_t AccelX, AccelY, AccelZ, Temperature, GyroX, GyroY, GyroZ;
  uint8_t _address;

  void _write_i2c(uint8_t deviceAddr, uint8_t regAddress, uint8_t data);

  const uint8_t MPU6050_REGISTER_SIGNAL_PATH_RESET = 0x68;
  const uint8_t MPU6050_REGISTER_ACCEL_CONFIG = 0x1C;
  const uint8_t MPU6050_REGISTER_ACCEL_XOUT_H = 0x3B;
  const uint8_t MPU6050_REGISTER_GYRO_CONFIG = 0x1B;
  const uint8_t MPU6050_REGISTER_SMPLRT_DIV = 0x19;
  const uint8_t MPU6050_REGISTER_PWR_MGMT_1 = 0x6B;
  const uint8_t MPU6050_REGISTER_PWR_MGMT_2 = 0x6C;
  const uint8_t MPU6050_REGISTER_INT_ENABLE = 0x38;
  const uint8_t MPU6050_REGISTER_USER_CTRL = 0x6A;
  const uint8_t MPU6050_REGISTER_FIFO_EN = 0x23;
  const uint8_t MPU6050_REGISTER_CONFIG = 0x1A;

 public:
  void Init();

  int16_t GetAccelX();
  int16_t GetAccelY();
  int16_t GetAccelZ();

  int16_t GetTemperature();

  int16_t GetGyroX();
  int16_t GetGyroY();
  int16_t GetGyroZ();

  void poll();

  MPU6050(uint8_t address);
  ~MPU6050();
};

#endif