#include <stdio.h>

float transaction(int n, float price, float *act_price);

int main(void){
    int n;
    float price, act_price;
    while(1){
        printf("Podaj cena hurtowa 1 sztuki towaru: ");
        scanf("%f", &price);
        if(price>0) break;
        printf("Niewlasciwa wartosc!\n");
    }
    while(1){
        printf("Podaj liczbe zamowionych sztuk: ");
        scanf("%d", &n);
        if(n>0) break;
        printf("Niewlasciwa wartosc!\n");
    }
    printf("Koszt zamowienia: %f\n", transaction(n, price, &act_price));
    printf("Cena 1 sztuki towaru: %f", act_price);
    return 0;
}

float transaction(int n, float price, float *act_price){
    *act_price=(n<10)?price*1.2:price;
    return n**act_price;
}
