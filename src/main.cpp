/* Can driver
Author: Mikhail Chernoskutov
*/
#define F_CPU 1000000
#include "timer.cpp"
#include "portwork.cpp"
#include <util/delay.h>

int main(void){
    enable0BPWM();
    DDRB = 0;
    PORTB = 0b11111111;
    while(1){
        set0Bduty(get0Bduty()-1);
        if(get0Bduty()<1){
            set0Bduty(255);
        }
        _delay_ms(10);
    }
}

