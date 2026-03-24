#include <stdio.h>
#include <limits.h>

int main(void) {
    printf("unsigned int max: %u\n", UINT_MAX);

    unsigned int a = 0x80000000;
    unsigned int b = 0x80000000;

    printf("0x80000000  = %u\n", a);
    printf("-0x80000000 = %u\n", b);
    printf("equal: %d\n", a == b);
    
    return 0;
}

// 0x80000000 in binary:
// 1000 0000 0000 0000 0000 0000 0000 0000

// flip all bits:
// 0111 1111 1111 1111 1111 1111 1111 1111

// add 1:
// 1000 0000 0000 0000 0000 0000 0000 0000
// same thing