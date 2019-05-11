#include <stdio.h>

int check(int MAX);

int main(void){
    int MAX;
    printf("Podaj wartosc MAX: ");
    scanf("%d", &MAX);
    printf("Nalezy dodac do siebie %d kolejnych liczb calkowitych.", check(MAX));
    return 0;
}

int check(int MAX){
    int i=1, sum=0;
    while(sum<=MAX) sum+=i++;
    return i-2;
}
