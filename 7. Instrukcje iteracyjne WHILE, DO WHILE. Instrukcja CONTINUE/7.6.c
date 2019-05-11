#include <stdio.h>

int geoprogression(void);

int main(void){
    printf("Ilosc liczb tworzacych ciag geometryczny: %d.", geoprogression());
    return 0;
}

int geoprogression(void){
    double b1, b2, q;
    int c=1;
    printf("Podaj b1: ");
    scanf("%lf", &b1);
    printf("Podaj b2: ");
    scanf("%lf", &b2);
    q=b2/b1;
    printf("Podaj zero dla wyjscia.\n");
    do{
        c++;
        b1=b2;
        printf("Podaj nastepna liczba: ");
        scanf("%lf", &b2);
    } while(b2/b1==q&&b2!=0);
    return c;
}
