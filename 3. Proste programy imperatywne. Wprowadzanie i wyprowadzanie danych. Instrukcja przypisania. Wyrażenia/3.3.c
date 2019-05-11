#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	float a, b, c, h, R;
	printf("Podaj strone szescianu: ");
	scanf("%f", &a);
	printf("Objetosc szescianu: %f\n", a*a*a);
	printf("Pole powierzchni szescianu: %f\n", 6*a*a);
	printf("Podaj strone podstawowa prostopadloscianu o podstawie kwadratowej: ");
	scanf("%f", &a);
	printf("Podaj inna strone prostopadloscianu o podstawie kwadratowej: ");
	scanf("%f", &b);
	printf("Objetosc prostopadloscianu o podstawie kwadratowej: %f\n", a*a*b);
	printf("Pole powierzchni prostopadloscianu o podstawie kwadratowej: %f\n", 2*(2*a*b+a*a));
	printf("Podaj strony prostopadloscianu o podstawie prostokatnej: ");
	scanf("%f %f %f", &a, &b, &c);
	printf("Objetosc prostopadloscianu o podstawie prostokatnej: %f\n", a*b*c);
	printf("Pole powierzchni prostopadloscianu o podstawie prostokatnej: %f\n", 2*(a*b+a*b+a*c));
	printf("Podaj radius walca: ");
	scanf("%f", &R);
	printf("Podaj wysokosc walca: ");
	scanf("%f", &h);
	printf("Objetosc walca: %f\n", M_PI*R*R*h);
	printf("Pole powierzchni walca: %f\n", 2*M_PI*R*(R+h));
	return 0;
}
