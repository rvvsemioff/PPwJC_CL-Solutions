#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void equation1(float x);
void equation2(float a, float b, float x);
void equation3(float x);
void equation4(float a, float x, float y);

int main(void) {
	float a, b, x, y;
	printf("Podaj stale a oraz b: ");
	scanf("%f%f", &a, &b);
	printf("Podaj x oraz y: ");
	scanf("%f%f", &x, &y);
    equation1(x);
    equation2(a,b,x);
    equation3(x);
    equation4(a,x,y);
    return 0;
}

void equation1(float x){
	printf("1) %f\n", (1+pow(x, 2))+sqrt(1+pow(x, 2)));
}

void equation2(float a, float b, float x){
	printf("2) %f\n", fabs(a+b*x)+pow(x, 100)+pow(1+x, 1/3));
}

void equation3(float x){
	printf("3) %f\n", sin(8)+pow(cos(pow(x, 3)), 2)+tan(x));
}

void equation4(float a, float x, float y){
	printf("4) %f\n", (x-y)/(2*a)+(2*a)/(x+y)+(3.2*x));
}
