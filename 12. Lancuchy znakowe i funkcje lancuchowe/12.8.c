#include <windows.h>
#include <stdio.h>

void capitalize(char *str);
void align(char *str);

int main(void){
    short i, len;
    char input[81], buffer[81];
    SetConsoleCP(1250);
    SetConsoleOutputCP(1250);
    puts("Wprowadü napis:");
    fgets(input, 80, stdin);
    len=strlen(input)-1;
    strcpy(buffer, input);
    for(i=0; i<len; ++i) input[i]=buffer[len-i-1];
    capitalize(input);
    align(input);
    puts(input);
    return 0;
}

void capitalize(char *str){
    for(int i=0; i<strlen(str); ++i) if(str[i]>96&&str[i]<123) str[i]-=32;
}

void align(char *str){
    char buffer[81]="";
    for(int i=0; i<(80-strlen(str))/2; ++i) strcat(buffer, " ");
    strcat(buffer, str);
    strcpy(str, buffer);
}
