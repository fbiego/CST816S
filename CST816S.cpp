/*
   MIT License

  Copyright (c) 2021 Felix Biego

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
*/

#include "Arduino.h"
#include <Wire.h>

#include "CST816S.h"


CST816S::CST816S(int sda, int scl, int rst, int irq){
	_sda = sda;
	_scl = scl;
	_rst = rst;
	_irq = irq;
	
}

void CST816S::begin(){
	Wire.begin(_sda, _scl);
	
    pinMode(_irq, INPUT);
	attachInterrupt(_irq, ISR, RISING);

    pinMode(_rst, OUTPUT);

    digitalWrite(_rst, HIGH );
    delay(50);
    digitalWrite(_rst, LOW);
    delay(5);
    digitalWrite(_rst, HIGH );
    delay(50);

    user_i2c_read(CST816S_ADDRESS, 0x15, &data.version, 1);
    delay(5);
    user_i2c_read(CST816S_ADDRESS, 0xA7, data.versionInfo, 3);
}


bool CST816S::available(){
	if (_event_available){
		_event_available = false;
		return true;
	}
	return false;
}

void IRAM_ATTR CST816S::ISR(){
	_event_available = true;
	read_touch();
}

void CST816S::read_touch() {
  byte data_raw[8];
  user_i2c_read(CST816S_ADDRESS, 0x01, data_raw, 6);

  data.gesture = data_raw[0];
  data.points = data_raw[1];
  data.event = data_raw[2] >> 6;
  data.x = data_raw[3];
  data.y = data_raw[5];
}

void CST816S::sleep(bool state) {
  digitalWrite(_rst, LOW);
  delay(5);
  digitalWrite(_rst, HIGH );
  delay(50);
  if (state) {
    byte standby_value = 0x03;
    user_i2c_write(CST816S_ADDRESS, 0xA5, &standby_value, 1);
  }
}

uint8_t CST816S::i2c_read(uint16_t addr, uint8_t reg_addr, uint8_t *reg_data, uint32_t length)
{
  Wire.beginTransmission(addr);
  Wire.write(reg_addr);
  if ( Wire.endTransmission(true))return -1;
  Wire.requestFrom(addr, length, true);
  for (int i = 0; i < length; i++) {
    *reg_data++ = Wire.read();
  }
  return 0;
}


uint8_t CST816S::i2c_write(uint8_t addr, uint8_t reg_addr, const uint8_t *reg_data, uint32_t length)
{
  Wire.beginTransmission(addr);
  Wire.write(reg_addr);
  for (int i = 0; i < length; i++) {
    Wire.write(*reg_data++);
  }
  if ( Wire.endTransmission(true))return -1;
  return 0;
}