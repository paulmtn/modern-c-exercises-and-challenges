#include <stdio.h>
#include <limits.h>

int main(void) {
    printf("max: %lld>\n", LLONG_MAX);
    printf("min: %lld>\n", LLONG_MIN);
    printf("max + 1: %lld>\n", LLONG_MAX + 1);
    printf("-max: %lld>\n", -LLONG_MAX);
    printf("min == -max: %d>\n", LLONG_MAX == LLONG_MIN);
}