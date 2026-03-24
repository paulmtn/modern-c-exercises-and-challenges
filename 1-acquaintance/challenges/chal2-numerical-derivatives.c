#include <math.h>
#include <stdio.h>

double derivative(double F(double), double x) {
    double h = 1E-9;

    double result = (F(x + h) - F(x))/h;
    return result;
}

double randomFunction(double x) {
    return pow(x, 2) + x;
}

int main(void) {
    double x0 = 0;
    printf("The derivative of sin at x = %.1f is: %.1f\n", x0, derivative(sin, x0));

    double x1 = 5;
    printf("The derivative of x^2 + x at x = %.1f is: %.1f\n", x1, derivative(randomFunction, x1));
}

