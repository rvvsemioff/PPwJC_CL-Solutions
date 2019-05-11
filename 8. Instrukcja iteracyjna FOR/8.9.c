#include <stdio.h>

void check(void);

int main(void){
    check();
    return 0;
}

void check(void){
    int n, d;
    long i, j;
    printf("Podaj ilosc liczb: ");
    scanf("%d", &n);
    if(n<2){
        printf("Niewlasciwe dane!");
        return;
    }
    printf("Podaj ciag arytmetyczny: ");
    scanf("%ld", &j);
    scanf("%ld", &i);
    d=i-j;
    for(; n-2; n--){
        j=i;
        scanf("%ld", &i);
        if(d!=i-j){
            printf("Liczby nie tworza ciag arytmetyczny.");
            return;
        }
    }
    printf("Liczby tworza ciag arytmetyczny.");
}
