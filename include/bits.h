#ifndef BITS_H
#define BITS_H

#include <stdint.h>

/**
 * Bit manipulation macros:
 * - 1U suffix prevents signed integer overflow on 32-bit registers (MISRA C rule).
 * - Comprehensive parentheses prevent operator precedence bugs during expansion.
 */
#define BIT_SET(reg, bit)     ((reg) |= (1U << (bit)))
#define BIT_CLEAR(reg, bit)   ((reg) &= ~(1U << (bit)))
#define BIT_TOGGLE(reg, bit)  ((reg) ^= (1U << (bit)))
#define BIT_CHECK(reg, bit)   (((reg) >> (bit)) & 1U)

/**
 * @brief Prints a 32-bit unsigned integer in binary representation.
 * @param val The 32-bit register value to inspect.
 */
void print_binary32(uint32_t val);

#endif /* BITS_H */
