#include "../../driver/inc/driver.h"
#include "../inc/audio.h"
#include "../inc/led.h"
#include "../inc/key.h"

// CONFIG1
#pragma config FOSC = INTOSC    // Oscillator Selection Bits (INTOSC oscillator: I/O function on CLKIN pin)
#pragma config WDTE = ON        // Watchdog Timer Enable (WDT enabled)
#pragma config PWRTE = ON       // Power-up Timer Enable (PWRT enabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select (MCLR/VPP pin function is MCLR)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable (Brown-out Reset disabled)
#pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)
#pragma config IESO = OFF       // Internal/External Switchover Mode (Internal/External Switchover Mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is disabled)

// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config STVREN = ON      // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will cause a Reset)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LPBOR = ON       // Low-Power Brown Out Reset (Low-Power BOR is enabled)
#pragma config LVP = ON         // Low-Voltage Programming Enable (Low-voltage programming enabled)

void SYSTEM_Initialize();
void Interrupt_Initialize();

void main() {
    SYSTEM_Initialize();
    Interrupt_Initialize();
    GlobleInterruptEnable();
    PeripheralInterruptEnable();
    Led_InitPara();
    Audio_Initialize();
    Led_Initialize();
    TMR2_StartTimer();

    while (1) {
        CLRWDT();

        if (gLedPara.mOn && (gLedPara.mMode == MODE_CLOUD || gLedPara.mMode == MODE_STORM)) {
            Audio_GetValue();
        }
        Led_SaveParaIfChanged();
    }
}

void interrupt ISR() {
    if (PIE1bits.TMR2IE && PIR1bits.TMR2IF) {
        TMR2_ISR();
    } else if (PIE1bits.TXIE && PIR1bits.TXIF) {
        EUSART_Transmit_ISR();
    }
}

void PIN_Initialize() {

    LATA = 0x00;
    LATB = 0x80;
    LATC = 0x00;

    TRISA = 0x30;
    TRISB = 0x60;
    TRISC = 0x05;

    ANSELC = 0x05;
    ANSELB = 0x00;
    ANSELA = 0x00;

    WPUB = 0x60;
    WPUA = 0x00;
    OPTION_REGbits.nWPUEN = 0;
}

void SYSTEM_Initialize() {

    PIN_Initialize();
    OSC_Initialize_Default();
    TMR2_Initialize_Default();
    PWM1_Initialize();
    PWM2_Initialize();
    PWM3_Initialize();
    PWM4_Initialize();
    EUSART_Initialize_Default();
    ADC_Initialize_Default();
}

void Interrupt_Initialize() {
    TMR2_SetInterruptHandler(Led_Run);
    Key_SetActionHandler(Led_OnKeyPressed);
}

