#include <stdio.h>

typedef struct {
    unsigned char c;
    unsigned i;
    unsigned long long l;
} A;

typedef struct {
    unsigned char c;
    unsigned long long l;
    unsigned i;
} B;

typedef struct {
    unsigned i;
    unsigned char c;
    unsigned long long l;
} C;

typedef struct {
    unsigned i;
    unsigned long long l;
    unsigned char c;
} D;

typedef struct {
    unsigned long long l;
    unsigned char c;
    unsigned i;
} E;

typedef struct {
    unsigned long long l;
    unsigned i;
    unsigned char c;
} F;
    
/*Create six different structure types for each possibility to order three fields inside a structure: one
unsigned char, one unsigned, and one unsigned long long. Print the sizes of these six structures;
they should be significantly different. Compute the minimal size as the sum of the sizes of each member.
Does any of your structure have this size? Which of your structures comes closest to that ideal size?*/

int main(void) {
    // 8 + 1 + 4
    size_t minimal = sizeof(unsigned char) + sizeof(unsigned) + sizeof(unsigned long long);
    printf("Minimal (no padding): %zu\n\n", minimal);

    printf("struct A (char, uint, ull):  %zu\n", sizeof(A));
    printf("struct A (char, ull, uint):  %zu\n", sizeof(B));
    printf("struct A (uint, char, ull):  %zu\n", sizeof(C));
    printf("struct A (uint, ull, char):  %zu\n", sizeof(D));
    printf("struct A (ull, char, uint):  %zu\n", sizeof(E));
    printf("struct A (ull, uint, char):  %zu\n", sizeof(F));

}