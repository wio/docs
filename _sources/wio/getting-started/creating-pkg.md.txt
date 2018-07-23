# Creating Pkg

In the ecosystem of `wio`, `pkg` is a project that is included as a dependency by other projects. It cannot be executed on its own.

## Setting up the Project
```
wio create pkg examplePackage 
```
* This will create a project in directory `examplePackage`

Congrats you have created your first `wio` package. Your project structure will look like this:
```
examplePackage
├── include
├── src
├── tests
├── wio.yml
├── README.md
├── .gitignore
```

The result of generated `wio.yml` file:
```yaml
type: pkg

project:
  name: examplePackage
  version: 0.0.1
  keywords:
  - wio
  - pkg
  compile_options:
    wio_version: 0.4.0
    default_target: tests

targets:
  tests:
    src: tests
```

## Initialize the Package

Now we will create `hello.hh` and `hello.cpp` files and place them in `include` and `src ` folder respectively.

`hello.hh` file in `include` directory:
```cpp
#ifndef HELLO_HH
#define HELLO_HH

void printHello();

#endif
```

`hello.cpp` file in `src` directory:
```cpp
#include "hello.hh"

#if defined(WIO_PLATFORM_AVR) && defined(WIO_FRAMEWORK_ARDUINO)
#include <Arduino.h>

void printHello() {
    Serial.println("Hello world");
}
#elif defined(WIO_PLATFORM_NATIVE)
#include <iostream>

void printHello() {
    std::cout << "Hello World" << std::endl;
}
#else
#error "Unsupported Platform or Framework"
#endif
```

Final project structure will look like:
```
examplePackage
└── include
    └── hello.hh
└── src
    └── hello.cpp
├── wio.yml
├── README.md
├── .gitignore
```

## Building and Executing

We have a package where "Hello World" is printed based on what platform the code is compiled and executed on. In order to test this package, we will create multiple targets for various platforms and see if our package code works.

`wio.yml` after update:
```yaml
type: pkg

project:
  name: examplePackage
  license: MIT
  author: Wio
  version: 0.0.1
  keywords:
  - wio
  - app
  compile_options:
    wio_version: 0.4.0
    default_target: main

targets:
  native:
    src: tests/native
    platform: native
  arduino:
    src: tests/arduino
    platform: avr
    framework: arduino
    board: uno
  cosa:
    src: tests/cosa
    platform: avr
    framework: cosa
    board: uno
```

Testing the package is simple but, before we do that, we need to create a simple test for `native` and `avr` platforms.

`test.cpp` file in `tests/native` directory:
```cpp
#include <hello.hh>

int main() {
    printHello();
}
```

`test.cpp` file in `tests/arduino` directory:
```cpp
#include <hello.hh>
#include <Arduino.h>

void setup() {
    Serial.begin(9600);
}

void loop() {
    printHello();
}
```

`test.cpp` file in `tests/cosa` directory:
```cpp
#include <hello.hh>
#include <UART.hh>

void setup() {
    uart.begin(9600);
}

void loop() {
    printHello();
}
```

Now to build each target:
```bash
# native target (valid build)
wio build native

# arduino target (valid build)
wio build arduino

# cosa target (invalid build)
wio build cosa
```

To execute each target:
```bash
# native
wio run native

# arduino
wio run arduino

# cosa (this won't work because cosa target is not compiled)
wio run cosa
```

