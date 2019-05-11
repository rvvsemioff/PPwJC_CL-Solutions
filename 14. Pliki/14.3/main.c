#include <windows.h>
#include <math.h>
#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

unsigned char check_posix(void);
unsigned char input(char str[], unsigned char bottom, unsigned char top);
void generate_data(struct book library[], unsigned char N);
short define_year(time_t time);
void generate_name(char name[], unsigned char N, unsigned char space);
double random(long mult);
void write_data(struct book library[], unsigned char N);
unsigned char read_data(struct book library[]);

int main(void){
    unsigned char is_gen=0, count, r_count;
    if(check_posix()) return 1;
    SetConsoleCP(1250);
    SetConsoleOutputCP(1250);
    r_count=input("WprowadŸ liczbê pozycji", 0, 255);
    struct book library[255];
    while(1){
        switch(input("Wygeneruj (1), zapisz (2) lub odczytaj (3) dane, wyœwietl tytu³y podanego autora (4) lub wyjdŸ (5)", 0, 6)){
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

unsigned char check_posix(void){
    time_t today=86400;
    if(strcmp(asctime(gmtime(&today)), "Fri Jan 02 00:00:00 1970\n")!=0) return 1;
    return 0;
}

unsigned char input(char str[], unsigned char bottom, unsigned char top){
    unsigned char input_val;
    while(1){
        printf("%s: ", str);
        fflush(stdin);
        scanf("%hhu", &input_val);
        if(input_val>bottom && input_val<top) return input_val;
        puts("Niew³aœciwa wartoœæ!");
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

short define_year(time_t time){
    struct tm *tm_today;
    tm_today=gmtime(&time);
    return (short)(*tm_today).tm_year+1900;
}

void generate_name(char name[], unsigned char N, unsigned char space){
    unsigned char l_c=1;
    name[0]=(char)random(25)+'A';
    for(unsigned char i=1; i<(unsigned char)random(N-2); ++i){
        if(space && name[i-1]!=' ' && (unsigned char)random(5)==4) name[i]=' ';
        else name[i]=(char)random(25)+'a';
        ++l_c;
    }
    name[l_c]='\0';
}

double random(long mult){
    return round(((double)rand()/RAND_MAX)*mult);
}

void print_data(struct book library[], unsigned char N){
    for(unsigned char i=0; i<N; ++i){
        printf("tytu³ - %s\n"
               "rok wydania - %hd\n"
               "autor - %s %s\n"
               "objêtoœæ - %ld\n\n", library[i].title, library[i].year, library[i].auth.name, library[i].auth.surname, library[i].volume);
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
    printf("WprowadŸ imiê i nazwisko autora: ");
    scanf("%s %s", s_name, s_surname);
    puts("");
    for(unsigned char i=0; i<N; ++i){
        if(strcmp(library[i].auth.name, s_name)==0 && strcmp(library[i].auth.surname, s_surname)==0){
            is_f=1;
            printf("tytu³ - %s\n"
               "rok wydania - %hd\n"
               "autor - %s %s\n"
               "objêtoœæ - %ld\n\n", library[i].title, library[i].year, library[i].auth.name, library[i].auth.surname, library[i].volume);
        }
    }
    if(is_f==0) puts("Nie znaleziono pozycji podanego autora");
 }
