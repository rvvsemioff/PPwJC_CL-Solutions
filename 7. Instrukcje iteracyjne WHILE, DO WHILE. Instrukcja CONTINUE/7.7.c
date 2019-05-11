#include <stdio.h>

int isinc(void);

int main(void){
    if(isinc()==1) printf("Liczby tworza ciag rosnacy.");
    else printf("Liczby nie tworza ciag rosnacy.");
    return 0;
}

int isinc(void){
    int n, r=1;
    double vp, vn;
    printf("Podaj ilosc liczb: ");
    scanf("%d", &n);
    printf("Podaj liczbe: ");
    scanf("%lf", &vp);
    while(0<--n){
        printf("Podaj liczbe: ");
        scanf("%lf", &vn);
        if(vp>vn) r=0;
        vp=vn;
    }
    return r;
}
