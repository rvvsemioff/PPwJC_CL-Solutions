#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int s;
	printf("Podaj znak: ");
	scanf("%c", &s);
	printf("Znak: %c\nKod ASCII: %i\nPodaj kod: ", s, s);
	scanf("%i", &s);
	printf("Znak: %c", s);
	return 0;
}
