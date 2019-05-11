#include <stdio.h>

void symbol(char s);

int main(void)
{
    char s;
    printf("Podaj znak: ");
    scanf("%c",&s);
    symbol(s);
    return 0;
}

void symbol(char s){
    if((s>=65&&s<=90)||(s>=97&&s<=122)) printf("To jest litera angielskiego alfabetu\n");
    else printf("To nie jest litera angielskiego alfabetu\n");
    if(s>9&&s<100) printf("kod ASCII jest dwucyfrowy\n");
    else printf("kod ASCII nie jest dwucyfrowy\n");
    if(s=='+'||s=='-'||s=='*'||s=='/') printf("To jest znak dzialania arytmetycznego");
    else printf("To nie jest znak dzialania arytmetycznego");
}
