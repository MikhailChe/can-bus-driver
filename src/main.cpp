/* Can driver
Author: Mikhail Chernoskutov
*/
#define F_CPU 1000000
#include <avr/io.h>
#include "portwork.cpp"
#include "canbus.cpp"
#include <util/delay.h>

int main(void){
    setBit(DDRB, 0);
    double sleep = 0;
    int direction = 1;
    while(true){
        switchBit(PORTB, 0);
        _delay_ms(1000);
        sleep = sleep + direction;
        if(direction == 1){
            if(sleep > 1000){
                direction = -1;
            }
        }else{
            if(sleep <= 1){
                direction = 1;
            }
        }
    }
}

