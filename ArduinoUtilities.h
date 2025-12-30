//
// Created by ash on 12/14/25.
//

#ifndef UTILITIES_ARDUINOUTILITIES_H
#define UTILITIES_ARDUINOUTILITIES_H
#pragma once

#include <Arduino.h>

// ANSI colors
#define Black "\033[30m"
#define Red "\033[31m"
#define Green "\033[32m"
#define Yellow "\033[33m"
#define Blue "\033[34m"
#define Magenta "\033[35m"
#define Cyan "\033[36m"
#define White "\033[37m"

// ANSI styles
#define Bold "\033[1m"
#define Italic "\033[3m"
#define Underline "\033[4m"
#define Strikethrough "\033[9m"
#define Blinking "\033[5m"
#define Reset "\033[0m"

// Memory macros for clarity
#define HeapStart __heap_start
#define HeapCurrent __brkval


// Print multiple vals in one statement
// Example: serialPrint("hello, ", userName, "!");
template<typename T>
 void serialPrint(const T& value) {
  Serial.println(value);
}
template<typename T, typename... Args>
 void serialPrint(const T& first, const Args&... rest) {
  Serial.print(first);
  serialPrint(rest...);
}

// Clamp values to constraints
// Example: clamp(110, 1, 100);
template<typename T>
 T clamp(T val, T minVal, T maxVal) {
  return (val < minVal) ? minVal : (val > maxVal ? maxVal : val);
}

// Check the amount of free RAM
// Example: Serial.println(freeMemory());
inline int freeMemory() {
  extern int HeapStart, *HeapCurrent;
  int v;
  return reinterpret_cast<int>(&v) - (HeapCurrent == nullptr ? reinterpret_cast<int>(&HeapStart) : reinterpret_cast<int>(HeapCurrent));
}

// Get the size of an array
// Example: arraySize([1, 2, 3]);
template <typename T, size_t N>
size_t arraySize(T (&)[N]) { return N; }

#endif //UTILITIES_ARDUINOUTILITIES_H
