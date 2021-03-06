/* 
 * File:   driver.h
 * Author: liruya
 *
 * Created on 2017年11月14日, 上午11:21
 */

#ifndef DRIVER_H
#define	DRIVER_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "chip_16f1508.h"
#include "pps.h"
#include "tmr0.h"
#include "tmr1.h"
#include "tmr2.h"
#include "pwm.h"
#include "flash.h"
#include "eusart.h"
#include "adc.h"
#include "osc.h"
    
#define GlobleInterruptDisable()        (INTCONbits.GIE = 0)
#define GlobleInterruptEnable()         (INTCONbits.GIE = 1)
#define PeripheralInterruptDisable()    (INTCONbits.PEIE = 0)
#define PeripheralInterruptEnable()     (INTCONbits.PEIE = 1)

#ifdef	__cplusplus
}
#endif

#endif	/* DRIVER_H */

