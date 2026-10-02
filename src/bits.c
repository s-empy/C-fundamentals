#include <stdio.h>
#include "bits.h"

void print_binary32(uint32_t val) {
    for (int i = 31; i >= 0; i--) {
        /* Read i-th bit using the BIT_CHECK macro */
        printf("%u", BIT_CHECK(val, (uint32_t)i));

        /* Add a space every 8 bits for readability (byte separation) */
        if (i % 8 == 0 && i != 0) {
            printf(" ");
        }
    }
    printf("\n");
}
