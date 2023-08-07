#ifndef MMC5983MA_h
#define MMC5983MA_h

#include "Arduino.h"

#define MMC5983MA_ADDRESS       0x30

#define MMC5983MA_XOUT_0        0x00
#define MMC5983MA_XOUT_1        0x01
#define MMC5983MA_YOUT_0        0x02
#define MMC5983MA_YOUT_1        0x03
#define MMC5983MA_ZOUT_0        0x04
#define MMC5983MA_ZOUT_1        0x05
#define MMC5983MA_XYZOUT_2      0x06
#define MMC5983MA_TOUT          0x07
#define MMC5983MA_STATUS        0x08
#define MMC5983MA_CONTROL_0     0x09
#define MMC5983MA_CONTROL_1     0x0A
#define MMC5983MA_CONTROL_2     0x0B
#define MMC5983MA_CONTROL_3     0x0C
#define MMC5983MA_PRODUCT_ID    0x2F // Should be 0x30

#define MMC5983MA_CONTROL_0_TM_M   0x01
#define MMC5983MA_CONTROL_0_SET    0b1000
#define MMC5983MA_CONTROL_0_RESET  0b10000

// Sample rates
#define MODR_ONESHOT   0x00
#define MODR_1Hz       0x01
#define MODR_10Hz      0x02
#define MODR_20Hz      0x03
#define MODR_50Hz      0x04
#define MODR_100Hz     0x05
#define MODR_200Hz     0x06 // BW = 0x01 only
#define MODR_1000Hz    0x07 // BW = 0x11 only

//Bandwidths
#define MBW_100Hz 0x00  // 8 ms measurement time
#define MBW_200Hz 0x01  // 4 ms
#define MBW_400Hz 0x02  // 2 ms
#define MBW_800Hz 0x03  // 0.5 ms


// Set/Reset as a function of measurements
#define MSET_1     0x00 // Set/Reset each data measurement
#define MSET_25    0x01 // each 25 data measurements
#define MSET_75    0x02
#define MSET_100   0x03
#define MSET_250   0x04
#define MSET_500   0x05
#define MSET_1000  0x06
#define MSET_2000  0x07

class MMC5983MA
{
  private:
    uint8_t rawData[7];
  public:
    // MMC5983MA(I2Cdev* i2c_bus);
    uint8_t getProductID();
    void read();
    // void init(uint8_t MODR, uint8_t MBW, uint8_t MSET);
    // void offsetBias(float * dest1, float * dest2);
    // void reset();
    uint8_t status();
    // void clearInt();
    // void selfTest();
    // void readData(uint32_t * destination);
    // uint8_t readTemperature();
    void SET();
    void RESET();
    // void getOffset(float * destination);
    // void powerDown();
    // void powerUp(uint8_t MODR);
  
  // private:
  // float _mRes;
  // I2Cdev* _i2c_bus;
};

#endif