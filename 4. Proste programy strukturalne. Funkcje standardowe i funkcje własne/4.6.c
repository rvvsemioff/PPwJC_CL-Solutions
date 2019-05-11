#include <stdio.h>
#include <stdlib.h>

void age();

int main(void) {
	age();
	return 0;
}

void age(){
    int y, m;
	printf("Podaj wiek w latach i miesiacach: ");
	scanf("%i %i", &y, &m);
	m=12*y+m;
	printf("Podaj czas w miesiacach: ");
	scanf("%i", &y);
	m+=y;
	y=m/12;
	m-=12*y;
	printf("Wiek w przyszlosci: %i lat i %i miesiace", y, m);
}
