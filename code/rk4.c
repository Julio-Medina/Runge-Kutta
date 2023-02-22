#include <stdio.h>
#include <math.h>

double f(double x, double y, double z) {
    // Define the function f(x, y, z) here
    return  pow(y,2)*exp(-pow(x,2));
}

double P(double x){
	
	return -2*x;
	
}

double Q(double x){

	return -1;
}

void rk4(double (*f)(double, double, double), double (*P)(double), double (*Q)(double), double x0, double y0, double z0, double h, double *y1, double *z1) {
    double r1,s1,r2,s2,r3,s3,r4,s4;

    

    r1 = h * z0;
    s1 = h * (f(x0, y0, z0)-P(x0)*z0-Q(x0)*y0);
    r2 = h * (z0 + s1/2);
    s2 = h * (f(x0+h/2, y0+r1/2, z0+s1/2)-P(x0+h/2)*(z0+s1/2)-Q(x0+h/2)*(y0+r1/2));
    r3 = h * (z0+s2/2);
    s3 = h * (f(x0+h/2, y0+r2/2, z0+s2/2)-P(x0+h/2)*(z0+s2/2)-Q(x0+h/2)*(y0+r2/2));	
    r4 = h * (z0+s3);
    s4 = h * (f(x0+h, y0+r3, z0+s3)-P(x0+h)*(z0+s3)-Q(x0+h)*(y0+r3));	
    *y1 = y0 + (r1+2*r2+2*r3+r4)/6;
    *z1 = z0 + (s1+2*s2+2*s3+s4)/6;
    
    
   // printf("%.2f\t%.2f\t%.5f\t%.5f\n", s1, s2, s3, s4);
   // printf("%.2f\t%.2f\t%.5f\t%.5f\n", r1, r2, r3, r4);
    
}

int main() {
    double x0 = 0.0, y0 = 1.0, z0 = 0.0; // Initial values
    double h = 0.25; // Step size
    double x, y, z;
    x=x0;
    printf("x\ty\ty'\n"); // Print column headers
    printf("%.2f\t%.5f\t%.5f\n", x0, y0, z0); // Print initial values

    for (int i = 1; i <= 2; i++) {
        rk4(f,P,Q, x0, y0, z0, h, &y, &z);

        // Update x and the initial values for the next iteration
        x = x + h;
        y0 = y;
        z0 = z;

        // Print the new values of x, y, and z
        printf("%.2f\t%.5f\t%.5f\n", x, y, z);
    }

    return 0;
}
