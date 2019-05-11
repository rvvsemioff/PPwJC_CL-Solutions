#include <stdio.h>
#include <stdlib.h>

void symbol();
void code(char s);

int main(void) {
	symbol();
	return 0;
}

void symbol(){
    char s;
	printf("Podaj znak: ");
	scanf("%c", &s);
	code(s);
}

void code(char s){
    printf("Znak: %c\nKod ASCII: %i\nPodaj kod: ", s, s);
	scanf("%i", &s);
	printf("Znak: %c", s);
}
