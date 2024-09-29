# CST816S
 An Arduino library for the CST816S capacitive touch screen IC
 
 [![arduino-library-badge](https://www.ardu-badge.com/badge/CST816S.svg?)](https://www.arduinolibraries.info/libraries/cst816-s)

 ## Register Information

 The following information was extracted from (this document)[https://www.waveshare.com/w/upload/c/c2/CST816S_register_declaration.pdf] provided by Waveshare.

 | Register Name     | Address | Bit Description                                       | Default Value | Configuration Options                                          |
|-------------------|---------|-------------------------------------------------------|---------------|----------------------------------------------------------------|
| GestureID         | 0x01    | Gesture code for detected gestures                    | N/A           | 0x00: None, 0x01: Slide Up, 0x02: Slide Down, 0x0B: Double Click |
| FingerNum         | 0x02    | Number of fingers detected                            | N/A           | 0: No finger, 1: One finger                                    |
| XposH             | 0x03    | High 4 bits of X coordinate                           | N/A           | -                                                              |
| XposL             | 0x04    | Low 8 bits of X coordinate                            | N/A           | -                                                              |
| YposH             | 0x05    | High 4 bits of Y coordinate                           | N/A           | -                                                              |
| YposL             | 0x06    | Low 8 bits of Y coordinate                            | N/A           | -                                                              |
| BPC0H             | 0xB0    | High 8 bits of BPC0 value                             | N/A           | -                                                              |
| BPC0L             | 0xB1    | Low 8 bits of BPC0 value                              | N/A           | -                                                              |
| BPC1H             | 0xB2    | High 8 bits of BPC1 value                             | N/A           | -                                                              |
| BPC1L             | 0xB3    | Low 8 bits of BPC1 value                              | N/A           | -                                                              |
| ChipID            | 0xA7    | Chip model identifier                                 | N/A           | -                                                              |
| ProjID            | 0xA8    | Project number                                        | N/A           | -                                                              |
| FwVersion         | 0xA9    | Firmware version number                               | N/A           | -                                                              |
| MotionMask        | 0xEC    | Enable gesture actions like double-click              | 0x00          | Bit 0: EnDClick (enable double-click), Bit 1: EnConUD          |
| IrqPluseWidth     | 0xED    | Interrupt pulse width (0.1 ms units)                  | 10            | 1-200                                                          |
| NorScanPer        | 0xEE    | Normal scan period (10 ms units)                      | 1             | 1-30                                                           |
| MotionSlAngle     | 0xEF    | Gesture detection sliding angle control               | N/A           | -                                                              |
| LpScanRaw1H       | 0xF0    | High 8 bits of low-power scan channel 1 reference     | N/A           | -                                                              |
| LpScanRaw1L       | 0xF1    | Low 8 bits of low-power scan channel 1 reference      | N/A           | -                                                              |
| LpScanRaw2H       | 0xF2    | High 8 bits of low-power scan channel 2 reference     | N/A           | -                                                              |
| LpScanRaw2L       | 0xF3    | Low 8 bits of low-power scan channel 2 reference      | N/A           | -                                                              |
| LpAutoWakeTime    | 0xF4    | Auto recalibration time in low-power mode             | 5 minutes     | 1-5 minutes                                                    |
| LpScanTH          | 0xF5    | Low-power scan wake threshold                         | 48            | 1-255                                                          |
| LpScanWin         | 0xF6    | Low-power scan range                                  | 3             | 0-3                                                            |
| LpScanFreq        | 0xF7    | Low-power scan frequency                              | 7             | 1-255                                                          |
| LpScanIdac        | 0xF8    | Low-power scan current                                | N/A           | 1-255                                                          |
| AutoSleepTime     | 0xF9    | Time in seconds before entering standby mode          | 2 seconds     | 1-255 seconds                                                  |
| IrqCtl            | 0xFA    | Control of interrupt behavior                         | N/A           | EnTest, EnTouch, EnChange, EnMotion                            |
| AutoReset         | 0xFB    | Auto-reset time with no valid gesture detected        | 5 seconds     | 0-5 seconds (0 to disable)                                     |
| LongPressTime     | 0xFC    | Time for long press to trigger reset                  | 10 seconds    | 0-10 seconds (0 to disable)                                    |
| IOCtl             | 0xFD    | IO control settings including soft reset              | N/A           | SOFT_RST, IIC_OD, En1v8                                        |
| DisAutoSleep      | 0xFE    | Disable auto sleep mode                               | 0             | Non-zero value disables auto sleep mode                        |
