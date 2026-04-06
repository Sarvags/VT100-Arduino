# VT100 Arduino Library

A lightweight VT100 (ANSI terminal) control library for Arduino.

## Features

1. Clear terminal screen
2. Cursor positioning
3. Print text at specific location
4. Simple and clean API

## Installation

1. Download this repository as ZIP
2. Extract to: Documents/Arduino/libraries/
3. Restart Arduino IDE

## Example

```cpp

#include <VT100.h>

VT100 vt(Serial);

void setup() {
  vt.begin(9600);
  vt.clearScreen();

  vt.printAt(2, 5, "Hello VT100!");
}

void loop() {
}
```

##  Supported Terminals

1. PuTTY
2. Tera Term
3. CoolTerm

##  How it works

This library uses ANSI escape sequences to control terminal behavior over serial communication.

##  Author

Sarvagya Jain

##  License

MIT License