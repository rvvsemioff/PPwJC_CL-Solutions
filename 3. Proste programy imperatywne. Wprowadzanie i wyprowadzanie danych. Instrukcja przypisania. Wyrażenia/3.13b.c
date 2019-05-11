#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char s;
	printf("Podaj mala litere: ");
	scanf("%c", &s);
	printf("Duza litera: %c", s-32);
	return 0;
}
