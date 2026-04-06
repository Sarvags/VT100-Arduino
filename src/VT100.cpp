#include "VT100.h"

VT100::VT100(HardwareSerial &serial) : ser(serial) {}

void VT100::begin(long baud) {
  ser.begin(baud);
  delay(1000);
}

void VT100::clearScreen() {
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

// NEW FEATURES

void VT100::color(int code) {
  ser.write(27);
  ser.print("[");
  ser.print(code);
  ser.print("m");
}

void VT100::reset() {
  ser.write(27);
  ser.print("[0m");
}

void VT100::hideCursor() {
  ser.write(27);
  ser.print("[?25l");
}

void VT100::showCursor() {
  ser.write(27);
  ser.print("[?25h");
}

void VT100::drawBox(int row1, int col1, int row2, int col2) {
  // Top and Bottom borders
  for (int col = col1; col <= col2; col++) {
    move(row1, col);
    ser.print("-");

    move(row2, col);
    ser.print("-");
  }

  // Left and Right borders
  for (int row = row1; row <= row2; row++) {
    move(row, col1);
    ser.print("|");

    move(row, col2);
    ser.print("|");
  }

  // Corners
  move(row1, col1); ser.print("+");
  move(row1, col2); ser.print("+");
  move(row2, col1); ser.print("+");
  move(row2, col2); ser.print("+");
}