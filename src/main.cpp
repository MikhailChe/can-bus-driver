/* Can driver
Author: Mikhail Chernoskutov
*/
#define F_CPU 1000000
#include "timer.cpp"
#include <util/delay.h>

int main(void){
    enable0BPWM();
    DDRB = 1;
    PORTB = 0b10101010;
    while(1){
        set0Bduty(get0Bduty()-1);
        if(get0Bduty()<64){
            set0Bduty(255);
        }
        _delay_ms(10);
    }
}

