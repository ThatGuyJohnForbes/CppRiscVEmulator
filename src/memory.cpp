//
// Created by John on 15/12/2022.
//

#include "memory.h"

std::uint64_t Memory::load(uint64_t addr, uint64_t size) {
    addr = addr-DRAM_BASE;
    switch (size) {
        case 8:
            return load8(addr);
        case 16:
            return load16(addr);
        case 32:
            return load32(addr);
        case 64:
            return load64(addr);
        default:
            assert(false && "Error: Attempted to load an unsupported data size from memory\n");
            return -1;
    }
}

void Memory::store(uint64_t addr, uint64_t size, uint64_t data) {
    addr = addr-DRAM_BASE;
    switch (size) {
        case 8:
            store8(addr,data);
            break;
        case 16:
            store16(addr,data);
            break;
        case 32:
            store32(addr,data);
            break;
        case 64:
            store64(addr,data);
            break;
        default:
            assert(false && "Error: Attempted to store an unsupported data size into memory\n");
    }
}

uint64_t Memory::load8(uint64_t addr) {
    return memory[addr];
}

uint64_t Memory::load16(uint64_t addr) {
    return (static_cast<uint32_t>(memory[addr])) |
           (static_cast<uint32_t>(memory[addr+1]) << 8);
}

uint64_t Memory::load32(uint64_t addr) {
    return (static_cast<uint32_t>(memory[addr])) |
           (static_cast<uint32_t>(memory[addr+1]) << 8) |
           (static_cast<uint32_t>(memory[addr+2]) << 16) |
           (static_cast<uint32_t>(memory[addr+3]) << 24);
}

uint64_t Memory::load64(uint64_t addr) {
    return (static_cast<uint64_t>(memory[addr])) |
           (static_cast<uint64_t>(memory[addr+1]) << 8) |
           (static_cast<uint64_t>(memory[addr+2]) << 16) |
           (static_cast<uint64_t>(memory[addr+3]) << 24) |
           (static_cast<uint64_t>(memory[addr+4]) << 32) |
           (static_cast<uint64_t>(memory[addr+5]) << 40) |
           (static_cast<uint64_t>(memory[addr+6]) << 48) |
           (static_cast<uint64_t>(memory[addr+7]) << 56);
}

void Memory::store8(uint64_t addr, uint64_t data) {
    memory[addr] = (uint8_t)(data & 0xff);
}

void Memory::store16(uint64_t addr, uint64_t data) {
    memory[addr] = (uint8_t)(data & 0xff);
    memory[addr + 1] = (uint8_t)((data >> 8) & 0xff);
}

void Memory::store32(uint64_t addr, uint64_t data) {
    memory[addr] = (uint8_t)(data & 0xff);
    memory[addr + 1] = (uint8_t)((data >> 8) & 0xff);
    memory[addr + 2] = (uint8_t)((data >> 16) & 0xff);
    memory[addr + 3] = (uint8_t)((data >> 24) & 0xff);
}

void Memory::store64(uint64_t addr, uint64_t data) {
    memory[addr] = (uint8_t)(data & 0xff);
    memory[addr + 1] = (uint8_t)((data >> 8) & 0xff);
    memory[addr + 2] = (uint8_t)((data >> 16) & 0xff);
    memory[addr + 3] = (uint8_t)((data >> 24) & 0xff);
    memory[addr + 4] = (uint8_t)((data >> 32) & 0xff);
    memory[addr + 5] = (uint8_t)((data >> 40) & 0xff);
    memory[addr + 6] = (uint8_t)((data >> 48) & 0xff);
    memory[addr + 7] = (uint8_t)((data >> 56) & 0xff);
}
