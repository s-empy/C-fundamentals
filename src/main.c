#include <stdio.h>
#include "bits.h"

int main(void) {
    /* Simulated 32-bit hardware register initialized to zero */
    uint32_t mock_reg = 0x00000000U;

    printf("1. Initial state:\n   ");
    print_binary32(mock_reg);

    /* Set bit 0: Enable motor */
    BIT_SET(mock_reg, 0);
    printf("2. Bit 0 SET (Motor enabled):\n   ");
    print_binary32(mock_reg);

    /* Set bit 3: Turn on LED without disturbing the motor */
    BIT_SET(mock_reg, 3);
    printf("3. Bit 3 SET (LED turned ON):\n   ");
    print_binary32(mock_reg);

    /* Clear bit 3: Turn off LED while motor remains active */
    BIT_CLEAR(mock_reg, 3);
    printf("4. Bit 3 CLEAR (LED turned OFF):\n   ");
    print_binary32(mock_reg);

    /* Toggle bit 0: Invert motor state (stop motor) */
    BIT_TOGGLE(mock_reg, 0);
    printf("5. Bit 0 TOGGLE (Motor stopped):\n   ");
    print_binary32(mock_reg);

    return 0;
}
