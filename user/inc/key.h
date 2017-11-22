/* 
 * File:   key.h
 * Author: liruya
 *
 * Created on 2017年11月16日, 下午5:05
 */

#ifndef KEY_H
#define	KEY_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "../../driver/inc/driver.h"

#define KEY_NONE        0x00
#define KEY_MODE        0x08
#define KEY_INCREASE    0x04
#define KEY_DECREASE    0x02
#define KEY_VOLUME      0x01

#define KEY_MASK        0x80
#define KEY_ONOFF       (KEY_MASK | KEY_MODE)
#define KEY_VOL_ONOFF   (KEY_MASK | KEY_VOLUME)
    
#define ADCHS_KEY       ADCHS_ANC0
    
#define	IDLE_COUNT		1000				
#define	MIN_COUNT		1					
#define RPT_COUNT       128  

    typedef void (*Key_Press_t)( uint8_t key );
    typedef void (*Key_Idle_t)();

    extern volatile uint8_t keyValue;

    extern void Key_Scan();
    extern void Key_SetActionHandler(Key_Press_t handler);
    extern void Key_SetIdleHandler(Key_Idle_t handler);


#ifdef	__cplusplus
}
#endif

#endif	/* KEY_H */

