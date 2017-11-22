/* 
 * File:   tmr2.h
 * Author: liruya
 *
 */

#ifndef TMR2_H
#define	TMR2_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "chip_16f1508.h"

#define T2CON_OUTPS_SHIFT   3
#define T2CON_OUTPS_16      (15<<T2CON_OUTPS_SHIFT)
#define T2CON_OUTPS_15      (14<<T2CON_OUTPS_SHIFT)
#define T2CON_OUTPS_14      (13<<T2CON_OUTPS_SHIFT)
#define T2CON_OUTPS_13      (12<<T2CON_OUTPS_SHIFT)
#define T2CON_OUTPS_12      (11<<T2CON_OUTPS_SHIFT)
#define T2CON_OUTPS_11      (10<<T2CON_OUTPS_SHIFT)
#define T2CON_OUTPS_10      (9<<T2CON_OUTPS_SHIFT)
#define T2CON_OUTPS_9       (8<<T2CON_OUTPS_SHIFT)
#define T2CON_OUTPS_8       (7<<T2CON_OUTPS_SHIFT)
#define T2CON_OUTPS_7       (6<<T2CON_OUTPS_SHIFT)
#define T2CON_OUTPS_6       (5<<T2CON_OUTPS_SHIFT)
#define T2CON_OUTPS_5       (4<<T2CON_OUTPS_SHIFT)
#define T2CON_OUTPS_4       (3<<T2CON_OUTPS_SHIFT)
#define T2CON_OUTPS_3       (2<<T2CON_OUTPS_SHIFT)
#define T2CON_OUTPS_2       (1<<T2CON_OUTPS_SHIFT)
#define T2CON_OUTPS_1       (0<<T2CON_OUTPS_SHIFT)
#define T2CON_TMR2ON_SHIFT  2
#define T2CON_TMR2ON        (1<<T2CON_TMR2ON_SHIFT)
#define T2CON_CKPS_SHIFT    0
#define T2CON_CKPS_64       (3<<T2CON_CKPS_SHIFT)
#define T2CON_CKPS_16       (2<<T2CON_CKPS_SHIFT)
#define T2CON_CKPS_4        (1<<T2CON_CKPS_SHIFT)
#define T2CON_CKPS_1        (0<<T2CON_CKPS_SHIFT)

    typedef void ( *TMR2_InterruptHandler_t ) ();

    extern void TMR2_Initialize_Default();
    extern void TMR2_StartTimer();
    extern void TMR2_StopTimer();
    extern void TMR2_ISR();
    extern void TMR2_SetInterruptHandler(TMR2_InterruptHandler_t handler);
    extern void TMR2_DisableISR();
    extern void TMR2_EnableISR();

#ifdef	__cplusplus
}
#endif

#endif	/* TMR2_H */

