#include <avr/io.h>
#include "portwork.c"
#include <stdbool.h>
#include "canbus.h"

/* ATMEGA16M1 high level wrapper functions
 * You can find updated version at https://github.com/MikhailChe/can-bus-driver
 * 
 * Source code can be distributed under MIT license, which means that
 * you can use it wherever and however you want until you remain copyrights
 *
 * Copyright 2013, Mikhail Chernoskutov
 */

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
    return get_bit(CANGSTA, BOFF);
}

// ErrorPassiveMode gives information of the state of the CAN channel.
bool isErrorPassiveMode(){
    return get_bit(CANGSTA, ERRP);
}

/** CANGIT - CAN General Interrupt Register **/

// 0 - no interrupt
// 1 - CAN interrupt: image of all the CAN controller interrputs except of OVRTIM interrupt.
//  This bit can be used for polling method
bool isCANGeneralInterruptFlag(){
    return get_bit(CANGIT, CANIT);
}

// Writing a logical one value resets this interrupt flag. BOFFIT flag is only set
// when the CAN enters in bus off mode (coming from error passive mode)
// 0 - no interrupt
// 1 - bus off interrupt when the CAN enters in bus off mode
void setBusOffInterrupt(bool isTrue){
    if(isTrue){
        set_bit(CANGIT, BOFFIT);
    }else{
        clear_bit(CANGIT, BOFFIT);
    }
}

// Writing a logical one resets this interrupt flag.
// Entering in CAN timer overrun interrupt handler also reset the interrupt flag.
// 0 - no interrupt
// 1 - CAN timer overrun interrupt: set when the CAN timer switches from 0xFFFF to 0
void setOverrunCANTimer(bool isTrue){
    if(isTrue){
        set_bit(CANGIT, OVRTIM);
    }else{
        clear_bit(CANGIT, OVRTIM);
    }
}

//Writing a logical one resets this interrupt flag. BXOK flag can be cleared only if all CONMOB 
//fields of the MOb’s of the buffer have been re-written before.
// 0 - no interrupt
// 1 - burst receive interrupt: set when the frame buffer receive is completed
void setFrameBufferRecieveInterrupt(bool isTrue){
    if(isTrue){
        set_bit(CANGIT, BXOK);
    }else{
        clear_bit(CANGIT, BXOK);
    }
}

//Writing a logical one resets this interrupt flag.
// 0 - no interrupt
// 1 - stuff error interrupt: detection of more than 5 consecutive bits with the same polarity
void setStuffErrorGeneral(bool isTrue){
    if(isTrue){
        set_bit(CANGIT, SERG);
    }else{
        clear_bit(CANGIT, SERG);
    }
}

//Writing a logical one resets this interrupt flag.
// 0 - no interrupt
// 1 - CRC error interrupt: the CRC check on destuffed message does not fit with the CRC field
void setCRCErrorGeneral(bool isTrue){
    if(isTrue){
        set_bit(CANGIT, CERG);
    }else{
        clear_bit(CANGIT, CERG);
    }
}

//Writing a logical one resets this interrupt flag.
// 0 - no interrupt
// 1 - form error interrupt: one or more violations of the fixed form in the CRC delimiter,
// acknowledgment delimiter or EOF
void setFormErrorGeneral(bool isTrue){
    if(isTrue){
        set_bit(CANGIT, FERG);
    }else{
        clear_bit(CANGIT, FERG);
    }
}

//Writing a logical one resets this interrupt flag.
// 0 - no interrupt
// 1 - acknowledgment error interrupt: no detection of the dominant bit in acknowledge slot
void setAcknowledgmentErrorGeneral(bool isTrue){
    if(isTrue){
        set_bit(CANGIT, AERG);
    }else{
        clear_bit(CANGIT, AERG);
    }
}

/** CANGIE  - CAN General Interrupt Enable Register **/
// Enables all CAN Interrupts except for CAN Timer Overrun Interrupt
void setEnableAllCANInterrupts(bool isTrue){
    if(isTrue){
        set_bit(CANGIE, ENIT);
    }else{
        clear_bit(CANGIE, ENIT);
    }
}

// Enables Bus-Off Interrupt
void setEnableBusOffInterrupt(bool isTrue){
    if(isTrue){
        set_bit(CANGIE, ENBOFF);
    }else{
        clear_bit(CANGIE, ENBOFF);
    }
}

// Enable Recieve Interrupt
void setEnableRecieveInterrupt(bool isTrue){
    if(isTrue){
        set_bit(CANGIE, ENRX);
    }else{
        clear_bit(CANGIE, ENRX);
    }
}

// Enable Transmit Interrupt
void setEnableTransmitInterrupt(bool isTrue){
    if(isTrue){
        set_bit(CANGIE, ENTX);
    }else{
        clear_bit(CANGIE, ENTX);
    }
}

// Enable MOb Errors Interrupt
void setEnableMObErrorsInterrupt(bool isTrue){
    if(isTrue){
        set_bit(CANGIE, ENERR);
    }else{
        clear_bit(CANGIE, ENERR);
    }
}

// Enable Frame Buffer Interrupt
void setEnableFrameBufferInterrupt(bool isTrue){
    if(isTrue){
        set_bit(CANGIE, ENBX);
    }else{
        clear_bit(CANGIE, ENBX);
    }
}

// Enable General Errors Interrupt
void setEnableGeneralErrorsInterrupt(bool isTrue){
    if(isTrue){
        set_bit(CANGIE, ENERG);
    }else{
        clear_bit(CANGIE, ENERG);
    }
}

// Enable CAN Timer Overrun Interrupt
void setEnableCANTimerOverrunInterrupt(bool isTrue){
    if(isTrue){
        set_bit(CANGIE, ENOVRT);
    }else{
        clear_bit(CANGIE, ENOVRT);
    }
}


#define N_OF_MObs 5
/** CANEN2 and CANEN1 - CAN Enable MOb Registers **/

// ATmega16M1 /32M1 /64M1 have only six MOb's
// 0 - message object disabled: MOb available for a new transmission or reception
// 1 - message object enabled: MOb in use
bool isMobEnalbed(uint8_t index){
    if(index >= N_OF_MObs){
        return false;
    }else{
        return get_bit(CANEN2, index);
    }
}

/** CANIE2 and CANIE1 - CAN Enable Interrupt MOb Registers **/
void setEnableMObInterrupt(uint8_t index, bool value){
    if(index >= N_OF_MObs){
        return;
    }
    if(value){
        set_bit(CANIE2, index);
    }else{
        clear_bit(CANIE2, index);
    }
}

/** CANSIT2 and CANSIT1 - CAN Status Interrupt MOb Registers **/
void setEnableMObStatusInterrupt(uint8_t index, bool value){
    if(index >= N_OF_MObs){
        return;
    }
    if(value){
        set_bit(CANSIT2, index);
    }else{
        clear_bit(CANSIT2, index);
    }
}

/** CANBT1 - CAN bit Timing Register 1 **/

//6-bit prescaler
void setBaudRatePrescaler(uint8_t prescaler){
    prescaler = prescaler & 0b111111;
    CANBT1 = (prescaler << BRP0);
    if(prescaler == 0){
        setSamplePoint(false);
    }
}

uint8_t getBaudRatePrescaler(){
    return (CANBT1 >> BRP0)&0b111111;
}

/** CANBT2 - CAN bit Timing Register 2 **/
void setResyncJumpWidth(uint8_t val){
    set_bits(CANBT2, 0b11, SJW0, val);
}

void setPropagationTimeSegment(uint8_t val){
    set_bits(CANBT2, 0b111, PRS0, val);
}


/** CANBT3 - CAN bit Timing Register 3 **/

//Phase Segment 2 shall always be >=1 and <= Phase Segment 1
// T(phs2) = T(scl) * (PHS2 + 1);
// This phase is used to compensate for phase edge errors.
// This segment may be shortened by the re-synchronization jump width
void setPhaseSegment2(uint8_t val){
    set_bits(CANBT3, 0b111, PHS20, val);
}

// This phase is used to compensate for phase edge errors.
// This segment may be lengthened by the re-synchronization jump width
// T(phs1) = T(scl) * (PHS1 +1);
void setPhaseSegment1(uint8_t val){
    set_bits(CANBT3, 0b111, PHS10, val);
}

void setSamplePoint(bool val){
    if(val){
        set_bit(CANBT3, SMP);
        if(getBaudRatePrescaler() == 0){
            setBaudRatePrescaler(1);
        }
    }else{
        clear_bit(CANBT3, SMP);
    }
}

/** CANTCON - CAN Timer Control Register **/

// Prescaler for the CAN timer upper counter range 0 to 255.
// It provides the clock to the CAN timer if the CAN controller is enabled
// Tclk(CANTIM) = Tclk(IO) * 8 * (CANTCON +1)
void setCanTimerPrescaler(uint8_t val){
    CANTCON = val;
}
    
uint8_t getCanTimerPrescaler(){
    return CANTCON;
}


//TODO: check that shift to left works properly
/** CANTIML and CANTIMH - CAN timer Registers (read-only) **/
uint16_t getCanTimer(){
    return ((CANTIMH << 8) | CANTIML);
}

/** CANTTCL and CANTTCH - CAN TTC Timer Registers (read-only) **/
uint16_t getCanTTCTimer(){
    return ((CANTTCH << 8) | CANTTCL);
}

/** CANTEC - CAN Transmit Error Counter Register **/
uint8_t getTransmitErrorCount(){
    return CANTEC;
}

/** CANREC - CAN Receive Error Counter Register **/
uint8_t getReceiveErrorCount(){
    return CANREC;
}
/** CANHPMOB - CAN Highest Priority MOb Register **/
uint8_t getHighestPriorMObNumber(){
    return (CANHPMOB >> HPMOB0)&0b1111;
}

/** CANPAGE - CAN Page MOb Register **/

//Selection of the Mob number. Available are from 0 to 5
void setMobNumber(uint8_t val){
    if(val>=0 && val <=5){
        set_bits(CANPAGE, 0b1111, MOBNB0, val);
    }
}

uint8_t getMobNumber(){
    return ((CANPAGE >> MOBNB0) & 0b1111);
}

// INVERTED!!
// Auto Increment of the FIFO CAN Data Buffer Index (Active low)
// 0 - auto increment of the index (which is default)
// 1 - NO auto increment of the index
void setAutoIncrement(bool val){
    if(val){
        set_bit(CANPAGE, AINC);
    }else{
        clear_bit(CANPAGE, AINC);
    }
}

bool getAutoIncrement(){
    return get_bit(CANPAGE, AINC);
}

// INDX - FIFO CAN Data Buffer index
// Byte location of the CAN data byte into the FIFO for the defined MOb
void setIndex(uint8_t val){
    if(val>=0 && val <= 0b111){
        set_bits(CANPAGE, 0b111, INDX0, val);
    }
}
uint8_t getIndex(){
    return ((CANPAGE>>INDX0) && 0b111);
}



/*|===============|***/
/*| MOb registers |**/
/*|===============|*/
/* The MOb registers has no initial (defaul) value after RESET. */

/* CANSTMOB - CAN MOb Status Register */

/* DLCW: Data Length Code Warning*/
/* The incoming message does not have DLC expected. */
/* Whatever the frame type, the DLC field of CANCD-MOB register is updated by the recieved DLC */
bool getDataLengthCodeWarning(){
    return (CANSTMOB >> DLCW)&1;
}

/* TXOK: Transmit OK */
/* This flag can generate an interrupt. It must be cleared */
/* The communication enabled by transmission is completed. TxOK rises at the end of EOF field. When the controller
is ready to send a frame, if two or more message objects are enabled as producers, the lower MOb index (0 to 14)
is supplied first. */
bool isTXOK(){
    return (CANSTMOB >> TXOK)&1;
}

void clearTXOK(){
    clear_bit(CANSTMOB, TXOK);
}

/* RXOK: Receive OK */
/* This flag can generate an interrupt. It must be cleared */
/* The communication enabled by reception is completed. RxOK rises at the end of the 6th bit of EOF field. In case of
two or more message object reception hits, the lower MOb index (0 to 14) is updated first. */

bool isRXOK(){
    return (CANSTMOB >> RXOK)&1;
}

void clearRXOK(){
    clear_bit(CANSTMOB, RXOK);
}

/* BERR: Bit Error (Only in Transmission) */
/* This flag can generate an interrupt. It must be cleared */
/* The bit value monitored is different from the bit value sent */
/* Exceptions: the monitored recessive bit sent as a dominant bit during the arbitration field and the acknowledge slot
detecting a dominant bit during the sending of an error frame. */
bool isBitError(){
    return (CANSTMOB >> BERR)&1;
}

void clearBitError(){
    clear_bit(CANSTMOB, BERR);
}


/* SERR: Stuff Error */
/* This flag can generate an interrupt. It must be cleared */
/* Detection of more than five consecutive bits with the same polarity */

bool isStuffError(){
    return (CANSTMOB >> SERR)&1;
}

void clearStuffError(){
    clear_bit(CANSTMOB, SERR);
}


/* CERR: CRC Error */
/* This flag can generate an interrupt. It must be cleared */
/* The receiver performs a CRC check on every de-stuffed received message from the start of frame up to the data
field. If this checking does not match with the de-stuffed CRC field, a CRC error is set. */
bool isCRCError(){
    return (CANSTMOB >> CERR)&1;
}

void clearCRCError(){
    clear_bit(CANSTMOB, CERR);
}


/* FERR: Form Error */
/* This flag can generate an interrupt. It must be cleared */
/* The form error results from one or more violations of the fixed form in the following bit fields: CRC delimiter, Acknowledgment delimiter, EOF */
bool isFormError(){
    return (CANSTMOB >> FERR)&1;
}

void clearFormError(){
    clear_bit(CANSTMOB, FERR);
}


/* AERR: Acknowledgment Error */
/* This flag can generate an interrupt. It must be cleared */
/* No detection of the dominant bit in the acknowledge slot. */
bool isAckError(){
    return (CANSTMOB >> AERR);
}

void clearAckError(){
    clear_bit(CANSTMOB, AERR);
}

//TODO: continue on high-level wrapper
