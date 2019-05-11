#include <stdio.h>
#include <math.h>

float area(float a, float b, float c);

int main(void) {
	float a, b, c;
	printf("Podaj boki trojkata: ");
	scanf("%f%f%f", &a, &b, &c);
	float res=area(a,b,c);
	if(res==0) printf("Trojkat nie istnieje.");
	else printf("Pole trojkata: %f", res);
	return 0;
}

float area(float a, float b, float c){
    float p=0.5*(a+b+c);
    return (a<b+c&&b<a+c&c<a+b)?sqrtf(p*(p-a)*(p-b)*(p-c)):0;
}
