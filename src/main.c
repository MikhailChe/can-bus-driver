/* Can driver
Author: Mikhail Chernoskutov
*/
#define F_CPU 1000000
#include "timer.c"
#include "portwork.c"
#include "canbus.c"
#include <util/delay.h>
#include <stdbool.h>
int main(void){
   setAbortRequest(true);
   return 0;
}

