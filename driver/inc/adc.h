#ifndef ADC_H
#define ADC_H

#include "chip_16f1508.h"

#define ADCON0_CHS_SHIFT        2
#define ADCON0_CHS_AN0          (0<<ADCON0_CHS_SHIFT)
#define ADCON0_CHS_AN1          (1<<ADCON0_CHS_SHIFT)
#define ADCON0_CHS_AN2          (2<<ADCON0_CHS_SHIFT)
#define ADCON0_CHS_AN3          (3<<ADCON0_CHS_SHIFT)
#define ADCON0_CHS_AN4          (4<<ADCON0_CHS_SHIFT)
#define ADCON0_CHS_AN5          (5<<ADCON0_CHS_SHIFT)
#define ADCON0_CHS_AN6          (6<<ADCON0_CHS_SHIFT)
#define ADCON0_CHS_AN7          (7<<ADCON0_CHS_SHIFT)
#define ADCON0_CHS_AN8          (8<<ADCON0_CHS_SHIFT) 
#define ADCON0_CHS_AN9          (9<<ADCON0_CHS_SHIFT)
#define ADCON0_CHS_AN10         (10<<ADCON0_CHS_SHIFT)
#define ADCON0_CHS_AN11         (11<<ADCON0_CHS_SHIFT)
#define ADCON0_CHS_TEMP         (29<<ADCON0_CHS_SHIFT)  
#define ADCON0_CHS_DAC          (30<<ADCON0_CHS_SHIFT)
#define ADCON0_CHS_FVR          (31<<ADCON0_CHS_SHIFT)
#define ADCON0_ADGO_SHIFT       1
#define ADCON0_ADGO             (1<<ADCON0_ADGO_SHIFT)
#define ADCON0_ADON_SHIFT       0
#define ADCON0_ADON             (1<<ADCON0_ADON_SHIFT)

#define ADCON1_ADFM_SHIFT       7
#define ADCON1_ADFM_RIGHT       (1<<ADCON1_ADFM_SHIFT)
#define ADCON1_ADFM_LEFT        (0<<ADCON1_ADFM_SHIFT)
#define ADCON1_ADCS_SHIFT       4
#define ADCON1_ADCS_ADCRC       (7<<ADCON1_ADCS_SHIFT) 
#define ADCON1_ADCS_FOSC_64     (6<<ADCON1_ADCS_SHIFT) 
#define ADCON1_ADCS_FOSC_16     (5<<ADCON1_ADCS_SHIFT)
#define ADCON1_ADCS_FOSC_4      (4<<ADCON1_ADCS_SHIFT)
#define ADCON1_ADCS_FOSC_32     (2<<ADCON1_ADCS_SHIFT)
#define ADCON1_ADCS_FOSC_8      (1<<ADCON1_ADCS_SHIFT)
#define ADCON1_ADCS_FOSC_2      (0<<ADCON1_ADCS_SHIFT)
#define ADCON1_ADPREF_SHIFT     0
#define ADCON1_ADPREF_VREF      (2<<ADCON1_ADPREF_SHIFT)
#define ADCON1_ADPREF_VDD       (0<<ADCON1_ADPREF_SHIFT)

#define ADCON2_TRIGSEL_SHIFT    4
#define ADCON2_TRIG_NONE        (0<<ADCON2_TRIGSEL_SHIFT)
#define ADCON2_TRIG_TMR0OVF     (3<<ADCON2_TRIGSEL_SHIFT)
#define ADCON2_TRIG_TMR1OVF     (4<<ADCON2_TRIGSEL_SHIFT)
#define ADCON2_TRIG_TMR2MATCH   (5<<ADCON2_TRIGSEL_SHIFT)
#define ADCON2_TRIG_C1OUT       (6<<ADCON2_TRIGSEL_SHIFT)
#define ADCON2_TRIG_C2OUT       (7<<ADCON2_TRIGSEL_SHIFT)
#define ADCON2_TRIG_CLC1OUT     (8<<ADCON2_TRIGSEL_SHIFT)
#define ADCON2_TRIG_CLC2OUT     (9<<ADCON2_TRIGSEL_SHIFT)
#define ADCON2_TRIG_CLC3OUT     (10<<ADCON2_TRIGSEL_SHIFT)
#define ADCON2_TRIG_CLC4OUT     (11<<ADCON2_TRIGSEL_SHIFT)

#define ADCON0_CHS_ANA0         ADCON0_CHS_AN0
#define ADCON0_CHS_ANA1         ADCON0_CHS_AN1
#define ADCON0_CHS_ANA2         ADCON0_CHS_AN2
#define ADCON0_CHS_ANA4         ADCON0_CHS_AN3
#define ADCON0_CHS_ANC0         ADCON0_CHS_AN4
#define ADCON0_CHS_ANC1         ADCON0_CHS_AN5
#define ADCON0_CHS_ANC2         ADCON0_CHS_AN6
#define ADCON0_CHS_ANC3         ADCON0_CHS_AN7
#define ADCON0_CHS_ANC6         ADCON0_CHS_AN8
#define ADCON0_CHS_ANC7         ADCON0_CHS_AN9
#define ADCON0_CHS_ANB4         ADCON0_CHS_AN10
#define ADCON0_CHS_ANB5         ADCON0_CHS_AN11

#define ADCHS_ANA0         0
#define ADCHS_ANA1         1
#define ADCHS_ANA2         2
#define ADCHS_ANA4         3
#define ADCHS_ANC0         4
#define ADCHS_ANC1         5
#define ADCHS_ANC2         6
#define ADCHS_ANC3         7
#define ADCHS_ANC6         8
#define ADCHS_ANC7         9
#define ADCHS_ANB4         10
#define ADCHS_ANB5         11
#define ADCHS_TEMP         29  
#define ADCHS_DAC          30
#define ADCHS_FVR          31

extern void ADC_Initialize_Default ();
extern uint16_t ADC_Conversion ( uint8_t chn );

#endif