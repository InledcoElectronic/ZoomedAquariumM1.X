#include "../inc/pwm.h"

extern volatile unsigned short PWM1DC @ 0x611;
extern volatile unsigned short PWM2DC @ 0x614;
extern volatile unsigned short PWM3DC @ 0x617;
extern volatile unsigned short PWM4DC @ 0x61A;

void PWM1_Initialize ( )
{
    PWM1CON = PWMCON_EN | PWMCON_OE;
    PWM1DC = 0;
}

void PWM1_LoadDutyValue ( uint16_t dutyValue )
{
	PWM1DC = dutyValue << 6;
}

void PWM2_Initialize ( )
{
	PWM2CON = PWMCON_EN | PWMCON_OE;
    PWM2DC = 0;
}

void PWM2_LoadDutyValue ( uint16_t dutyValue )
{
	PWM2DC = dutyValue << 6;
}

void PWM3_Initialize ( )
{
	PWM3CON = PWMCON_EN | PWMCON_OE;
    PWM3DC = 0;
}

void PWM3_LoadDutyValue ( uint16_t dutyValue )
{
	PWM3DC = dutyValue << 6;
}

void PWM4_Initialize ( )
{
	PWM4CON = PWMCON_EN | PWMCON_OE;
    PWM4DC = 0;
}

void PWM4_LoadDutyValue ( uint16_t dutyValue )
{
	PWM4DC = dutyValue << 6;
}
