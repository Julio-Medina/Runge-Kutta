#include <stdio.h>
#include <math.h>

double f(double t, double y, double z) {
    // Define the function f(x, y, z) here
    return  2*t*z+y+pow(y,2)*exp(-pow(t,2));
}

void rk2(double (*f)(double, double, double), double x0, double y0, double z0, double h, double *y1, double *z1) {
    double x_mid, k1, k2, l1, l2;

    x_mid = x0 + h/2;

    k1 = h * z0;
    l1 = h * f(x0, y0, z0);
    k2 = h * (z0 + l1/2);
    l2 = h * f(x_mid, y0 + k1/2, z0 + l1/2);

    *y1 = y0 + k2;
    *z1 = z0 + l2;
}

int main() {
    double x0 = 0.0, y0 = 1.0, z0 = 0.0; // Initial values
    double h = 0.25; // Step size
    double x, y, z;
    x=x0;
    printf("x\ty\ty''\n"); // Print column headers
    printf("%.2f\t%.5f\t%.5f\n", x0, y0, z0); // Print initial values

    for (int i = 1; i <= 10; i++) {
        rk2(f, x0, y0, z0, h, &y, &z);

        // Update x and the initial values for the next iteration
        x = x + h;
        y0 = y;
        z0 = z;

        // Print the new values of x, y, and z
        printf("%.2f\t%.5f\t%.5f\n", x, y, z);
    }

    return 0;
}
