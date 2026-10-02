# C Fundamentals: Safe Bit Manipulation Utilities

A lightweight, MISRA-compliant bit manipulation library written in portable C99. Designed for bare-metal embedded software and register-level peripheral control without dynamic memory allocation.

## Motivation & Architecture

In bare-metal embedded programming, peripheral control registers pack multiple hardware flags into a single 32-bit memory location. Direct assignments (`=`) overwrite unrelated configuration bits, risking hardware instability.

This module provides safe macro implementations adhering to strict embedded guidelines:
- **`1U` literal suffix:** Mitigates undefined behavior caused by signed integer overflow when shifting into the sign bit (bit 31).
- **Redundant macro parenthesization:** Shields against operator precedence collisions during macro expansion.

## Bit Manipulation Operations

| Operation | Logic Expression | Description |
| :--- | :--- | :--- |
| **SET** | `((reg) \|= (1U << (bit)))` | Forces target bit to `1` without affecting other bits. |
| **CLEAR** | `((reg) &= ~(1U << (bit)))` | Clears target bit to `0` using inverted mask. |
| **TOGGLE** | `((reg) ^= (1U << (bit)))` | Inverts target bit status using XOR logic. |
| **CHECK** | `(((reg) >> (bit)) & 1U)` | Extracts binary state (`0` or `1`) of the target bit. |

## Project Structure

```text
c-fundamentals/
├── include/
│   └── bits.h         # Macro definitions and public prototypes
├── src/
│   ├── bits.c         # Binary visualization routines
│   └── main.c         # Execution and verification tests
├── Makefile           # Automated build script (-Wall -Wextra -Werror)
├── .gitignore
└── README.md
