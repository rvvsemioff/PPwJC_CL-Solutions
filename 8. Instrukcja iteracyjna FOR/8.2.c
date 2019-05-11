#include <stdio.h>

void count(void);

int main(void){
    count();
    return 0;
}

void count(void){
    int n, i, c=0;
    printf("Podaj ilosc liczb: ");
    scanf("%d", &n);
    for(n; n; n--){
        printf("Podaj liczbe: ");
        scanf("%d", &i);
        if(i%2==1) c++;
    }
    printf("Ilosc liczb nieparzystych: %d.", c);
}
