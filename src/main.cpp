/* Can driver
Author: Mikhail Chernoskutov
*/
#define F_CPU 1000000
#include "timer.cpp"
#include "portwork.cpp"
#include <util/delay.h>
#include <math.h>
int main(void){
    enable0BPWM();
    DDRB = 0;
    PORTB = 0b11111111;
    double angle = 0;
    while(1){
        /*set0Bduty(get0Bduty()-1);
        if(get0Bduty()<1){
            set0Bduty(255);
        }*/
        set0Bduty((sin(angle)+1)*127);
        angle += 0.1;
        if(angle > M_PI*2){
            angle = 0;
        }
        _delay_ms(1);
    }
}

