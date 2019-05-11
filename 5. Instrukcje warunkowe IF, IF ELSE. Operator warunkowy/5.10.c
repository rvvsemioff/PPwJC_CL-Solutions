#include <stdio.h>

float tax(float sal);

int main(void)
{
    float sal;
    printf("Podaj pensje: ");
    scanf("%f",&sal);
    printf("Podatek wynosi: %0.2f zl", tax(sal));
    return 0;
}

float tax(float sal){
    return (sal<=85528)?0.18*sal-556.02:14839.02+0.32*(sal-85528);
}
