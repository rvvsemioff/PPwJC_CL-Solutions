#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int a, b, c;
	printf("Podaj dwie liczby calkowite trzycyfrowe: ");
	scanf("%i%i", &a, &b);
	c=a;
	a=b;
	b=c;
	printf("Zamiana zmiennych\na = %i\nb = %i\n", a, b);
	a=(a%10)*100+((a/10)%10)*10+a/100;
	b=(b%10)*100+((b/10)%10)*10+b/100;
	printf("Odwrotna kolejnosc\na = %i\nb = %i\n", a, b);
	return 0;
}
