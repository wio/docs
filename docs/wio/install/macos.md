# MacOS

Wio is available for macOS platform through `NPM` and `Homebrew`. 

## Homebrew
Homebrew is a package manager for MacOS
```bash
# installing wio
brew tap dhillondeep/wio
brew install dhillondeep/wio/wio
```

## NPM
NPM is a node package manager and can be downloaded using:
```bash
brew install node
```

If you have any issues, check [npm install website](https://www.npmjs.com/get-npm). 

Now that you have `npm` installed, you can use it to install `wio`:
```bash
npm install -g wio
```
Sometimes there are issues with permission, and to resolve those issues, you can do,
```bash
sudo npm install -g wio --unsafe-perm
```

Hurray! you have **wio** installed but wait there are few more things before you get started. You will have to install toolchain for the platform you are building. You will also have to install build tools used by **wio**

## Wio build Tools
Wio uses `cmake` and `make` to compile the project. Most likely your machine already has `make` installed. To install `cmake` and `make`:
```bash
brew install cmake make
```
For more information on how to install, check [cmake website](https://cmake.org/download/).

## Platform toolchain

### Atmel AVR toolchain
This toolchain is used to build any AVR project and must be installed:
```
xcode-select --install
brew tap osx-cross/avr
brew install avr-gcc
brew install avrdude
```
**Note:** You will need to have xcode installed on your machine.

### Native toolchain
In order to develop C/C++ programs, you need to develop toolchain to compile and build those projects. Most popular of them is `clang` and most likely your machine already comes with it. In order to install `clang`, you can do:
```
xcode-select --install
```
**Note:** You will need to have xcode installed on your machine.

