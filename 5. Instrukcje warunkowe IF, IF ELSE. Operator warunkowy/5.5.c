#include <stdio.h>

float salary(float sal, int exp);

int main(void)
{
    float sal;
    int exp;
    printf("Podaj pensje pracownika: ");
    scanf("%f", &sal);
    printf("Podaj staz pracownika: ");
    scanf("%d", &exp);
    printf("Wyplata pracownika wynosi: %0.2f", salary(sal,exp));
    return 0;
}

float salary(float sal, int exp){
    if(exp<5) return sal;
    return (exp<11)?sal+sal*(float)exp*0.01:sal+sal*0.15;
}
