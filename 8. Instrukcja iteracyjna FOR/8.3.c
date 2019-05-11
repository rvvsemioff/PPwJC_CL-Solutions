#include <stdio.h>

void count(void);

int main(void){
    count();
    return 0;
}

void count(void){
    int n, i, m=0, c=0;
    printf("Podaj ilosc liczb: ");
    scanf("%d", &n);
    if(n<=0){
        printf("Niewlasciwe dane!");
        return;
    }
    for(; n; n--){
        printf("Podaj liczbe: ");
        scanf("%d", &i);
        if(i%2==0){
            m+=i;
            c++;
        }
    }
    if(c==0){
        printf("Brak liczb parzystych.");
        return;
    }
    printf("Srednia arytmetyczna liczb parzystych: %f", (float)m/c);
}
