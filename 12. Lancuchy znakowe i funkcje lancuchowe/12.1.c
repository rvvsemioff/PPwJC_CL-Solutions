#include <stdio.h>
#include <string.h>

void aling(char *str);

int main(void){
    char str1[81], str2[81];
    puts("Wprowadz pierwszy napis:");
    gets(str1);
    puts("Wprowadz drugi napis:");
    gets(str2);
    puts("Napisy wprowadzone:");
    puts(str1);
    puts(str2);
    aling(str1);
    aling(str2);
    puts("Napisy wysrodkowane:");
    puts(str1);
    puts(str2);
    return 0;
}

void aling(char *str){
    short position=(81-strlen(str))/2;
    char buffer[81]="";
    for(int i=1; i<position; i++) strcat(buffer, " ");
    strcat(buffer, str);
    strcpy(str, buffer);
}
