#include <stdio.h>

void partlysum(void);

int main(void){
    partlysum();
    return 0;
}

void partlysum(void){
    int n;
    double sum=0, add;
    printf("Podaj ilosc liczb: ");
    scanf("%d", &n);
    while(n-->0){
        printf("Podaj liczbe: ");
        scanf("%lf", &add);
        sum+=add;
        printf("Suma czastkowa: %lf.\n", sum);
    }
}
