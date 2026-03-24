#include <math.h>
#include <stdio.h>
#include <complex.h>


double complex derivative(double complex F(double complex), double complex x) {
    double complex h = CMPLX(0, 1E-9);

    double complex result = (F(x + h) - F(x))/h;
    return result;
}

double complex randomFunction(double complex x) {
    return cpow(x, 2) + x;
}

int main(void) {
    double complex z = CMPLX(1, 2);
    printf("complex: %f + %fi\n", creal(z), cimag(z));

    double complex x0 = CMPLX(1, 2);
    double complex x0_derivative = derivative(csin, x0);
    printf("The derivative of sin at x = %.1f +- %.1f is: %.1f + %.1fi\n", creal(x0), cimag(x0), creal(x0_derivative), cimag(x0_derivative));

    double complex x1 = CMPLX(1, 2);
    double complex x1_derivative = derivative(ccos, x1);
    printf("The derivative of sin at x = %.1f +- %.1f is: %.1f + %.1fi\n", creal(x1), cimag(x1), creal(x1_derivative), cimag(x1_derivative));
}

