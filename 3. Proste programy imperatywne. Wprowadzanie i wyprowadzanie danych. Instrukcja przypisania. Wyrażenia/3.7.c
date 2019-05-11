#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	float a, b, x, y;
	printf("Podaj stale a oraz b: ");
	scanf("%f%f", &a, &b);
	printf("Podaj x oraz y: ");
	scanf("%f%f", &x, &y);
	printf("1) %f\n", (1+pow(x, 2))+sqrt(1+pow(x, 2)));
	printf("2) %f\n", fabs(a+b*x)+pow(x, 100)+pow(1+x, 1/3));
	printf("3) %f\n", sin(8)+pow(cos(pow(x, 3)), 2)+tan(x));
	printf("4) %f\n", (x-y)/(2*a)+(2*a)/(x+y)+(3.2*x));
	return 0;
}
