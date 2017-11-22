/* 
 * File:   tmr0.h
 * Author: liruya
 *
 */

#ifndef TMR0_H
#define	TMR0_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "chip_16f1508.h"

#define OPTION_REG_WPUEN_SHIFT      7
#define OPTION_REG_WPU_ENABLE       (0<<OPTION_REG_WPUEN_SHIFT)
#define OPTION_REG_WPU_DISABLE      (1<<OPTION_REG_WPUEN_SHIFT)
#define OPTION_REG_INTEDGE_SHIFT    6
#define OPTION_REG_INT_RISE         (1<<OPTION_REG_INTEDGE_SHIFT)
#define OPTION_REG_INT_FALL         (0<<OPTION_REG_INTEDGE_SHIFT)
#define OPTION_REG_TMR0CS_SHIFT     5
#define OPTION_REG_TMR0CS_T0CKI     (1<<OPTION_REG_TMR0CS_SHIFT)
#define OPTION_REG_TMR0CS_FOSC_4    (0<<OPTION_REG_TMR0CS_SHIFT)
#define OPTION_REG_TMR0SE_SHIFT     4
#define OPTION_REG_TMR0SE_FALL      (1<<OPTION_REG_TMR0SE_SHIFT)
#define OPTION_REG_TMR0SE_RISE      (0<<OPTION_REG_TMR0SE_SHIFT)
#define OPTION_REG_PSA_SHIFT        3
#define OPTION_REG_PSA_ENABLE       (0<<OPTION_REG_PSA_SHIFT)
#define OPTION_REG_PSA_DISABLE      (1<<OPTION_REG_PSA_SHIFT)
#define OPTION_REG_PS_SHIFT         0
#define OPTION_REG_PS_2             (0<<OPTION_REG_PS_SHIFT)
#define OPTION_REG_PS_4             (1<<OPTION_REG_PS_SHIFT)
#define OPTION_REG_PS_8             (2<<OPTION_REG_PS_SHIFT)
#define OPTION_REG_PS_16            (3<<OPTION_REG_PS_SHIFT)
#define OPTION_REG_PS_32            (4<<OPTION_REG_PS_SHIFT)
#define OPTION_REG_PS_64            (5<<OPTION_REG_PS_SHIFT)
#define OPTION_REG_PS_128           (6<<OPTION_REG_PS_SHIFT)
#define OPTION_REG_PS_256           (7<<OPTION_REG_PS_SHIFT)

    typedef void ( *TMR0_InterruptHandler_t) ();

    extern void TMR0_Initialize_Default();
    extern void TMR0_EnableISR();
    extern void TMR0_DisableISR();
    extern void TMR0_ISR();
    extern void TMR0_SetInterruptHandler(TMR0_InterruptHandler_t handler);

#ifdef	__cplusplus
}
#endif

#endif	/* TMR0_H */

