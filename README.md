# ArduinoUtilities
A set of useful utilities (currently only one) for Arduino devs.

## Installation
1. Clone this repo anywhere.
2. Symlink/move the file `ArduinoUtilities.h` to your preferred Arduino lib search path.
3. Include with `#include <ArduinoUtilities.h>`

## Utilities
### `serialPrint()` :
- Gives Python-like single print abilities.
- Usage: `serialPrint(params[]);`
- Example:
  ```c++
  #include <ArduinoUtilities.h>
  
  void setup() {
    float temp = 32.76;
    serialPrint("Temp: ", temp, "°C")
  }

  // out: "Temp: 32.76°C" (without quotes)
  ```
