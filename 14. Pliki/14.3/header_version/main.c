#include "data_input.h"

struct author{
    char name[15];
    char surname[25];
};

struct book{
    char title[25];
    short year;
    struct author auth;
    long volume;
};

void generate_data(struct book library[], unsigned char N);
void write_data(struct book library[], unsigned char N);
unsigned char read_data(struct book library[]);

int main(void){
    unsigned char is_gen=0, count, r_count;
    if(check_posix()) return 1;
    SetConsoleCP(1250);
    SetConsoleOutputCP(1250);
    r_count=input("Wprowadü liczbÍ pozycji", 0, 255);
    struct book library[255];
    while(1){
        switch(input("Wygeneruj (1), zapisz (2) lub odczytaj (3) dane, wyúwietl tytu≥y podanego autora (4) lub wyjdü (5)", 0, 6)){
        case 1:
            count=r_count;
            generate_data(library, count);
            is_gen=1;
            puts("Wygenerowano dane:\n");
            print_data(library, count);
            break;
        case 2:
            if(is_gen){
                write_data(library, count);
                puts("Zapisano dane");
            }
            else puts("Nie ma danych do zapisu");
            break;
        case 3:
            count=read_data(library);
            is_gen=1;
            puts("Odczytano dane:\n");
            print_data(library, count);
            break;
        case 4:
            if(is_gen) select_author(library, count);
            else puts("Nie ma danych do odczytu");
            break;
        default:
            return 0;
        }
    }
}

void generate_data(struct book library[], unsigned char N){
    short today=define_year(time(NULL));
    srand(time(NULL));
    for(unsigned char i=0; i<N; ++i){
        generate_name(library[i].title, 25, 1);
        library[i].year=today-(short)random(25);
        generate_name(library[i].auth.name, 15, 0);
        generate_name(library[i].auth.surname, 25, 0);
        library[i].volume=(long)random(2000);
    }
}

void print_data(struct book library[], unsigned char N){
    for(unsigned char i=0; i<N; ++i){
        printf("tytu≥ - %s\n"
               "rok wydania - %hd\n"
               "autor - %s %s\n"
               "objÍtoúÊ - %ld\n\n", library[i].title, library[i].year, library[i].auth.name, library[i].auth.surname, library[i].volume);
    }
}

void write_data(struct book library[], unsigned char N){
    FILE *f_p=fopen("data.ini", "w");
    if(f_p==NULL) exit(2);
    for(unsigned char i=0; i<N; ++i) fprintf(f_p, "%s-\t%hd\t%s\t%s\t%ld*", library[i].title, library[i].year, library[i].auth.name, library[i].auth.surname, library[i].volume);
    if(fclose(f_p)==EOF) exit(3);
 }

unsigned char read_data(struct book library[]){
    FILE *f_p=fopen("data.ini", "r");
    unsigned char count=0;
    char buffer[25];
    if(f_p==NULL) exit(2);
    for(unsigned char i=0; ; ++i){
        for(unsigned char j=0; j<25; ++j){
            buffer[j]=fgetc(f_p);
            if(feof(f_p)) return count;
            if(buffer[j]=='-'){
                buffer[j]='\0';
                break;
            }
        }
        strcpy(library[i].title, buffer);
        fscanf(f_p, "%hd\t%s\t%s\t%ld*", &library[i].year, &library[i].auth.name, &library[i].auth.surname, &library[i].volume);
        ++count;
    }
    if(fclose(f_p)==EOF) exit(3);
 }

 void select_author(struct book library[], unsigned char N){
    char s_name[15], s_surname[25];
    unsigned char is_f=0;
    printf("Wprowadü imiÍ i nazwisko autora: ");
    scanf("%s %s", s_name, s_surname);
    puts("");
    for(unsigned char i=0; i<N; ++i){
        if(strcmp(library[i].auth.name, s_name)==0 && strcmp(library[i].auth.surname, s_surname)==0){
            is_f=1;
            printf("tytu≥ - %s\n"
               "rok wydania - %hd\n"
               "autor - %s %s\n"
               "objÍtoúÊ - %ld\n\n", library[i].title, library[i].year, library[i].auth.name, library[i].auth.surname, library[i].volume);
        }
    }
    if(is_f==0) puts("Nie znaleziono pozycji podanego autora");
 }
