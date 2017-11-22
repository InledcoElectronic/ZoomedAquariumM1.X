#include "../inc/flash.h"

void FLASH_EraseBlock(uint16_t addr) {
    uint8_t state = GIE;
    GIE = 0;
    PMADR = addr;

    CFGS = 0;
    FREE = 1;
    WREN = 1;

    PMCON2 = 0x55;
    PMCON2 = 0xAA;
    WR = 1;
    NOP();
    NOP();

    WREN = 0;
    GIE = state;
}

void FLASH_WriteByte(uint16_t addr, uint8_t *buf, uint8_t byte) {
    uint16_t start_addr = (uint16_t) (addr & ((FLASH_SIZE - 1) ^ (ERASE_FLASH_BLOCKSIZE - 1)));
    uint8_t offset = (uint8_t) (addr & (ERASE_FLASH_BLOCKSIZE - 1));
    uint8_t i;

    for (i = 0; i < ERASE_FLASH_BLOCKSIZE; i++) {
        *(buf + i) = FLASH_ReadByte((start_addr + i));
    }

    *(buf+offset) = byte;
    FLASH_WriteBlock(start_addr, buf);
}

bool FLASH_WriteBlock(uint16_t addr, uint8_t *buf) {
    uint16_t start_addr = (uint16_t) (addr & ((FLASH_SIZE - 1) ^ (ERASE_FLASH_BLOCKSIZE - 1)));
    uint8_t i;

    if (addr != start_addr) {
        return false;
    }

    FLASH_EraseBlock(addr);
    uint8_t state = GIE;
    GIE = 0;
    CFGS = 0;
    WREN = 1;
    LWLO = 1;

    for (i = 0; i < WRITE_FLASH_BLOCKSIZE; i++) {
        PMADR = addr;
        PMDAT = *(buf+i);

        if (i == (WRITE_FLASH_BLOCKSIZE - 1)) {
            LWLO = 0;
        }

        PMCON2 = 0x55;
        PMCON2 = 0xAA;
        WR = 1;
        NOP();
        NOP();

        addr++;
    }

    WREN = 0;
    GIE = state;

    return true;
}

uint8_t FLASH_ReadByte(uint16_t addr) {
    uint8_t state = GIE;
    GIE = 0;
    PMADR = addr;

    CFGS = 0;
    RD = 1;
    NOP();
    NOP();
    GIE = state;
    return PMDATL;
}

void FLASH_ReadBuffer(uint8_t *buf, uint16_t addr, uint8_t size) {
    for (uint8_t i = 0; i < size; i++) {
        *(buf + i) = FLASH_ReadByte(addr + i);
    }
}
