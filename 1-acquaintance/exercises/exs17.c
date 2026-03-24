#include <stdio.h>
#include <limits.h>

int main(void) {
    printf("-1U: %u\n", -1U);
    printf("max unsigned: %u\n", UINT_MAX);
    printf("-1UL: %lu\n", -1UL);
    printf("max unsigned: %lu\n", ULONG_MAX);
    printf("-1ULL: %llu\n", -1ULL);
    printf("max unsigned: %llu\n", ULLONG_MAX);
    printf("They are nonpromoted as shown by how they are at the max\n");
}