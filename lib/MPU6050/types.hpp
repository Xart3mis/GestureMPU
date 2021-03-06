#ifndef __TYPES_H__
#define __TYPES_H__

#include <Arduino.h>

typedef struct Vector
{
    int16_t AxisX;
    int16_t AxisY;
    int16_t AxisZ;
} Vector;

typedef Vector GyroOffsets_t;

enum MPU_REGISTERS
{
    MPU6050_REGISTER_SIGNAL_PATH_RESET = 0x68,

    MPU6050_REGISTER_ACCEL_CONFIG = 0x1C,
    MPU6050_REGISTER_ACCEL_XOUT_H = 0x3B,
    MPU6050_REGISTER_ACCEL_XOUT_L = 0x3C,
    MPU6050_REGISTER_ACCEL_YOUT_H = 0x3D,
    MPU6050_REGISTER_ACCEL_YOUT_L = 0x3E,
    MPU6050_REGISTER_ACCEL_ZOUT_H = 0x3F,
    MPU6050_REGISTER_ACCEL_ZOUT_L = 0x40,

    MPU6050_REGISTER_TEMP_OUT_H = 0x41,
    MPU6050_REGISTER_TEMP_OUT_L = 0x42,

    MPU6050_REGISTER_GYRO_XOUT_H = 0x43,
    MPU6050_REGISTER_GYRO_XOUT_L = 0x44,
    MPU6050_REGISTER_GYRO_YOUT_H = 0x45,
    MPU6050_REGISTER_GYRO_YOUT_L = 0x46,
    MPU6050_REGISTER_GYRO_ZOUT_H = 0x47,
    MPU6050_REGISTER_GYRO_ZOUT_L = 0x48,
    MPU6050_REGISTER_GYRO_CONFIG = 0x1B,

    MPU6050_REGISTER_SMPLRT_DIV = 0x19,
    MPU6050_REGISTER_PWR_MGMT_1 = 0x6B,
    MPU6050_REGISTER_PWR_MGMT_2 = 0x6C,
    MPU6050_REGISTER_INT_ENABLE = 0x38,
    MPU6050_REGISTER_USER_CTRL = 0x6A,
    MPU6050_REGISTER_WHO_AM_I = 0x75,
    MPU6050_REGISTER_FIFO_EN = 0x23,
    MPU6050_REGISTER_CONFIG = 0x1A,
};

#endif // __TYPES_H__