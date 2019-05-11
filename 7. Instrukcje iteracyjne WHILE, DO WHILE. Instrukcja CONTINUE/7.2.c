#include <stdio.h>
#include <conio.h>

void count(char s);

int main(void){
    char s;
    printf("Podaj litere: ");
    s=getchar();
    count(s);
    return 0;
}

void count(char s){
    int i=0, j=0;
    char c;
    printf("Napisz zdanie: ");
    while(c!='.'){
        c=getche();
        if(c==s) i++;
        else if(c>47&&c<58) j++;
    }
    printf("\nLitera '%c' wystapila %d razy, a cyfry - %d razy.", s, i, j);
}
