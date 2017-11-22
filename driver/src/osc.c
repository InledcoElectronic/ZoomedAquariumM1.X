#include "../inc/osc.h"

/**
 * INTOSC 16MHz
 */
void OSC_Initialize_Default ()
{
    OSCCON = OSCCON_IRCF_16M | OSCCON_SCS_INTOSC;
    while( OSCSTATbits.HFIOFS == 0 );
}
