#ifndef __I2C_UTILS_H__
#define __I2C_UTILS_H__

#include <Arduino.h>
#include <Wire.h>

class i2c_utils
{
public:
    void _write_i2c(uint8_t device_addr, uint8_t reg_addr, uint8_t data);
    int16_t _read_parse16();
    i2c_utils(/* args */);
    ~i2c_utils();
};
#endif // __I2C_UTILS_H__