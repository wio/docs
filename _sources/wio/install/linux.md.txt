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
Sometimes there are issues with permission, and to resolve those issues, you can do,
```bash
sudo npm install -g wio --unsafe-perm
```

Hurray! you have **wio** installed but wait there are few more things before you get started. You will have to install toolchain for the platform you are building. You will also have to install build tools used by **wio**

## Wio build Tools
Wio uses `cmake` and `make` to compile the project. To install `cmake` and `make`:
```bash
# ubuntu
sudo apt-get install cmake make

# arch
sudo pacman -S cmake make
```
For more information on how to install, check [cmake website](https://cmake.org/download/). `make` should be installed already!

## Platform toolchain

### Atmel AVR toolchain
This toolchain is used to build any AVR project and must be installed:

```
# ubuntu
sudo apt-get install gcc-avr avr-libc avrdude

# arch
sudo pacman -S avr-gcc avr-libc avrdude
```