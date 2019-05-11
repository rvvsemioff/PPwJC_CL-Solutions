#include <stdio.h>
#include <math.h>

double fun(double a, int t);

int main(void)
{
    double a;
    int t;
    printf("Podaj liczbe rzeczywista a: ");
    scanf("%lf", &a);
    printf("Podaj liczbe calkowita t: ");
    scanf("%d", &t);
    double res=fun(a,t);
    if(res!=0) printf("Wynik funkcji: %lf", fun(a,t));
    else printf("Niepoprawne dane!");
    return 0;
}

double fun(double a, int t){
    if(t==8) return 1-sin(a);
    else if(t>=0&&t<4) return 0.5*(1+cos(a));
    else if(t==4||t==6||t==7) return sqrt(pow(a,2)+1);
    else return 0;
}
