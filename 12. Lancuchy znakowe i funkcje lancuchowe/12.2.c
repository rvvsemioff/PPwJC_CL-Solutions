#include <windows.h>
#include <stdio.h>

void align(char *str);

int main(void){
    char verse[7][81]={ "Stoi na stacji lokomotywa,",
                        "Ciê¿ka, ogromna i pot z niej sp³ywa:",
                        "T³usta oliwa.",
                        "Stoi i sapie, dyszy i dmucha,",
                        "¯ar z rozgrzanego jej brzucha bucha:",
                        "Buch - jak gor¹co!",
                        "Uch - jak gor¹co!"};
    SetConsoleCP(1250);
    SetConsoleOutputCP(1250);
    for(int i=0; i<7; i++){
        align(verse[i]);
        puts(verse[i]);
    }
    return 0;
}

void align(char *str){
    char buffer[81]="";
    for(int i=0; i<80-strlen(str); i++) strcat(buffer, " ");
    strcat(buffer, str);
    strcpy(str, buffer);
}
