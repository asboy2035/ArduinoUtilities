//
// Created by ash on 12/14/25.
//

#ifndef UTILITIES_ARDUINOUTILITIES_H
#define UTILITIES_ARDUINOUTILITIES_H
#pragma once
#include <Arduino.h>

template<typename T>
inline void serialPrint(const T& value) {
  Serial.println(value);
}

template<typename T, typename... Args>
inline void serialPrint(const T& first, const Args&... rest) {
  Serial.print(first);
  serialPrint(rest...);
}
#endif //UTILITIES_ARDUINOUTILITIES_H
