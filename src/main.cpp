/* Can driver
Author: Mikhail Chernoskutov
*/
#include <avr/io.h>
#include "portwork.cpp"
#include "canbus.cpp"

int main(void){
    setBit(DDRB, 0);
    while(true){
        switchBit(PORTB, 0);
    }
}

