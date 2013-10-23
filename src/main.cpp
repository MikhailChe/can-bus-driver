/* Can driver
Author: Mikhail Chernoskutov
*/
#include "main.h"
#include <avr/io.h>
#include "portwork.cpp"
#include "canbus.cpp"

int main(void){
    initCanBus();
    setBit(PORTB, 1);
    return 0;
}

