#include <stdio.h>

double calc(int N, double X, double Y, double Z);

int main(void){
    int N;
    double X, Y, Z;
    printf("Podaj skladke w zl: ");
    scanf("%lf", &X);
    printf("Podaj procent potracen: ");
    scanf("%lf", &Y);
    printf("Podaj procent dochodu: ");
    scanf("%lf", &Z);
    for(; ; ){
        printf("Podaj ilosc lat: ");
        scanf("%d", &N);
        if(N>0) break;
        else printf("Niewlasciwe dane!\n");
    }
    printf("Kwota: %lf", calc(N, X, Y, Z));
    return 0;
}

double calc(int N, double X, double Y, double Z){
    double sum=0;
    for(; N; N--){
        sum+=X-X*Y;
        sum*=1+Z;
    }
    return sum;
}
