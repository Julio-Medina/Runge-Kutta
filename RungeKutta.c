#include<stdio.h>
#include<math.h>
float f(float t,float y)/*funcion a resolver*/
{
    float value;
    value=t*sin(y);
    return value;
}

void rk4(float y0, float t0, float tf,int stepnumber)
{
	float h=(tf-t0)/stepnumber;
	float yn,tn,k1,k2,k3,k4;
	yn=y0;tn=t0;
	printf("                        Método Runge-Kutta\n");
	
	
	
	printf("\n  t\t  y\n");
	for(int i=0;i<=stepnumber;i++){
		k1=f(tn,yn);
		k2=f(tn+h/2,yn+k1*h/2);
		k3=f(tn+h/2,yn+k2*h/2);
		k4=f(tn+h,yn+h*k3);
		printf("%0.3f\t%0.3f\n",tn,yn);
		yn+=(h/6)*(k1+2*k2+2*k3+k4);
		tn+=h;
		
	}
	
	
	
}
void main(){	
	rk4(1,0,10,50);
}
	
	
