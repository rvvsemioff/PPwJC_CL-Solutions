#include <stdio.h>
#include <math.h>

void quadraticequation(double a, double b, double c);

int main(void)
{
    double a,b,c;
    printf("Podaj zmienne a, b i c: ");
    scanf("%lf%lf%lf", &a, &b, &c);
    quadraticequation(a,b,c);
    return 0;
}

void quadraticequation(double a, double b, double c){
    if(a!=0){
        double d=pow(b,2)-4*a*c;
        if(d<0) printf("Rownanie kwadratowe nie posiada pierwiastkow");
        else if(d==0) printf("Rownanie kwadratowe posiada jeden pierwiastek:\nx = %lf", -b/(2*a));
        else printf("Rownanie kwadratowe posiada dwa pierwiastki:\nx1 = %lf\nx2 = %lf", (-b+sqrt(d))/(2*a), (-b-sqrt(d))/(2*a));
    }
    else printf("Rownanie kwadratowe nie istnieje");
}
