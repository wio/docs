# Creating App

In the ecosystem of `wio`, `app` is a project that can be executed or uploaded. It is what runs on machines and displays "Hello world".

## Setting up the Project 
```
wio create app projectDir
```
* This will create a project in directory `projectDir`
* This application has no `platform`, `framework`, and `board`
    * You will need to specify these fields before a project can be built.
    * You can create various targets for various configurations.
    * For example to create an `AVR` project:
    ```
    wio create app --platform avr --framework arduino --board uno projectDir
    ```

Congrats you have created your first `wio` application. Your project structure will look like this:
```
projectDir
├── src
├── wio.yml
├── README.md
├── .gitignore
```

The result of generated `wio.yml` file:
```yaml
type: app

project:
  name: projectDir
  version: 0.0.1
  keywords:
  - wio
  - app
  compile_options:
    wio_version: 0.4.0
    default_target: main

targets:
  main:
    src: src
```

## Initialize the App

Now you can create `main_native.cpp` and `main_arduino.cpp` files and place them in `src` folder based on their target.

```bash
cd projectDir
mkdir src/native
mkdir src/arduino
```

`main_native.cpp` file in `src/native` directory:
```cpp
#include <iostream>

int main() {
    std::cout << "Hello world!!" << std::endl;
}
```

`main_arduino.cpp` file in `src/arduino` directory:
```cpp
/**
 * Blink
 *
 * Turns on an LED on for one second,
 *  then off for one second, repeatedly.
 */

#include "Arduino.h"

#ifndef LED_BUILTIN 
#define LED_BUILTIN 13
#endif

void setup() {
    // initialize LED digital pin as an output. 
    pinMode(LED_BUILTIN, OUTPUT);
} 

void loop() {
    // turn the LED on (HIGH is the voltage level) 
    digitalWrite(LED_BUILTIN, HIGH);

    // wait for a second 
    delay(1000);
    
    // turn the LED off by making the voltage LOW
    digitalWrite(LED_BUILTIN, LOW);
    
    // wait for a second 
    delay(1000);
}
```

Final project structure will look like:
```
projectDir
└── src
    └── native
        └── main_native.cpp
    └── arduino
        └── main_arduino.cpp
├── wio.yml
├── README.md
├── .gitignore
```

## Building and Executing

We have two sets of code that we want to build and run. This is achieved by using targets. We will modify `wio.yml` file and create a target for both `native` and `arduino` code.

`wio.yml` after update:
```yaml
type: app

project:
  name: projectDir
  version: 0.0.1
  keywords:
  - wio
  - app
  compile_options:
    wio_version: 0.4.0

targets:
  native:
    src: src/native
    platform: native
  arduino:
    src: src/arduino
    platform: avr
    framework: arduino
    board: uno
```

If you want to test using a different framework like `Cosa` or a different board like `mega2560`, you can create even more targets.

Building each target is very simple:
```bash
# native target
wio build native

# arduino target
wio build arduino
```

To execute each target:
```bash
# native
wio run native

# arduino
wio run arduino
```

