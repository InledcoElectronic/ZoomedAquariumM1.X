/* 
 * File:   eeprom.h
 * Author: liruya
 *
 */

#ifndef FLASH_H
#define	FLASH_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "chip_16f1508.h"

#define FLASH_SIZE              4096
#define ERASE_FLASH_BLOCKSIZE   32
#define WRITE_FLASH_BLOCKSIZE   32

    extern void FLASH_EraseBlock(uint16_t addr);
    extern void FLASH_WriteByte(uint16_t addr, uint8_t *buf, uint8_t byte);
    extern bool FLASH_WriteBlock(uint16_t addr, uint8_t *buf);
    extern uint8_t FLASH_ReadByte(uint16_t addr);
    extern void FLASH_ReadBuffer(uint8_t *buf, uint16_t addr, uint8_t size);

#ifdef	__cplusplus
}
#endif

#endif	/* EEPROM_H */

