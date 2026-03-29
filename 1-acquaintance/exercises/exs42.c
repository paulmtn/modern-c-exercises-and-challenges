#include <stdio.h>

int main(void) {
    printf("%.20f\n", (1.0E-13 + 1.0E-13 + 1.0) - 1.0);
    printf("%.20f\n", (1.0E-13 + (1.0E-13 + 1.0)) - 1.0);

}