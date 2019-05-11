#include <windows.h>
#include <stdio.h>

void sort(char input[][4]);

int main(void){
    char input[5][4];
    SetConsoleCP(1250);
    SetConsoleOutputCP(1250);
    puts("WprowadŸ piêæ trzyliterowych wyrazów:");
    puts("");
    for(int i=0; i<5; i++){
        fgets(input[i], 4, stdin);
        fflush(stdin);
    }
    sort(input);
    puts("");
    puts("Wyrazy uporz¹dkowane leksykograficznie uwzglêdniaj¹c pierwsze litery wyrazów:");
    puts("");
    for(int i=0; i<5; i++) puts(input[i]);
    return 0;
}

void sort(char input[][4]){
    char buffer[4]="";
    for(int i=1; i<5; i++){
        for(int j=i; j>0&&input[j-1][0]>input[j][0]; j--){
            strcpy(buffer, input[j-1]);
            strcpy(input[j-1], input[j]);
            strcpy(input[j], buffer);
        }
    }
}
