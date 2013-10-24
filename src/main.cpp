/* Can driver
Author: Mikhail Chernoskutov
*/
#define F_CPU 1000000
#include "timer.cpp"
#include <util/delay.h>

int main(void){
    enable0BPWM();
    while(1){
        set0Bduty(get0Bduty()+1);
        _delay_ms(10);
    }
}

