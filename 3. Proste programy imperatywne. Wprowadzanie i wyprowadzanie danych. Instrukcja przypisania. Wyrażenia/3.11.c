#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	float x1, x2, y1, y2;
	printf("Podaj wspowrzedne punktu przez ktory przechodzi okreg: ");
	scanf("%f%f", &x1, &y1);
	printf("Podaj wspowrzedne srodku okregu: ");
	scanf("%f%f", &x2, &y2);
	printf("Obwod okregu wynosi: %f", 2*M_PI*sqrt(pow(x1-x2, 2)+pow(y1-y2, 2)));
	return 0;
}
