#include <stdio.h>
#include <math.h>

double sin_K(double x, int K);
long fact(int n);

int main(void){
    int ch, K;
    double x;
    printf("Podaj ilosc skladnikow sumy: ");
    scanf("%d", &K);
    if(K<1){
        printf("Niewlasciwe dane!");
        return 0;
    }
    printf("Podaj kat: ");
    scanf("%lf", &x);
    for(; ; ){
        printf("Wybierz jednostke:\n1. stopien\n2. radian\n");
        scanf("%d", &ch);
        if(ch==1){
            x*=0.01745329;
            printf("sin x = %.15lf", sin_K(x, K));
            break;
        }
        else if(ch==2){
            printf("sin x = %.15lf", sin_K(x, K));
            break;
        }
        else printf("Niewlasciwy wybor!\n");
    }
    return 0;
}

double sin_K(double x, int K){
    double result=x;
    for(int n=1; n<K; n++) result+=(pow(-1, n)/(double)fact(2*n+1))*pow(x, 2*n+1);
    return result;
}

long fact(int n){
    long result=1;
    if(n==0) return 1;
    for(; n; n--) result*=n;
    return result;
}
