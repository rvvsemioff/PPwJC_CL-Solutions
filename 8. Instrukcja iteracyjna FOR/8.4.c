#include <stdio.h>

void count(void);

int main(void){
    count();
    return 0;
}

void count(void){
    int n, i, r;
    printf("Podaj ilosc liczb: ");
    scanf("%d", &n);
    if(n<1){
        printf("Niewlasciwe dane!");
        return;
    }
    if(n<10){
        int s;
        r=1;
        printf("Podaj liczbe: ");
        scanf("%d", &s);
        for(; n-1; n--){
            printf("Podaj liczbe: ");
            scanf("%d", &i);
            if(i>s) r*=i;
        }
    }
    else{
        r=0;
        for(; n; n--){
            printf("Podaj liczbe: ");
            scanf("%d", &i);
            r+=i;
        }
    }
    printf("Wynik: %d.", r);
}
