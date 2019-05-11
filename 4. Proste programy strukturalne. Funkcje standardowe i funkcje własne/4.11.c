#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void coordinates();
void perimeter(float x1, float x2, float y1, float y2);

int main(void) {
	coordinates();
	return 0;
}

void coordinates(){
    float x1, x2, y1, y2;
	printf("Podaj wspowrzedne punktu przez ktory przechodzi okreg: ");
	scanf("%f%f", &x1, &y1);
	printf("Podaj wspowrzedne srodku okregu: ");
	scanf("%f%f", &x2, &y2);
	perimeter(x1,x2,y1,y2);
}

void perimeter(float x1, float x2, float y1, float y2){
    printf("Obwod okregu wynosi: %f", 2*M_PI*sqrt(pow(x1-x2, 2)+pow(y1-y2, 2)));
}
