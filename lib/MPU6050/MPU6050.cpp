#include "MPU6050.h"

MPU6050::MPU6050(uint8_t address) : AccelRaw(), Temperature(), GyroRaw(), _address(address) {}

void MPU6050::Init()
{
  i2c._write_i2c(_address, MPU6050_REGISTER_SIGNAL_PATH_RESET, 0x00); //00000000
  i2c._write_i2c(_address, MPU6050_REGISTER_ACCEL_CONFIG, 0x00);      //00000000
  i2c._write_i2c(_address, MPU6050_REGISTER_GYRO_CONFIG, 0x00);       //00000000
  i2c._write_i2c(_address, MPU6050_REGISTER_SMPLRT_DIV, 0x07);        //01110000
  i2c._write_i2c(_address, MPU6050_REGISTER_PWR_MGMT_1, 0x01);        //00010000
  i2c._write_i2c(_address, MPU6050_REGISTER_PWR_MGMT_2, 0x00);        //00000000
  i2c._write_i2c(_address, MPU6050_REGISTER_INT_ENABLE, 0x01);        //00010000
  i2c._write_i2c(_address, MPU6050_REGISTER_USER_CTRL, 0x00);         //00000000
  i2c._write_i2c(_address, MPU6050_REGISTER_FIFO_EN, 0x00);           //00000000
  i2c._write_i2c(_address, MPU6050_REGISTER_CONFIG, 0x00);            //00000000
}

void MPU6050::poll()
{
  // Wire.beginTransmission(_address);
  // Wire.write(MPU6050_REGISTER_ACCEL_XOUT_H);
  // Wire.endTransmission();
  i2c._write_i2c(_address, MPU6050_REGISTER_ACCEL_XOUT_H, -1);

  Wire.requestFrom(_address, (size_t)14, true);

  AccelRaw.AxisX = i2c._read_parse16();
  AccelRaw.AxisY = i2c._read_parse16();
  AccelRaw.AxisZ = i2c._read_parse16();

  Temperature = i2c._read_parse16();

  GyroRaw.AxisX = i2c._read_parse16();
  GyroRaw.AxisY = i2c._read_parse16();
  GyroRaw.AxisZ = i2c._read_parse16();
}

Vector MPU6050::GetAccel()
{
  return AccelRaw;
}

Vector MPU6050::GetGyro()
{
  return GyroRaw;
}

int16_t MPU6050::GetTemperature()
{
  return Temperature;
}

MPU6050::~MPU6050() {}