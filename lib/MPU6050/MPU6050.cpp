#include "MPU6050.h"

MPU6050::MPU6050(uint8_t address): AccelX(), AccelY(), AccelZ(), Temperature(), GyroX(), GyroY(), GyroZ(), _address(address){}

void MPU6050::_write_i2c(uint8_t deviceAddr, uint8_t regAddress, uint8_t data) {
  Wire.beginTransmission(deviceAddr);
  Wire.write(regAddress);
  Wire.write(data);
  Wire.endTransmission();
}

void MPU6050::Init() {
  delay(150);
  _write_i2c(_address, MPU6050_REGISTER_SIGNAL_PATH_RESET, 0x00);
  _write_i2c(_address, MPU6050_REGISTER_ACCEL_CONFIG, 0x00);
  _write_i2c(_address, MPU6050_REGISTER_GYRO_CONFIG, 0x00);
  _write_i2c(_address, MPU6050_REGISTER_SMPLRT_DIV, 0x07);
  _write_i2c(_address, MPU6050_REGISTER_PWR_MGMT_1, 0x01);
  _write_i2c(_address, MPU6050_REGISTER_PWR_MGMT_2, 0x00);
  _write_i2c(_address, MPU6050_REGISTER_INT_ENABLE, 0x01);
  _write_i2c(_address, MPU6050_REGISTER_USER_CTRL, 0x00);
  _write_i2c(_address, MPU6050_REGISTER_FIFO_EN, 0x00);
  _write_i2c(_address, MPU6050_REGISTER_CONFIG, 0x00);
  delay(150);
}

void MPU6050::poll() {
  Wire.beginTransmission(_address);
  Wire.write(MPU6050_REGISTER_ACCEL_XOUT_H);
  Wire.endTransmission();

  Wire.requestFrom(_address, (size_t)14, true);

  AccelX = (Wire.read() << 8) | Wire.read();
  AccelY = (Wire.read() << 8) | Wire.read();
  AccelZ = (Wire.read() << 8) | Wire.read();

  Temperature = (Wire.read() << 8) | Wire.read();

  GyroX = (Wire.read() << 8) | Wire.read();
  GyroY = (Wire.read() << 8) | Wire.read();
  GyroZ = (Wire.read() << 8) | Wire.read();
}

int16_t MPU6050::GetAccelX() { return AccelX; }
int16_t MPU6050::GetAccelY() { return AccelY; }
int16_t MPU6050::GetAccelZ() { return AccelZ; }

int16_t MPU6050::GetTemperature() { return Temperature; }

int16_t MPU6050::GetGyroX() { return GyroX; }
int16_t MPU6050::GetGyroY() { return GyroY; }
int16_t MPU6050::GetGyroZ() { return GyroZ; }

MPU6050::~MPU6050() {}