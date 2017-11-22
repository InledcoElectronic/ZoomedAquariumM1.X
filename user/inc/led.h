/* 
 * File:   led.h
 * Author: liruya
 *
 * Created on 2017年11月14日, 下午1:41
 */

#ifndef LED_H
#define	LED_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "../../driver/inc/driver.h"

#define CHANNEL_CNT         2
#define MODE_CNT            5
#define BRIGHT_MAX          1000
#define BRIGHT_MIN          10
#define VOLUME_CNT          5
#define VOLUME_MAX          4
#define VOLUME_MIN          0

#define BRIGHT_STEP_RAMP    1
#define BRIGHT_STEP_SEG     200

#define MODE_ALL            0
#define MODE_WHITE          1
#define MODE_BLUE           2
#define MODE_CLOUD          3
#define MODE_STORM          4

#define PWM_CHS_BLUE        0
#define PWM_CHS_WHITE       1

#define LEDPARA_FLASH_ADDR  0xFC0

    typedef union {

        struct {
            unsigned mOn : 1;
            unsigned mMode : 3;
            unsigned mVolOn : 1;
            unsigned mVolume : 3;
            uint16_t all_bright;
            uint16_t white_bright;
            uint16_t blue_bright;
        };
        uint8_t array[ERASE_FLASH_BLOCKSIZE];
    } LedPara_t;

    typedef struct {
        uint16_t mCurrentBright[CHANNEL_CNT];
        uint16_t mTargetBright[CHANNEL_CNT];
        unsigned mParaChanged : 1;
        unsigned music_state : 7;
    } LedRunPara_t;

    typedef void ( *Led_LoadDutyValue_t) (uint16_t duty);

    extern volatile LedPara_t gLedPara;
    extern volatile LedRunPara_t gLedRunPara;

    extern void Led_InitPara();
    extern void Led_Initialize();
    extern void Led_SaveParaIfChanged();
    extern void Led_UpdateBright();
    extern void Led_TurnOnAllRamp();
    extern void Led_TurnOnWhiteRamp();
    extern void Led_TurnOnBlueRamp();
    extern void Led_TurnOffRamp();
    extern void Led_OnKeyPressed(uint8_t key);
    extern void Led_Ramp();
    extern void Led_Run();

#ifdef	__cplusplus
}
#endif

#endif	/* LED_H */

