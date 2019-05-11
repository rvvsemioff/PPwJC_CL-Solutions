#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double fun(double a, int t);

int main(void)
{
    int t;
    double a;
    printf("Podaj a: ");
    scanf("%lf", &a);
    printf("Podaj t: ");
    scanf("%d", &t);
    printf("z = %lf", fun(a,t));
    return 0;
}

double fun(double a, int t){
    switch(t){
        case 0:
        case 1:
        case 2:
        case 3: return 0.5*(1+cos(a));
        case 4:
        case 6:
        case 7: return sqrt(pow(a,2)+1);
        case 8: return 1-sin(a);
    }
}
