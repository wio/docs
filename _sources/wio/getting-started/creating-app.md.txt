# Creating App

Project of type `app` is an executable project that can be executed.

## Setting up the Project
Create wio example project 
```
wio create app avr testDir --create-example
```
* This will create a project in directory `testDir`
* The board for this project is set to `uno` by default 

## Project Structure
```
testDir
├── src
│   └── main.cpp
├── wio.yml
```

## Source Files
* `wio.yml`
```yaml
# define global app configurations. This is an application and can be built, run and uploaded. Some terminology:
# - Framework: SDK for the application (cosa, arduino, c, c++, etc)
# - Platform: platform to build application for
# - Dependencies: wio packages
app:
  name: testDir
  ide: none

  config:
    minimum_wio_version: 0.3.2
    supported_platforms:
    - avr
    supported_frameworks:
    - cosa
    supported_boards:
    - uno

  compile_options:
    platform: avr

# "targets" tag allows for testing and development for various settings and configurations. You can create
# multiple targets where you can define different types of boards, frameworks and flags. By default one target
# is created, which is defined based on settings provided in the creation process.
targets:
  default: main
  create:
    main:
      src: src
      framework: cosa
      board: uno
      flags:
        global_flags: []
        target_flags: []
      definitions:
        global_definitions: []
        target_definitions: []

```
* `src/main.cpp`
```cpp
#include <Cosa/RTT.hh>
#include <Cosa/OutputPin.hh>

OutputPin ledPin(Board::LED);

void setup() {
    RTT::begin();
}

void loop() {
    ledPin.on();
    delay(50);
    ledPin.off();
    delay(500);
}
```

## Run and Upload
* To build the project
```
wio run
```
* To upload the project
```
wio run --upload
```
