#include <stdio.h>

int islucky(int n);

int main(void)
{
    int n;
    printf("Podaj szesciocyfrowy numer biletu: ");
    scanf("%d", &n);
    if(islucky(n)) printf("To jest bilet szczesliwy");
    else printf("To nie jest bilet szczesliwy");
    return 0;
}

int islucky(int n){
    return (n/100000+(n/10000)%10+(n/1000)%10==(n/100)%10+(n/10)%10+n%10)?1:0;
}
