#ifndef VT100_H
#define VT100_H

#include <Arduino.h>

class VT100 {
  public:
    VT100(HardwareSerial &serial);

    void begin(long baud);
    void clear();
    void home();
    void move(int row, int col);
    void printAt(int row, int col, const String &text);

  private:
    HardwareSerial &ser;
};

#endif