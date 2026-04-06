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

    // NEW FEATURES
    void color(int code);
    void reset();
    void hideCursor();
    void showCursor();

    void drawBox(int row1, int col1, int row2, int col2);

  private:
    HardwareSerial &ser;
};

#endif