/* 
 * File:   pps.h
 * Author: liruya
 *
 * Created on 2017年11月14日, 上午9:50
 */

#ifndef PPS_H
#define	PPS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "chip_16f1508.h"
    
#define APFCON_SSSEL_SHIFT      4
#define APFCON_SS_RA3           (1<<APFCON_SSSEL_SHIFT)
#define APFCON_SS_RC6           (0<<APFCON_SSSEL_SHIFT)
#define APFCON_T1GSEL_SHIFT     3
#define APFCON_T1G_RA3          (1<<APFCON_T1GSEL_SHIFT)
#define APFCON_T1G_RA4          (0<<APFCON_T1GSEL_SHIFT)
#define APFCON_CLC1SEL_SHIFT    1
#define APFCON_CLC1_RC5         (1<<APFCON_CLC1SEL_SHIFT)
#define APFCON_CLC1_RA2         (0<<APFCON_CLC1SEL_SHIFT)
#define APFCON_NCO1SEL_SHIFT    0
#define APFCON_NCO1_RC6         (1<<APFCON_NCO1SEL_SHIFT)
#define APFCON_NCO1_RC1         (0<<APFCON_NCO1SEL_SHIFT)

#ifdef	__cplusplus
}
#endif

#endif	/* PPS_H */

