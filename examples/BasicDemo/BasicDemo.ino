#include <VT100.h>

VT100 vt(Serial);

void setup() {
  vt.begin(9600);
  vt.clear();

  vt.drawBox(1, 1, 10, 40);
  vt.printAt(2, 3, "VT100 UI BOX!");
}

void loop() {
}