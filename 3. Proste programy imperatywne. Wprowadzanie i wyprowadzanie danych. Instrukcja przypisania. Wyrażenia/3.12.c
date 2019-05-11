#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	float x1, x2, x3, y1, y2, y3;
	printf("Podaj wspowrzedne 1-go wierzcholka: ");
	scanf("%f%f", &x1, &y1);
	printf("Podaj wspowrzedne 2-go wierzcholka: ");
	scanf("%f%f", &x2, &y2);
	printf("Podaj wspowrzedne 3-go wierzcholka: ");
	scanf("%f%f", &x3, &y3);
	printf("Pole trojkata: %f", 0.5*fabsf(x1*y3-x1*y2+x2*y1-x2*y3+x3*y2-x3*y1));
	return 0;
}
