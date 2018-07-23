# Linux

Wio is available for linux platform through `npm`. NPM is a node package manager and can be downloaded using:
```bash
# ubuntu
sudo apt-get install npm

# arch
sudo pacman -S nodejs
```

If you do not use *ubuntu* and *arch*, or you have any other issues, check [npm install website](https://www.npmjs.com/get-npm). 

Now that you have `NPM` installed, you can use it to install `wio`:
```bash
npm install -g wio
```
Sometimes there are issues with permissions, and to resolve those issues, you can do:
```bash
sudo npm install -g wio --unsafe-perm
```

Hurray! you have **wio** installed but wait there are few more things before you can get started. You will have to install toolchain for the platform you are building. You will also have to install build tools used by **wio**

## Wio build Tools
Wio uses `cmake` and `make` to compile the project. Most likely your machine already has `make` installed. To install `cmake` and `make`:
```bash
# ubuntu
sudo apt-get install cmake make

# arch
sudo pacman -S cmake make
```
For more information on how to install, check [cmake website](https://cmake.org/download/). 

## Platform toolchain

### Atmel AVR toolchain
This toolchain is used to build any AVR project and must be installed:
```
# ubuntu
sudo apt-get install gcc-avr avr-libc avrdude

# arch
sudo pacman -S avr-gcc avr-libc avrdude
```

### Native toolchain
In order to develop C/C++ programs, you need to download toolchain to compile and build those projects. Most popular of them is is `gcc` and most likely your machine already comes with it. In order to install `gcc`, you can do:
```
# ubuntu
sudp apt-get install gcc

# arc
sudo pacman -S gcc
```
**Note:** You can you any compile you like `gcc` is just one example.

