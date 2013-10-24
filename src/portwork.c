#define setBit(PORT, BIT) ((PORT |= 1 <<BIT))
#define clearBit(PORT, BIT) ((PORT &= ~(1 << BIT)))
#define switchBit(PORT, BIT) ((PORT ^= 1 << BIT))
/*void setBit(volatile uint8_t &portname, uint8_t bitshift){
    portname |= 1 << bitshift;
}

void clearBit(volatile uint8_t &portname, uint8_t bitshift){
    portname &= ~(1 << bitshift);
}

void switchBit(volatile uint8_t &portname, uint8_t bitshift){
    portname ^= 1 << bitshift;
}*/
