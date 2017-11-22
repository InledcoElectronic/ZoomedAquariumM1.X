#include "../inc/tmr2.h"

TMR2_InterruptHandler_t tmr2_isr_handler;

/**
 * ckps:1 outps:16 disabled pr2:249 isr enabled
 */
void TMR2_Initialize_Default() {
    T2CON = T2CON_CKPS_1 | T2CON_OUTPS_16;
    PR2 = 0xF9;
    TMR2 = 0x00;
    PIR1bits.TMR2IF = 0;
    PIE1bits.TMR2IE = 1;
}

void TMR2_StartTimer(void) {
    T2CONbits.TMR2ON = 1;
}

void TMR2_StopTimer(void) {
    T2CONbits.TMR2ON = 0;
}

void TMR2_ISR() {
    PIR1bits.TMR2IF = 0;
    if (tmr2_isr_handler) {
        tmr2_isr_handler();
    }
}

void TMR2_SetInterruptHandler(TMR2_InterruptHandler_t handler) {
    tmr2_isr_handler = handler;
}

void TMR2_DisableISR() {
    PIE1bits.TMR2IE = 0;
}

void TMR2_EnableISR() {
    PIE1bits.TMR2IE = 1;
}