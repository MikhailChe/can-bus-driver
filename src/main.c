/* Can driver
Author: Mikhail Chernoskutov
*/
#define F_CPU 1000000
#include <avr/io.h>
#include "portwork.c"
#include <util/delay.h>

int main(void){
    setBit(DDRB, 0);
    while(1){
        switchBit(PORTB, 0);
        _delay_ms(500);
    }
}

