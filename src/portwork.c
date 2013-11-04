#ifndef _PORTWORK_ENABLED_
#define _PORTWORK_ENABLED_

#define set_bit(port,mask) ((port) |= (uint8_t)(1 << mask))
#define clear_bit(port,mask) ((port) &= (uint8_t)~(1 << mask))
#define switch_bit(port,mask) ((port) ^= (uint8_t)(1 << mask))

#define set_bits(port,mask,shift,value) (port = (( port&( ~(mask<<shift) ) ) | (value & mask) << shift))

#define get_bit(port,mask) ((port >> mask)&1)

#endif
