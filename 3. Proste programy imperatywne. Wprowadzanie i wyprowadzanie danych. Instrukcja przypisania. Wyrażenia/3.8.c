#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	float a, b, x;
	printf("Podaj stale a oraz b: ");
	scanf("%f%f", &a, &b);
	printf("Podaj zmienna: ");
	scanf("%f", &x);
	printf("a) %f\n", 10*cos(x)-0.1*pow(x,2)+sin(x)+sqrt(4*pow(x,2)+7));
	printf("b) %f\n", log(x+5)+exp(x+1)-fabs(tan(x)+1));
	printf("c) %f\n", (pow(sin(a),2)+0.5)/(cos(pow(a,4))+pow(tan(pow(a,2)),4)));
	printf("d) %f\n", sqrt(fabs(5*sin(pow(b,5))+1)/(3.5*pow(sin(b)+cos(b),2))));
	return 0;
}
