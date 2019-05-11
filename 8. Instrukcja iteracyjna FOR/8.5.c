#include <stdio.h>

void mean(void);

int main(void){
    mean();
    return 0;
}

void mean(void){
    int n, f, i, sum=0, c=0;
    printf("Podaj ilosc liczb: ");
    scanf("%d", &n);
    if(n<1){
        printf("Niewlasciwa wartosc!");
        return;
    }
    printf("Podaj liczbe: ");
    scanf("%d", &f);
    for(; n-1; n--){
        printf("Podaj liczbe: ");
        scanf("%d", &i);
        if(i>f){
            sum+=i;
            c++;
        }
    }
    if(c==0){
        printf("Brak liczb wiekszych od pierwszej.");
        return;
    }
    printf("Srednia arytmetyczna liczb wiekszych od pierwszej: %f", (float)sum/c);
}
