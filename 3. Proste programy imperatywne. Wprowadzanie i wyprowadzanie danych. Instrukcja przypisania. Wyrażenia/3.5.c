#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float A;
	printf("Podaj moc w koniach mechamicznych: ");
	scanf("%f", &A);
	printf("Moc w watach: %f\n", 735*A);
	printf("Podaj szybkosc w kilometrach na godzine: ");
	scanf("%f", &A);
	printf("Szybkosc w metrach na sekunde: %f\n", A/3.6);
	printf("Podaj temperature w stopniach Fahrenheita: ");
	scanf("%f", &A);
	printf("Temperatura w stopniach Celsjusza: %f", 0.5555555555556*(A-32));
	return 0;
}
