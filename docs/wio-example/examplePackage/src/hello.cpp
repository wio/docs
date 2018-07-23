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

