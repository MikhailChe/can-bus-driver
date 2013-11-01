#include <avr/io.h>
#include "portwork.c"
#include <stdbool.h>



/**CANGCON -- CAN General Control Register **/
// 0 - no request
// 1 - abort request: reset of CANEN1 and CANEN2 reqisters is made.
//  and all communications are disabled
void setAbortRequest(bool isTrue){
    if(isTrue){
        set_bit(CANGCON, ABRQ);
    }else{
        clear_bit(CANGCON, ABRQ);
    }
}

// 0 - no request
// 1 - overload frame request: send an overload frame after the next recieved frame
void setOverloadFrameRequest(bool isTrue){
    if(isTrue){
        set_bit(CANGCON, OVRQ);
    }else{
        clear_bit(CANGCON, OVRQ);
    }
}

// 0 - no request
// 1 - TTC (Time Trigger Communication) mode
void setTimeTriggerComm(bool isTrue){
    if(isTrue){
        set_bit(CANGCON, TTC);
    }else{
        clear_bit(CANGCON, TTC);
    }
}

// 0 - TTC Timer is caught on SOF
// 1 - TTC Timer is caght on the last bit of the EOF
void setSyncTimeTriggerComm(bool isTrue){
    if(isTrue){
        set_bit(CANGCON, SYNTTC);
    }else{
        clear_bit(CANGCON, SYNTTC);
    }
}

void setListening(bool isTrue){
    if(isTrue){
        set_bit(CANGCON, LISTEN);
    }else{
        clear_bit(CANGCON, LISTEN);
    }
}

// Enable CAN channel
void setEnabled(bool isTrue){
    if(isTrue){
        set_bit(CANGCON, ENASTB);
    }else{
        clear_bit(CANGCON, ENASTB);
    }
}

void SetSoftwareResetRequest(bool isTrue){
    if(isTrue){
        set_bit(CANGCON, SWRES);
    }else{
        clear_bit(CANGCON, SWRES);
    }
}



/** CANGSTA - CAN General Status Register **/

// 0 - no overload frame
// 1 - overload frame: set by hardware as long as the produced overload frame is sent
bool isOverloadFrame(){
    return get_bit(CANGSTA, OVFG);
}

// 0 - transmitter not busy
// 1 - transmitter is bysy: set by hardware as long as a frame or an ACK field is sent.
//  Alsk set when an inter frame space is sent
bool isTransmitterBusy(){
    return get_bit(CANGSTA, TXBSY);
}

// 0 - reciever not busy
// 1 - reciever is busy: set by hardware as long as frame is revieved or monitored
bool isRecieverBusy(){
    return get_bit(CANGSTA, RXBSY);
}

// 0 - CAN is disabled
// 1 - CAN controller is enabled
bool isEnabled(){
    return get_bit(CANGSTA, ENFG);
}

// BusOffMode gives the information of the state of the CAN channel.
// Only entering in "bus off" mode generated the BOFFIT interrupt
bool isBusOffMode(){
    return get_bit(CANGSTA, BOFF;
}

// ErrorPassiveMode gives information of the state of the CAN channel.
bool isErrorPassiveMode(){
    return get_bit(CANGSTA, ERRP);
}

/** CANGIT - CAN General Interrupt Register **/
//TODO: continue on high-level wrapper
