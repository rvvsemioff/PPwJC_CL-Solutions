#include <stdio.h>

double thebiggest(void);

int main(void){
    printf("Najwieksza liczba: %lf.", thebiggest());
    return 0;
}

double thebiggest(void){
    double i, b=-1;
    printf("Podaj -1 dla zakonczenia dzilania.\n");
    do{
        printf("Podaj liczbe: ");
        scanf("%lf", &i);
        if(i>b) b=i;
    } while(i!=-1);
    return b;
}
