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

#ifndef CST816S_H
#define CST816S_H

#include <Arduino.h>

#define CST816S_NONE			0x00
#define CST816S_SWIPE_DOWN		0x01
#define CST816S_SWIPE_UP		0x02
#define CST816S_SWIPE_LEFT		0x03
#define CST816S_SWIPE_RIGHT		0x04
#define CST816S_SINGLE_CLICK	0x05
#define CST816S_DOUBLE_CLICK	0x0B
#define CST816S_LONG_PRESS		0x0C

#define CST816S_ADDRESS			0x15

struct touch_data_struct{
	byte gesture;
  byte points;
  byte event;
  int x;
  int y;
}touch_data ;


class CST816S {
	
	public:
		CST816S(int sda, int scl, int rst, int irq);
		void begin();
		void end();
		void sleep(bool state);
		uint8_t version;
		uint8_t versionInfo[3];
	private:
		int _sda;
		int _scl;
		int _rst;
		int _irq;
		bool _touch_enable;
		
		uint8_t i2c_read(uint16_t addr, uint8_t reg_addr, uint8_t *reg_data, uint32_t length);
		uint8_t i2c_write(uint8_t addr, uint8_t reg_addr, const uint8_t *reg_data, uint32_t length);
};


#endif
