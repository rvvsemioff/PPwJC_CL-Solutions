#include <stdio.h>
#include <stdlib.h>
#include "funkcje.h"

void data(int pe, int k, int d, int mie, char i[], char n[], char pl[], char mia[], char u[]);

int main() {
	int pe, k, d, mie;
	char i[16], n[16], pl[8], mia[16], u[32];
	printf("Podaj imie: ");
	scanf("%s", i);
	printf("Podaj nazwisko: ");
	scanf("%s", n);
	printf("Podaj pesel: ");
	scanf("%d", &pe);
	printf("Podaj plec: ");
	scanf("%s", pl);
	printf("Podaj kod: ");
	scanf("%d", &k);
	printf("Podaj miasto: ");
	scanf("%s", mia);
	printf("Podaj ulice: ");
	scanf("%s", u);
	printf("Podaj nr domu: ");
	scanf("%d", &d);
	printf("Podaj nr mieszkania: ");
	scanf("%d", &mie);
	data(pe, k, d, mie, i, n, pl, mia, u);
	return 0;
}
