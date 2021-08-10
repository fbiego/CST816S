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


int enabled = false;

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
	
	if (!enabled) {
    enabled = true;
    pinMode(_rst, OUTPUT);

    digitalWrite(_rst, HIGH );
    delay(50);
    digitalWrite(_rst, LOW);
    delay(5);
    digitalWrite(_rst, HIGH );
    delay(50);

    user_i2c_read(touch_dev_addr, 0x15, &touch_data.version15, 1);
    delay(5);
    user_i2c_read(touch_dev_addr, 0xA7, touch_data.versionInfo, 3);
  }
}

uint8_t CST816S::i2c_read(uint16_t addr, uint8_t reg_addr, uint8_t *reg_data, uint32_t length)
{
  set_i2cReading(true);
  Wire.beginTransmission(addr);
  Wire.write(reg_addr);
  if ( Wire.endTransmission(true))return -1;
  Wire.requestFrom(addr, length, true);
  for (int i = 0; i < length; i++) {
    *reg_data++ = Wire.read();
  }
  set_i2cReading(false);
  return 0;
}