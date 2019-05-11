#include <windows.h>
#include <stdio.h>
#define PI 3.14159

int main(void){
    double r;
    SetConsoleCP(1250);
    SetConsoleOutputCP(1250);
    while(1){
        printf("Podaj promieñ ko³a: ");
        scanf("%lf", &r);
        if(r>0) break;
        puts("Niew³aœciwa wartoœæ!");
    }
    printf("Pole powierzchni ko³a - %lf\n", PI*r*r);
    printf("Obwód okrêgu - %lf\n", 2*PI*r);
    return EXIT_SUCCESS;
}
