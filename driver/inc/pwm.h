/* 
 * File:   pwm.h
 * Author: liruya
 *
 */

#ifndef PWM_H
#define	PWM_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "chip_16f1508.h"

#define PWMCON_EN_SHIFT     7
#define PWMCON_EN           (1<<PWMCON_EN_SHIFT)
#define PWMCON_OE_SHIFT     6
#define PWMCON_OE           (1<<PWMCON_OE_SHIFT)
#define PWMCON_OUT_SHIFT    5
#define PWMCON_OUT          (1<<PWMCON_OUT_SHIFT)
#define PWMCON_POL_SHIFT    4
#define PWMCON_POL_HIGH     (0<<PWMCON_POL_SHIFT)
#define PWMCON_POL_LOW      (1<<PWMCON_POL_SHIFT)
    
    void PWM1_Initialize();
    void PWM1_LoadDutyValue(uint16_t dutyValue);

    void PWM2_Initialize();
    void PWM2_LoadDutyValue(uint16_t dutyValue);

    void PWM3_Initialize();
    void PWM3_LoadDutyValue(uint16_t dutyValue);

    void PWM4_Initialize();
    void PWM4_LoadDutyValue(uint16_t dutyValue);


#ifdef	__cplusplus
}
#endif

#endif	/* PWM_H */

