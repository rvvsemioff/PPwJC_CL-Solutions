#include <stdio.h>
#include <stdlib.h>
#define STATUS "student"
#define SREDNIA_OCEN 3.4

void data();

int main() {
	data();
	return 0;
}

void data(){
	int pe, k, d, mie;
	char i[16], n[16], pl[8], mia[16], u[32];
	printf("Podaj imie: ");
	scanf("%s", &i);
	printf("Podaj nazwisko: ");
	scanf("%s", &n);
	printf("Podaj pesel: ");
	scanf("%d", &pe);
	printf("Podaj plec: ");
	scanf("%s", &pl);
	printf("Podaj kod: ");
	scanf("%d", &k);
	printf("Podaj miasto: ");
	scanf("%s", &mia);
	printf("Podaj ulice: ");
	scanf("%s", &u);
	printf("Podaj nr domu: ");
	scanf("%d", &d);
	printf("Podaj nr mieszkania: ");
	scanf("%d", &mie);
	printf("%s - %s - %d - %s\n%d - %s - %s - %d - %d\n%s", i, n, pe, pl, k, mia, u, d, mie, STATUS);
}
