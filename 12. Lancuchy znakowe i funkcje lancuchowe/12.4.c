#include <windows.h>
#include <stdio.h>

void capitalize(char *str);
void align(char *str);

int main(void){
    char str[81];
    SetConsoleCP(1250);
    SetConsoleOutputCP(1250);
    puts("Wprowadü napis: ");
    fgets(str, 80, stdin);
    capitalize(str);
    align(str);
    puts(str);
    return 0;
}

void capitalize(char *str){
    for(int i=0; i<strlen(str); i++) if(str[i]>96&&str[i]<123) str[i]-=32;
}

void align(char *str){
    char buffer[81]="";
    for(int i=0; i<(80-strlen(str))/2; i++) strcat(buffer, " ");
    strcat(buffer, str);
    strcpy(str, buffer);
}
