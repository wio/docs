# What is Wio?

Wio is an open source Iot ecosystem. The goal of this project is to make iot development
easier and simpler. Wio is developed and maintained by <a href="http://waterloop.ca/" target="_blank">Waterloop</a> and it is being actively used for building hyperloop pod production code.

## Problem
* Embedded world is complicated with seperate toolchains, proprietary vendor IDEs, and OS supported softwares. This repulses people from embedded developemnt.
* Multiple hardware platforms (MCUs, boards) require different toolchains, IDEs, etc, and, respectively, spending time on learning new development environments.
* Finding libraries and code samples is a hasle all the ways
* Sharing code and then getting it work on your personal machine is never easys

## Overview
Wio is independent from any platform and infact it has no requirement. It is a compiled binary and can run on pretty much on any machine. This allows for great portability since Wio can be used on any machine and projects can be shared easily. Wio is a command line tool and because of that it can run on any server and/or virtual machine.

Wio is in beta right now and hence only supports AVR platform. When wio 1.0.0 is released, it will ship with support for native development (desktop c/c++) as well. As this project will grow, support for ARM chips and other boards will be added.

## How Does it Work
A very basic work cycle of the project development using Wio is as follows:
* User create a project of their type (app or pkg) and specifies a board.
* In `wio.yml` file, user can specify framework for the board.
* Based on the board and the framework, Wio links the required toolchain.
* Users develop code and Wio makes sure it is compiled, uploaded and runs on all the boards specified. 

**Note:** Wio is still in beta and if there are any issues please open an issue on wio repository.