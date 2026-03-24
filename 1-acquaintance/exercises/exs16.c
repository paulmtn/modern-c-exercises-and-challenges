#include <stdio.h>
#include <limits.h>
#include <math.h>


int main(void) {
    // printf("max unsigned: %u\n", UINT_MAX);
    // printf("2^16: %f\n", pow(2, 32));

    unsigned short x = -0x8000;
    printf("unsigned short max: %u\n", USHRT_MAX);
    printf("0x8000: %u\n", 0x8000);
    printf("-0x8000: %u\n", (unsigned short) -x);
    printf("They are equal because since 0x8000 is bigger than 2^15-1 (signed 16 bit max), C makes it unsigned (max: 2^32-1) so it wraps around\n");
}

// -x = (UINT_MAX + 1) - x
// lets say max is 4 bits
// -5 = (15 + 1) - 5
// -5 = 11
// -5 = 1011
// twos complement: 0100 + 1 = 0101 = 5