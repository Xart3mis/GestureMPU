#include <i2c_utils.h>

i2c_utils::i2c_utils()
{
}

i2c_utils::~i2c_utils()
{
}

void i2c_utils::_write_i2c(uint8_t device_addr, uint8_t reg_addr, uint8_t data, bool write_data)
{
  Wire.beginTransmission(device_addr);
  Wire.write(reg_addr);
  if (write_data)
    Wire.write(data);
  Wire.endTransmission();
}

int16_t i2c_utils::_read_parse16()
{
  return (Wire.read() << 8) | Wire.read();
}
