/* Can driver
Author: Mikhail Chernoskutov
*/
#define F_CPU 10000000
#include <avr/io.h>
#include "portwork.cpp"
#include "canbus.cpp"
#include <util/delay.h>

int main(void){
    setBit(DDRB, 0);
    while(true){
        switchBit(PORTB, 0);
        _delay_ms(1000);
    }
}

