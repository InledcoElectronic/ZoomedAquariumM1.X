#include "../inc/tmr0.h"

TMR0_InterruptHandler_t tmr0_isr_handler;

/**
 * wpu enabled, intedge fall, clk fosc/4,rise, psa enable 256
 */
void TMR0_Initialize_Default() {
    OPTION_REG = OPTION_REG_WPU_ENABLE | OPTION_REG_INT_FALL | OPTION_REG_TMR0CS_FOSC_4 | OPTION_REG_TMR0SE_RISE
            | OPTION_REG_PSA_ENABLE | OPTION_REG_PS_256;
    TMR0 = 0;
    INTCONbits.TMR0IF = 0;
    INTCONbits.TMR0IE = 0;
}

void TMR0_EnableISR() {
    INTCONbits.TMR0IE = 1;
}

void TMR0_DisableISR() {
    INTCONbits.TMR0IE = 0;
}

void TMR0_ISR() {
    INTCONbits.TMR0IF = 0;

    if (tmr0_isr_handler) {
        tmr0_isr_handler();
    }
}

void TMR0_SetInterruptHandler(TMR0_InterruptHandler_t handler) {
    tmr0_isr_handler = handler;
}

