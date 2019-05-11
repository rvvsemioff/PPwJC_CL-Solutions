#include <stdio.h>
#include <stdlib.h>

void read();
void write(char s);

int main(void) {
	read();
	return 0;
}

void read(){
    char s;
	printf("Podaj mala litere: ");
	scanf("%c", &s);
	write(s);
}

void write(char s){
    printf("Duza litera: %c", s-32);
}
