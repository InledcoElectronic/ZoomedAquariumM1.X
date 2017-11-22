/* 
 * File:   osc.h
 * Author: liruya
 *
 * Created on 2017年11月16日, 下午4:45
 */

#ifndef OSC_H
#define	OSC_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "chip_16f1508.h"
    
#define OSCCON_IRCF_SHIFT       3
#define OSCCON_IRCF_16M         (15<<OSCCON_IRCF_SHIFT)
#define OSCCON_IRCF_8M          (14<<OSCCON_IRCF_SHIFT)
#define OSCCON_IRCF_4M          (13<<OSCCON_IRCF_SHIFT)
#define OSCCON_IRCF_2M          (12<<OSCCON_IRCF_SHIFT)
#define OSCCON_IRCF_1M          (11<<OSCCON_IRCF_SHIFT)
#define OSCCON_IRCF_500K        (7<<OSCCON_IRCF_SHIFT)
#define OSCCON_IRCF_250K        (6<<OSCCON_IRCF_SHIFT)
#define OSCCON_IRCF_125K        (5<<OSCCON_IRCF_SHIFT)
#define OSCCON_IRCF_62_5K       (4<<OSCCON_IRCF_SHIFT)
#define OSCCON_IRCF_31_25K      (2<<OSCCON_IRCF_SHIFT)
#define OSCCON_IRCF_LF_31K      (0<<OSCCON_IRCF_SHIFT)
#define OSCCON_SCS_SHIFT        0
#define OSCCON_SCS_INTOSC       (2<<OSCCON_SCS_SHIFT)
#define OSCCON_SCS_SOSC         (1<<OSCCON_SCS_SHIFT)
#define OSCCON_SCS_CONFIGBITS   (0<<OSCCON_SCS_SHIFT)

    extern void OSC_Initialize_Default();
    
#ifdef	__cplusplus
}
#endif

#endif	/* OSC_H */

