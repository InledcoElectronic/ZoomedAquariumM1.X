/* 
 * File:   eusart.h
 * Author: liruya
 *
 */

#ifndef EUSART_H
#define	EUSART_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "chip_16f1508.h"
    
    //TXSTA
#define TXSTA_CSRC_SHIFT    7
#define TXSTA_CSRC_BRG      (1<<TXSTA_CSRC_SHIFT)
#define TXSTA_CSRC_EXT      (0<<TXSTA_CSRC_SHIFT)
#define TXSTA_TX9_SHIFT     6
#define TXSTA_TX9           (1<<TXSTA_TX9_SHIFT)
#define TXSTA_TXEN_SHIFT    5
#define TXSTA_TXEN          (1<<TXSTA_TXEN_SHIFT)
#define TXSTA_SYNC_SHIFT    4
#define TXSTA_SYNC          (1<<TXSTA_SYNC_SHIFT)
#define TXSTA_SENDB_SHIFT   3
#define TXSTA_SENDB         (1<<TXSTA_SENDB_SHIFT)
#define TXSTA_BRGH_SHIFT    2
#define TXSTA_BRGH          (1<<TXSTA_BRGH_SHIFT)
#define TXSTA_TRMT_SHIFT    1
#define TXSTA_TRMT          (1<<TXSTA_TRMT_SHIFT)
#define TXSTA_TX9D_SHIFT    0
#define TXSTA_TX9D          (1<<TXSTA_TX9D_SHIFT)
    
    //RCSTA
#define RCSTA_SPEN_SHIFT    7
#define RCSTA_SPEN          (1<<RCSTA_SPEN_SHIFT)
#define RCSTA_RX9_SHIFT     6
#define RCSTA_RX9           (1<<RCSTA_RX9_SHIFT)
#define RCSTA_SREN_SHIFT    5
#define RCSTA_SREN          (1<<RCSTA_SREN_SHIFT)
#define RCSTA_CREN_SHIFT    4
#define RCSTA_CREN          (1<<RCSTA_CREN_SHIFT)
#define RCSTA_ADDEN_SHIFT   3
#define RCSTA_ADDEN         (1<<RCSTA_ADDEN_SHIFT)
#define RCSTA_FERR_SHIFT    2
#define RCSTA_FERR          (1<<RCSTA_FERR_SHIFT)
#define RCSTA_OERR_SHIFT    1
#define RCSTA_OERR          (1<<RCSTA_OERR_SHIFT)
#define RCSTA_RX9D_SHIFT    0
#define RCSTA_RX9D          (1<<RCSTA_RX9D_SHIFT)
    
    //BAUDCON
#define BAUDCON_ABDOVF_SHIFT    7
#define BAUDCON_ABDOVF          (1<<BAUDCON_ABDOVF_SHIFT)
#define BAUDCON_RCIDL_SHIFT     6
#define BAUDCON_RCIDL           (1<<BAUDCON_RCIDL_SHIFT)
#define BAUDCON_SCKP_SHIFT      4
#define BAUDCON_SCKP_IDLE_LOW   (1<<BAUDCON_SCKP_SHIFT)
#define BAUDCON_SCKP_IDLE_HIGH  (0<<BAUDCON_SCKP_SHIFT)
#define BAUDCON_BRG16_SHIFT     3
#define BAUDCON_BRG16           (1<<BAUDCON_BRG16_SHIFT)
#define BAUDCON_WUE_SHIFT       1
#define BAUDCON_WUE             (1<<BAUDCON_WUE_SHIFT)
#define BAUDCON_ABDEN_SHIFT     0
#define BAUDCON_ABDEN           (1<<BAUDCON_ABDEN_SHIFT)
    
#define BAUDRATE_16M_9600       416
#define BAUDRATE_16M_19200      207
#define BAUDRATE_16M_38400      103
#define BAUDRATE_16M_57600      68
#define BAUDRATE_16M_115200     34
    
    typedef void ( *EUSART_ReceiveInterruptHandler_t ) ( uint8_t rcv );
    
extern void EUSART_Initialize_Default();
extern uint8_t EUSART_Write( uint8_t byte );
extern void EUSART_Receive_ISR();
extern void EUSART_Transmit_ISR();

#ifdef	__cplusplus
}
#endif

#endif	/* EUSART_H */

