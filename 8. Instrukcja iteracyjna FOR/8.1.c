#include <stdio.h>

void line(char s);

int main(void){
    char s;
    printf("Podaj znak: ");
    scanf("%c", &s);
    line(s);
    return 0;
}

void line(char s){
    for(int i=50; i; i--){
        printf("%c", s);
    }
}
