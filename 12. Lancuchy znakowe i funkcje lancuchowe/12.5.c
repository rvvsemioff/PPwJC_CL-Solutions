#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

void read(void);

int main(void){
    while(1) read();
    return 0;
}

void read(void){
    char str[81];
    SetConsoleCP(1250);
    SetConsoleOutputCP(1250);
    puts("Wprowadü napis:");
    fgets(str, 81, stdin);
    if(!strcmp(str, "quit\n")) exit(EXIT_SUCCESS);
}
