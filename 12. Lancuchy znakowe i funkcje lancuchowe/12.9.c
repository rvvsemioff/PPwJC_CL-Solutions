#include <windows.h>
#include <stdio.h>

void caesar(char *str);

int main(void){
    char input[100][81];
    SetConsoleCP(1250);
    SetConsoleOutputCP(1250);
    for(int i=0; i<100; i++){
        puts("WprowadŸ napis:");
        fgets(input[i], 80, stdin);
        if(!strcmp(input[i], "quit\n")) break;
    }
    puts("");
    puts("Napisy zaszyfrowane szyfrem Cezara");
    puts("");
    for(int i=0; i<100; i++){
        if(!strcmp(input[i], "quit\n")) break;
        caesar(input[i]);
        puts(input[i]);
    }
    return 0;
}

void caesar(char *str){
    for(int i=0; i<strlen(str)-1; i++){
        if(str[i]>64&&str[i]<91){
            str[i]-=3;
            if(str[i]<65) str[i]+=26;
        }
        else if(str[i]>96&&str[i]<123){
            str[i]-=3;
            if(str[i]<97) str[i]+=26;
        }
    }
}
