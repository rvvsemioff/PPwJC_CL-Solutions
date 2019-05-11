#include <stdio.h>

int numbers(int *zero);

int main(void){
    int zero=0;
    printf("Ilosc liczb dodatnich: %d\n", numbers(&zero));
    printf("Ilosc zer: %d", zero);
    return 0;
}

int numbers(int *zero){
    int n, i, plus=0;
    while(1){
        printf("Podaj ilosc liczb: ");
        scanf("%d", &n);
        if(n>0) break;
        printf("Niewlasciwa wartosc!\n");
    }
    for(; n; n--){
        printf("Podaj liczbe: ");
        scanf("%d", &i);
        if(i==0) ++*zero;
        if(i>0) plus++;
    }
    return plus;
}
