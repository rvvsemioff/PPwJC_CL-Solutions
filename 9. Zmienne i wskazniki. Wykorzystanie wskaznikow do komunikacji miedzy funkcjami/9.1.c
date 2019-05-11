#include <stdio.h>

int multiply(long long *l);

int main(void){
    long long result=1;
    if(multiply(&result)==0) printf("Brak liczb spelniajacych warunek.");
    else printf("Iloczyn liczb: %lld", result);
    return 0;
}

int multiply(long long *l){
    int N, check=0;
    long long i;
    while(1){
        printf("Podaj ilosc mnoznikow: ");
        scanf("%d", &N);
        if(N>0) break;
        printf("Niewlasciwe dane!\n");
    }
    for(; N; N--){
        printf("Podaj liczbe: ");
        scanf("%lld", &i);
        if(i>0 && i<101){
            check=1;
            *l*=i;
        }
    }
    return check;
}
