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
    unsigned B = 18U;

    print_binary(A);
    print_binary(B);

    // equivalent to A ^ B operator
    // change A XOR B
    print_binary((A - (A&B)) + (B - (A&B)));
}