#include "VT100.h"

VT100::VT100(HardwareSerial &serial) : ser(serial) {}

void VT100::begin(long baud) {
  ser.begin(baud);
  delay(1000);
}

void VT100::clear() {
  ser.write(27);
  ser.print("[2J");
}

void VT100::home() {
  ser.write(27);
  ser.print("[H");
}

void VT100::move(int row, int col) {
  ser.write(27);
  ser.print("[");
  ser.print(row);
  ser.print(";");
  ser.print(col);
  ser.print("H");
}

void VT100::printAt(int row, int col, const String &text) {
  move(row, col);
  ser.print(text);
}