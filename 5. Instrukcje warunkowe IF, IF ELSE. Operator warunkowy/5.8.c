#include <stdio.h>

int calc(int a, int b, int c);

int main(void)
{
    int a,b,c;
    printf("Podaj trzy liczby calkowite: ");
    scanf("%d%d%d",&a,&b,&c);
    printf("Funkcja zwraca: %d", calc(a,b,c));
    return 0;
}

int calc(int a, int b, int c){
    if(a%2==0&&b%2==0&&c%2==0) return a+b+c;
    return (a==1||b==1||c==1)?a*b*c:-1;
}
