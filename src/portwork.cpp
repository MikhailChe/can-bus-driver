#ifndef _PORTWORK_ENABLED_
#define _PORTWORK_ENABLED_

#define set_bit(port,mask) ((port) |= (1 << mask))
#define clear_bit(port,mask) ((port) &= ~(1 << mask))
#define switch_bit(port,mask) ((port) ^= (1 << mask))

#define get_bit(port,mask) ((port >> mask)&1)

#endif
