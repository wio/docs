# Creating Pkg

Project of type `pkg` is a package that is meant to be imported by other projects. This makes code sharing easier and modular.

## Setting up the Project
Create wio example project 
```
wio create pkg avr testDir --create-example
```
* This will create a project in directory `testDir`
* The board for the test target is set to `uno` by default 

## Project Structure
```
testDir
├── include
│   └── output.h
├── src
│   └── output.cpp
├── tests
│   └── main.cpp
├── wio.yml
```

## Source Files
* `wio.yml`
```yaml
# define global pkg configurations. This is a package and is created to be used by other wio projects. Even though
# package cannot be built, it can be tested by using "tests" directory. Some terminology:
# - Framework: SDK for the application (cosa, arduino, c, c++, etc)
# - Platform: platform to build application for
# - Dependencies: wio packages
pkg:
  ide: none

  meta:
    name: testDir
    description: A wio avr pkg using cosa framework
    version: 0.0.1
    keywords:
    - avr
    - c
    - c++
    - wio
    - cosa
    license: MIT

  config:
    minimum_wio_version: 0.3.2
    supported_platforms:
    - avr
    supported_frameworks:
    - cosa
    supported_boards:
    - uno

  compile_options:
    header_only: false
    platform: avr
  flags:
    allow_only_global_flags: false
    allow_only_required_flags: false
    global_flags: []
    visibility: PRIVATE
  definitions:
    allow_only_global_definitions: false
    allow_only_required_definitions: false
    global_definitions: []
    visibility: PRIVATE

# "targets" tag allows for testing and development for various settings and configurations. You can create
# multiple targets where you can define different types of boards, frameworks and flags. By default one target
# is created, which is defined based on settings provided in the creation process.
targets:
  default: tests
  create:
    tests:
      src: tests
      framework: cosa
      board: uno
      flags:
        global_flags: []
        target_flags: []
        pkg_flags: []
      definitions:
        global_definitions: []
        target_definitions: []
        pkg_definitions: []
```
* `include/output.h`
```cpp
#ifndef OUTPUT_H
#define OUTPUT_H

// Turns built in LED ON (PIN 13)
void builtLedOn();

// Turns built in LED OFF (PIN 13)
void builtLedOff();

#endif /* OUTPUT_H */

```
* `src/output.cpp`
```cpp
#include <Cosa/OutputPin.hh>
#include <output.h>

OutputPin ledPin(Board::LED);

void builtLedOn() {
    ledPin.on();
}

void builtLedOff() {
    ledPin.off();
}
```
* `tests/main.cpp`
```cpp
#include <Cosa/RTT.hh>
#include <output.h>

void setup() {
    RTT::begin();
}

void loop() {
    builtLedOn();
    delay(50);
    builtLedOff();
    delay(500);
}
```

## Run and Upload Test target
* To build the project
```
wio run
```
* To upload the project
```
wio run --upload
```
