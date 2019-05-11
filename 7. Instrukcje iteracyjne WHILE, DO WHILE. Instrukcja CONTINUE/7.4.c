#include <stdio.h>
#include <math.h>

double series(double eps);

int main(void){
    double eps;
    printf("Podaj liczbe EPS: ");
    scanf("%lf", &eps);
    printf("Wartosc szeregu: %lf", series(eps));
    return 0;
}

double series(double eps){
    int i=0;
    double sum=0, add;
    do{
        i++;
        add=i/powf(i+1, 2);
        sum+=add;
    } while(add>eps);
    return sum;
}
