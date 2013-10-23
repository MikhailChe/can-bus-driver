void setBit(volatile uint8_t &portname, uint8_t bitshift){
    portname |= 1 << bitshift;
}

void clearBit(volatile uint8_t &portname, uint8_t bitshift){
    portname &= ~(1 << bitshift);
}

void switchBit(volatile uint8_t &portname, uint8_t bitshift){
    portname ^= 1 << bitshift;
}
