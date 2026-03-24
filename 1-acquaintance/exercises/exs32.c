#include <stdio.h>

void print_binary(unsigned number) {
    for (int i = 31; i >= 0; i--) {
        // number >> i shifts all the bits of the number right by i positions
        // if number is 1101 and i is 1, it becomes 0110 
        printf("%u", (number >> i) & 1);
        if (i % 4 == 0) printf(" ");
    }
    printf("\n");
}

int main(void) {
    unsigned A = 15U;

    print_binary(A);

    unsigned n = 3;
    print_binary(A >> n);

    print_binary(A % (1ULL << n));

    // The operation A >> n will lose n bits
    // !ULL << n gives 1 shifted left n times
    // So when getting the remainder, everything 
    // to the left goes away and we are left with n bits lost
}