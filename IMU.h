#include <stdint.h>

#ifndef IMU_H
#define IMU_H

  class IMU
  {
  public:

    IMU();
    
    void selectDevice(int file, int addr);
    void readACC(int  a[]);
    void readMAG(int  m[]);
    void readGYR(int g[]);
    void writeAccReg(uint8_t reg, uint8_t value);
    void writeMagReg(uint8_t reg, uint8_t value);
    void writeGyrReg(uint8_t reg, uint8_t value);

  private:
    int file;
    int BerryIMUversion = -1;

    struct calibrate_struct
    {
      int t1;
      int t2;
      int t3;
      int p1;
      int p2;
      int p3;
      int p4;
      int p5;
      int p6;
      int p7;
      int p8;
      int p9;
      int p10;
      int p11;
    } calibrationData;
      

    int detectIMU();
    void enableIMU();
    void  readBlock(uint8_t command, uint8_t size, uint8_t *data);
  };

#endif
