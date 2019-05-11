#include <windows.h>
#include <stdio.h>

int main(void){
    char words[9][13]={"Biblioteka", "string.h", "pozwala", "na", "zastosowanie", "funkcji", "do", "lancuchow", "znakowych"}, buffer[76];
    for(int i=0; i<9; i++){
        strcat(buffer, words[i]);
        if(i<8) strcat(buffer, " ");
    }
    SetConsoleCP(1250);
    SetConsoleOutputCP(1250);
    puts(buffer);
    printf("D³ugoœæ zdania posta³ego przez kontatenacjê: %d znaki.\n", strlen(buffer));
    return 0;
}
