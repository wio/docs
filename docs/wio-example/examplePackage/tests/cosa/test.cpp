#include <hello.hh>
#include <UART.hh>

void setup() {
    uart.begin(9600);
}

void loop() {
    printHello();
}

