#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float ar(int a, int b);
float ge(int a, int b);

int main(void) {
	int a, b;
	printf("Podaj dwie liczby calkowite: ");
	scanf("%i %i", &a, &b);
	printf("Srednia arytmetyczna: %f\nSrednia geometryczna: %f", ar(a, b), ge(a, b));
	return 0;
}

float ar(int a, int b){
	return ((float)(a+b))/2;
}

float ge(int a, int b){
	return sqrt(a*b);
}
