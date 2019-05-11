#include <stdio.h>
#include <stdlib.h>

void square();
void rectangle();
void trapezoid();
void triangle();

int main() {
	square();
	rectangle();
	trapezoid();
	triangle();
	return 0;
}

void square(){
	float a;
	printf("Podaj strone kwadratu: ");
	scanf("%f", &a);
	printf("Pole powierzchni kwadratu: %f\n", a*a);
	printf("Obwod kwadratu: %f\n", 4*a);
}

void rectangle(){
	float a, b;
	printf("Podaj strony prostokata: ");
	scanf("%f %f", &a, &b);
	printf("Pole powierzchni prostokata: %f\n", a*b);
	printf("Obwod prostokata: %f\n", 2*(a+b));
}

void trapezoid(){
	float a, b, c, d, h;
	printf("Podaj strone podstawowe trapezu: ");
	scanf("%f %f", &a, &b);
	printf("Podaj strone boczne trapezu: ");
	scanf("%f %f", &c, &d);
	printf("Podaj wysokosc trapezu: ");
	scanf("%f", &h);
	printf("Pole powierzchni trapezu: %f\n", (a+b)*h/2);
	printf("Obwod trapezu: %f\n", a+b+c+d);
}

void triangle(){
	float a, b, c, h;
	printf("Podaj strone podstawowa trojkata: ");
	scanf("%f", &a);
	printf("Podaj inne strone trojkata: ");
	scanf("%f %f", &b, &c);
	printf("Podaj wysokosc trojkata: ");
	scanf("%f", &h);
	printf("Pole powierzchni trojkata: %f\n", (a*h)/2);
	printf("Obwod trojkata: %f\n", a+b+c);
}
