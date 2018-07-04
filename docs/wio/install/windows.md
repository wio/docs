# Windows

Wio is available for windows platform through `NPM` and `Scoop`.

## Scoop
Scoop is a windows package manager. It downloads binaries like how linux package managers do. You can use scoop if you have powershell 13 or above. To install Scoop, type the following in powershell:
```bash
iex (new-object net.webclient).downloadstring('https://get.scoop.sh')
```
If you get an error you might need to change the execution policy (i.e. enable Powershell):
```bash
set-executionpolicy -s cu unrestricted
```

Now that you have `scoop`, you can use it to install `wio`:
```bash
scoop bucket add wio https://github.com/dhillondeep/wio-bucket.git
scoop install wio
```

## NPM
 NPM is a node package manager and can be downloaded using:
```bash
# using scoop
scoop install nodejs
```
If you do not want to use *scoop*, you can download *NPM* from their [official website](https://nodejs.org/en/download/)

Now that you have `NPM` installed, you can use it to install `wio`:
```bash
npm install -g wio
```

Hurray! you have **wio** installed but wait there are few more things before you get started. You will have to install toolchain for the platform you are building. You will also have to install build tools used by **wio**

## Wio build Tools
Wio uses `cmake` and `make` to compile the project. To install `cmake` and `make`:
```bash
# using scoop
scoop install cmake make
```
If you do not like `scoop` or if you wany more information on how to install, check [cmake website](https://cmake.org/download/) and [make website](http://gnuwin32.sourceforge.net/packages/make.htm). **Note**: Make sure to add both cmake and make to Environment PATH. 

## Platform toolchain

### Atmel AVR toolchain
This toolchain is used to build any AVR project and must be installed:

* Download [Core Arduino](https://www.arduino.cc/en/Main/Software) and install it. This will contains all the compilers and tools needed for building and uploading the binaries
* Go to Arduino install directory, ex: `C:\Program Files (x86)\Arduino` and from there go to `hardware\tools\avr\bin`. Grab the whole path and add that to your environment PATH
