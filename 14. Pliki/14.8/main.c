#include <windows.h>
#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdlib.h>

void read(char name[], char file[], unsigned char step);
void write(char file[]);

int main(void){
    char file[10000], full_name[55]="read\\", name[50];
    SetConsoleCP(1250);
    SetConsoleOutputCP(1250);
    printf("WprowadŸ pe³n¹ nazwê pliku do odczytania: ");
    scanf("%s", &name);
    strcat(full_name, name);
    read(full_name, file, 3);
    write(file);
    read(full_name, file, 1);
    puts("Zawartoœæ pliku Ÿród³owego:\n\n");
    printf("%s\n\n\n", file);
    read("res.fl", file, 1);
    puts("Zawartoœæ pliku wynikowego:\n\n");
    printf("%s\n\n\n", file);
    return EXIT_SUCCESS;
}

void read(char name[], char file[], unsigned char step){
    short i;
    FILE *f_p=fopen(name, "r");
    if(f_p==NULL){
        puts("Plik nie istnieje");
        exit(1);
    }
    --step;
    for(i=0; !feof(f_p); ++i){
        fseek(f_p, step, SEEK_CUR);
        file[i]=fgetc(f_p);
    }
    file[i]='\0';
    if(fclose(f_p)==EOF) exit(2);
}

void write(char file[]){
    FILE *f_p=fopen("res.fl", "w");
    if(f_p==NULL) exit(1);
    fprintf(f_p, "%s", file);
    if(fclose(f_p)==EOF) exit(2);
}
