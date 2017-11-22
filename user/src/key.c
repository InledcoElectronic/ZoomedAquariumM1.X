#include "../inc/key.h"

volatile uint8_t keyValue;
Key_Press_t key_press_cb;
Key_Idle_t key_idle_cb;

static uint8_t Key_Read() {
    uint16_t value = ADC_Conversion(ADCHS_KEY);
    if (value < 48) {
        return KEY_NONE;
    } else if (value > 150 && value < 250) {
        return KEY_MODE;
    } else if (value > 350 && value < 450) {
        return KEY_INCREASE;
    } else if (value > 550 && value < 650) {
        return KEY_DECREASE;
    } else if (value > 750 && value < 850) {
        return KEY_VOLUME;
    } else {
        return KEY_NONE;
    }
}

void Key_Scan() {
    static uint8_t lastKey = KEY_NONE;
    static uint8_t rptCount = 0;
    static uint16_t idleCount = 0;
    uint8_t keyNum = Key_Read();

    if (keyNum != KEY_NONE) {
        idleCount = 0;
        if (keyNum == lastKey) {
            if (rptCount < RPT_COUNT) {
                rptCount++;
            } else if (rptCount == RPT_COUNT) {
                rptCount++;
                keyValue = keyNum | KEY_MASK;
                if (key_press_cb) {
                    key_press_cb(keyValue);
                }
            }
        } else {
            rptCount = 0;
        }
    } else {
        if (lastKey != KEY_NONE) {
            if (rptCount > MIN_COUNT && rptCount < RPT_COUNT) {
                keyValue = lastKey;
                if (key_press_cb) {
                    key_press_cb(keyValue);
                }
            }
        }
        rptCount = 0;

        if (idleCount < IDLE_COUNT) {
            idleCount++;
        } else if (idleCount == IDLE_COUNT) {
            idleCount++;
            if (key_idle_cb) {
                key_idle_cb();
            }
        }
    }
    lastKey = keyNum;
}

void Key_SetActionHandler(Key_Press_t handler) {
    key_press_cb = handler;
}

void Key_SetIdleHandler(Key_Idle_t handler) {
    key_idle_cb = handler;
}
