#include "../inc/led.h"
#include "../inc/audio.h"
#include "../inc/key.h"
#include "../inc/util.h"

static Led_LoadDutyValue_t loadDuty[CHANNEL_CNT] = {PWM1_LoadDutyValue, PWM3_LoadDutyValue};
const uint8_t VOLUME[VOLUME_CNT] = {14, 17, 20, 23, 26};
const uint8_t GAIN[VOLUME_CNT] = { 7, 5, 3, 1, 0 };
volatile LedPara_t gLedPara;
volatile LedRunPara_t gLedRunPara;

void Led_InitPara() {
    FLASH_ReadBuffer((uint8_t*) & gLedPara, LEDPARA_FLASH_ADDR, sizeof (gLedPara));
    if (gLedPara.all_bright > BRIGHT_MAX) {
        gLedPara.all_bright = BRIGHT_MAX;
    }
    if (gLedPara.white_bright > BRIGHT_MAX) {
        gLedPara.white_bright = BRIGHT_MAX;
    }
    if (gLedPara.blue_bright > BRIGHT_MAX) {
        gLedPara.blue_bright = BRIGHT_MAX;
    }
#if BRIGHT_MIN > 0
    if (gLedPara.all_bright < BRIGHT_MIN) {
        gLedPara.all_bright = BRIGHT_MIN;
    }
    if (gLedPara.white_bright < BRIGHT_MIN) {
        gLedPara.white_bright = BRIGHT_MIN;
    }
    if (gLedPara.blue_bright < BRIGHT_MIN) {
        gLedPara.blue_bright = BRIGHT_MIN;
    }
#endif
    if (gLedPara.mMode > MODE_STORM) {
        gLedPara.mMode = MODE_ALL;
    }
    if (gLedPara.mVolume > VOLUME_MAX) {
        gLedPara.mVolume = VOLUME_MAX;
    }
#if	VOLUME_MIN > 0
    if (gLedPara.mVolume < VOLUME_MIN) {
        gLedPara.mVolume = VOLUME_MIN;
    }
#endif
    gLedRunPara.music_state = 0;
}
void Audio_Initialize(){
    __delay_ms(640);
    CLRWDT();
    Audio_StopSound();
    __delay_ms(480);
    Audio_SetVolume(gLedPara.mVolOn ? VOLUME[ gLedPara.mVolume ] : 0);
    __delay_ms(480);
    Audio_SetPlayMode(PLAY_SINGLE_CYCLE);
    __delay_ms(480);
}
void Led_Initialize() {
    if (!gLedPara.mOn) {
        Led_TurnOffRamp();
    } else {
        gLedRunPara.music_state = 0;
        switch (gLedPara.mMode) {
            case MODE_ALL:
                Led_TurnOnAllRamp();
                break;
            case MODE_WHITE:
                Led_TurnOnWhiteRamp();
                break;
            case MODE_BLUE:
                Led_TurnOnBlueRamp();
                break;
            default:
                break;
        }
    }
}

void Led_SaveParaIfChanged() {
    if (gLedRunPara.mParaChanged) {
        gLedRunPara.mParaChanged = 0;
        __delay_ms(8);
        FLASH_WriteBlock(LEDPARA_FLASH_ADDR, (uint8_t *) & gLedPara);
    }
}

void Led_UpdateBright() {
    for (uint8_t i = 0; i < CHANNEL_CNT; i++) {
        loadDuty[i](gLedRunPara.mCurrentBright[i]);
    }
}

void Led_TurnOnAllRamp() {
    gLedPara.mOn = 1;
    for (uint8_t i = 0; i < CHANNEL_CNT; i++) {
        gLedRunPara.mTargetBright[i] = gLedPara.all_bright;
    }
}

void Led_TurnOnWhiteRamp() {
    gLedPara.mOn = 1;
    gLedRunPara.mTargetBright[PWM_CHS_BLUE] = 0;
    gLedRunPara.mTargetBright[PWM_CHS_WHITE] = gLedPara.white_bright;
}

void Led_TurnOnBlueRamp() {
    gLedPara.mOn = 1;
    gLedRunPara.mTargetBright[PWM_CHS_BLUE] = gLedPara.blue_bright;
    gLedRunPara.mTargetBright[PWM_CHS_WHITE] = 0;
}

void Led_TurnOffRamp() {
    gLedPara.mOn = 0;
    for (uint8_t i = 0; i < CHANNEL_CNT; i++) {
        gLedRunPara.mTargetBright[i] = 0;
    }
}

void Led_OnKeyPressed(uint8_t key) {
    switch (key) {
        case KEY_MODE:
            if (gLedPara.mOn) {
//                Audio_StopSound();
                gLedPara.mMode++;
                if (gLedPara.mMode >= MODE_CNT) {
                    gLedPara.mMode = MODE_ALL;
                }
                Led_Initialize();
                gLedRunPara.mParaChanged = 1;
            }
            break;
        case KEY_INCREASE:
            if (gLedPara.mOn) {
                if (gLedPara.mMode == MODE_ALL) {
                    Util_IncValue((uint16_t *) & gLedPara.all_bright, BRIGHT_MAX, BRIGHT_STEP_SEG);
                    Led_TurnOnAllRamp();
                    gLedRunPara.mParaChanged = 1;
                } else if (gLedPara.mMode == MODE_WHITE) {
                    Util_IncValue((uint16_t *) & gLedPara.white_bright, BRIGHT_MAX, BRIGHT_STEP_SEG);
                    Led_TurnOnWhiteRamp();
                    gLedRunPara.mParaChanged = 1;
                } else if (gLedPara.mMode == MODE_BLUE) {
                    Util_IncValue((uint16_t *) & gLedPara.blue_bright, BRIGHT_MAX, BRIGHT_STEP_SEG);
                    Led_TurnOnBlueRamp();
                    gLedRunPara.mParaChanged = 1;
                }
            }
            break;
        case KEY_DECREASE:
            if (gLedPara.mOn) {
                if (gLedPara.mMode == MODE_ALL) {
                    Util_DecValue((uint16_t *) & gLedPara.all_bright, BRIGHT_MIN, BRIGHT_STEP_SEG);
                    Led_TurnOnAllRamp();
                    gLedRunPara.mParaChanged = 1;
                } else if (gLedPara.mMode == MODE_WHITE) {
                    Util_DecValue((uint16_t *) & gLedPara.white_bright, BRIGHT_MIN, BRIGHT_STEP_SEG);
                    Led_TurnOnWhiteRamp();
                    gLedRunPara.mParaChanged = 1;
                } else if (gLedPara.mMode == MODE_BLUE) {
                    Util_DecValue((uint16_t *) & gLedPara.blue_bright, BRIGHT_MIN, BRIGHT_STEP_SEG);
                    Led_TurnOnBlueRamp();
                    gLedRunPara.mParaChanged = 1;
                }
            }
            break;
        case KEY_VOLUME:
            if (gLedPara.mOn && gLedPara.mVolOn) {
                gLedPara.mVolume++;
                if (gLedPara.mVolume > VOLUME_MAX) {
                    gLedPara.mVolume = VOLUME_MIN;
                }
                Audio_SetVolume(VOLUME[gLedPara.mVolume]);
                gLedRunPara.mParaChanged = 1;
            }
            break;
        case KEY_ONOFF:
            Audio_StopSound();
            gLedPara.mOn = !gLedPara.mOn;
            Led_Initialize();
            gLedRunPara.mParaChanged = 1;
            break;
        case KEY_VOL_ONOFF:
            if (gLedPara.mOn) {
                gLedPara.mVolOn = !gLedPara.mVolOn;
                Audio_SetVolume(gLedPara.mVolOn ? VOLUME[ gLedPara.mVolume ] : 0);
                gLedRunPara.mParaChanged = 1;
            }
            break;
        default:
            break;
    }
}

void Led_Ramp() {
    for (uint8_t i = 0; i < CHANNEL_CNT; i++) {
        if (gLedRunPara.mCurrentBright[i] + BRIGHT_STEP_RAMP < gLedRunPara.mTargetBright[i]) {
            gLedRunPara.mCurrentBright[i] += BRIGHT_STEP_RAMP;
        } else if (gLedRunPara.mCurrentBright[i] > gLedRunPara.mTargetBright[i] + BRIGHT_STEP_RAMP) {
            gLedRunPara.mCurrentBright[i] -= BRIGHT_STEP_RAMP;
        } else {
            gLedRunPara.mCurrentBright[i] = gLedRunPara.mTargetBright[i];
        }
        loadDuty[i]( gLedRunPara.mCurrentBright[i] );
    }
}

void Led_DynamicCloud(uint16_t ptp) {
    uint8_t i;
    uint16_t val = ptp * ( 6 + GAIN[gLedPara.mVolume] );
    uint16_t duty[CHANNEL_CNT] = {400, 320};
    if (duty[PWM_CHS_WHITE] > val) {
        duty[PWM_CHS_WHITE] -= val;
    } else {
        duty[PWM_CHS_WHITE] = 0;
    }
    for (i = 0; i < CHANNEL_CNT; i++) {
        if (gLedRunPara.mCurrentBright[i] < duty[i]) {
            gLedRunPara.mCurrentBright[i]++;
        } else if (gLedRunPara.mCurrentBright[i] > duty[i]) {
            gLedRunPara.mCurrentBright[i]--;
        }
        loadDuty[i](gLedRunPara.mCurrentBright[i]);
    }
}

void Led_DynamicStorm(uint16_t ptp) {
    uint8_t i;
    uint16_t val = ptp * ( 5 + GAIN[gLedPara.mVolume] );
    uint16_t duty[CHANNEL_CNT] = {500, 64};
    if (duty[PWM_CHS_BLUE] > val) {
        duty[PWM_CHS_BLUE] -= val;
    } else {
        duty[PWM_CHS_BLUE] = 0;
    }
    duty[PWM_CHS_WHITE] += val;
    for (i = 0; i < CHANNEL_CNT; i++) {
        if (gLedRunPara.mCurrentBright[i] < duty[i]) {
            gLedRunPara.mCurrentBright[i]++;
        } else if (gLedRunPara.mCurrentBright[i] > duty[i]) {
            gLedRunPara.mCurrentBright[i]--;
        }
        loadDuty[i](gLedRunPara.mCurrentBright[i]);
    }
}

void Led_RunMusic() {
    if (gLedRunPara.music_state < 32) {
        gLedRunPara.music_state++;
    } else if (gLedRunPara.music_state == 32 ) {
        Audio_SelectSound(gLedPara.mMode + 0x31);
        gLedRunPara.music_state++;
    } 
    switch (gLedPara.mMode) {
        case MODE_ALL:
        case MODE_WHITE:
        case MODE_BLUE:
            Led_Ramp();
            break;
        case MODE_CLOUD:
            Led_DynamicCloud(audio_value);
            break;
        case MODE_STORM:
            Led_DynamicStorm(audio_value);
            break;
        default:
            break;
    }
}

void Led_Run() {
    static uint8_t cnt = 0;
    cnt++;
    if ((cnt & 0x0F) == 0x00) {
        Key_Scan();
    }
    if (gLedPara.mOn) {
        Led_RunMusic();
    } else {
        Led_Ramp();
    }
}