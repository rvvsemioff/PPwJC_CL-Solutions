#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	int a, b;
	printf("Podaj dwie liczby calkowite: ");
	scanf("%i %i", &a, &b);
	printf("Srednia arytmetyczna: %f\nSrednia geometryczna: %f", ((float)(a+b))/2, sqrt(a*b));
	return 0;
}
