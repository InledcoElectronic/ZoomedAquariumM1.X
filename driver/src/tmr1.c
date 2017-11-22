#include "../inc/tmr1.h"

TMR1_InterruptHandler_t tmr1_isr_handler;
TMR1_InterruptHandler_t tmr1_gate_isr_handler;

/**
 * fosc/4 ckps:8
 */
void TMR1_Initialize_Default() {
    T1CON = T1CON_CKPS_8 | T1CON_ASYNC | T1CON_TMR1CS_FOSC_4;

    TMR1 = 0x00;
    PIR1bits.TMR1IF = 0;
    PIE1bits.TMR1IE = 0;
    PIR1bits.TMR1GIF = 0;
    PIE1bits.TMR1GIE = 0;
}

void TMR1_StartTimer() {
    T1CONbits.TMR1ON = 1;
}

void TMR1_StopTimer() {
    T1CONbits.TMR1ON = 0;
}

void TMR1_EnableISR() {
    PIE1bits.TMR1IE = 1;
}

void TMR1_DisableISR() {
    PIE1bits.TMR1IE = 0;
}

void TMR1_EnableGateISR() {
    PIE1bits.TMR1GIE = 1;
}

void TMR1_DisableGateISR() {
    PIE1bits.TMR1GIE = 0;
}

void TMR1_ISR() {
    PIR1bits.TMR1IF = 0;
    if (tmr1_isr_handler) {
        tmr1_isr_handler();
    }
}

void TMR1_GATE_ISR() {
    PIR1bits.TMR1GIF = 0;
    if (tmr1_gate_isr_handler) {
        tmr1_gate_isr_handler();
    }
}

void TMR1_SetInterruptHandler(TMR1_InterruptHandler_t handler) {
    tmr1_isr_handler = handler;
}

void TMR1_Gate_SetInterruptHandler(TMR1_InterruptHandler_t handler) {
    tmr1_gate_isr_handler = handler;
}
