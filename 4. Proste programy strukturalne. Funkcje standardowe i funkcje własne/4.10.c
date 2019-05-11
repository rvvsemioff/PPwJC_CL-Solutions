#include <stdio.h>
#include <stdlib.h>

void negation(int a);

int main(void) {
	int a;
	printf("Podaj liczbe calkowite trzycyfrowa: ");
	scanf("%i", &a);
    negation(a);
	return 0;
}

void negation(int a){
	a=(a%10)*100+((a/10)%10)*10+a/100;
	printf("Odwrotna kolejnosc\na = %i\n", a);
}
