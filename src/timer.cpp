#include "portwork.cpp"
#include <avr/io.h>
void set0Bduty(uint8_t duty){
    OCR0B = duty;
}
uint8_t get0Bduty(){
    return OCR0B;
}
void enable0BPWM(){
    //Setting Direction of PORTD5 to output
    set_bit(DDRD, 5);
    set_bit(PORTD, 5);
    
    // Connecting timer output to PORTD5 in Clear on Compare match mode
    set_bit(DDRB, COM0B1);
    clear_bit(TCCR0A, COM0B0);
    
    // Enable fast-PWM TOP = 0xFF
    clear_bit(TCCR0B, WGM02);
    set_bit(TCCR0A, WGM01);
    set_bit(TCCR0A, WGM00);
    
    //Clearing FOC0B bit int TCCR0B as said in docs
    clear_bit(TCCR0B, FOC0B);
    
    //Selecting an input clock without prescaler
    clear_bit(TCCR0B, CS02);
    clear_bit(TCCR0B, CS01);
    set_bit(TCCR0B, CS00);
    
    set0Bduty(255);
}
