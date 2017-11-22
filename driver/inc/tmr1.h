/* 
 * File:   tmr1.h
 * Author: liruya
 *
 */

#ifndef TMR1_H
#define	TMR1_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "chip_16f1508.h"

#define isTMR1Overflow()        (PIR1bits.TMR1IF)
#define TMR1_ResetOverflow()    (PIR1bits.TMR1IF = 0)

    //T1CON
#define T1CON_TMR1CS_SHIFT          6
#define T1CON_TMR1CS_LFINTOSC       (3<<T1CON_TMR1CS_SHIFT)
#define T1CON_TMR1CS_T1CKI_SOSC     (2<<T1CON_TMR1CS_SHIFT)
#define T1CON_TMR1CS_FOSC           (1<<T1CON_TMR1CS_SHIFT)
#define T1CON_TMR1CS_FOSC_4         (0<<T1CON_TMR1CS_SHIFT)
#define T1CON_CKPS_SHIFT            4
#define T1CON_CKPS_1                (0<<T1CON_CKPS_SHIFT)
#define T1CON_CKPS_2                (1<<T1CON_CKPS_SHIFT)
#define T1CON_CKPS_4                (2<<T1CON_CKPS_SHIFT)
#define T1CON_CKPS_8                (3<<T1CON_CKPS_SHIFT)
#define T1CON_SOSCEN_SHIFT           3
#define T1CON_SOSC_ENABLE           (1<<T1CON_SOSCEN_SHIFT)
#define T1CON_SOSC_DISABLE          (0<<T1CON_SOSCEN_SHIFT)
#define T1CON_SYNC_SHIFT            2
#define T1CON_ASYNC                 (1<<T1CON_SYNC_SHIFT)
#define T1CON_SYNC                  (0<<T1CON_SYNC_SHIFT)
#define T1CON_TMR1ON_SHIFT          0
#define T1CON_TMR1ON                (1<<T1CON_TMR1ON_SHIFT)

    //T1GCON
#define T1GCON_TMR1GE_SHIFT         7
#define T1GCON_TMR1GE               (1<<T1GCON_TMR1GE_SHIFT)
#define T1GCON_GPOL_SHIFT           6
#define T1GCON_T1GPOL               (1<<T1GCON_GPOL_SHIFT)
#define T1GCON_GTM_SHIFT            5
#define T1GCON_T1GTM                (1<<T1GCON_GTM_SHIFT)
#define T1GCON_GSPM_SHIFT           4
#define T1GCON_T1GSPM               (1<<T1GCON_GSPM_SHIFT)
#define T1GCON_GGO_SHIFT            3
#define T1GCON_T1GGOnDONE           (1<<T1GCON_GGO_SHIFT)
#define T1GCON_GVAL_SHIFT           2
#define T1GCON_T1GVAL               (1<<T1GCON_GVAL_SHIFT)
#define T1GCON_GSS_SHIFT            0
#define T1GCON_T1GSS_CMP2OUT        (3<<T1GCON_GSS_SHIFT)     
#define T1GCON_T1GSS_CMP1OUT        (2<<T1GCON_GSS_SHIFT) 
#define T1GCON_T1GSS_TMR0OVF        (1<<T1GCON_GSS_SHIFT) 
#define T1GCON_T1GSS_T1G            (0<<T1GCON_GSS_SHIFT)  


    typedef void ( *TMR1_InterruptHandler_t ) ();

    extern void TMR1_Initialize_Default();
    extern void TMR1_StartTimer();
    extern void TMR1_StopTimer();
    extern void TMR1_EnableISR();
    extern void TMR1_DisableISR();
    extern void TMR1_EnableGateISR();
    extern void TMR1_DisableGateISR();
    extern void TMR1_ISR();
    extern void TMR1_GATE_ISR();
    extern void TMR1_SetInterruptHandler(TMR1_InterruptHandler_t handler);
    extern void TMR1_Gate_SetInterruptHandler(TMR1_InterruptHandler_t handler);


#ifdef	__cplusplus
}
#endif

#endif	/* TMR1_H */

