#include <windows.h>
#include <math.h>
#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ONE_YEAR 31536000
#define TM_AND_POSIX_YEAR_DIFF 70
#define COUNT 250
#define RANGE 5

union date{
    short year;
    time_t time;
};

struct person{
    char name[15];
    char surname[25];
};

union authors{
    struct person author;
    struct person council[6];
};

struct article{
    unsigned char type;
    char title[50];
    union date dt;
    union authors athr;
    unsigned char volume;
};

unsigned char check_posix(void);
void generate_data(struct article lib[], unsigned char N);
short define_year(time_t time);
double random(int mult);
void generate_name(char name[], unsigned char N, unsigned char space);
void show(struct article lib[], unsigned char N);

int main(void){
    struct article lib[COUNT];
    if(check_posix()) return 1;
    SetConsoleCP(1250);
    SetConsoleOutputCP(1250);
    srand(time(NULL));
    generate_data(lib, COUNT);
    show(lib, COUNT);
    return 0;
}

unsigned char check_posix(void){
    time_t today=86400;
    if(strcmp(asctime(gmtime(&today)), "Fri Jan 02 00:00:00 1970\n")!=0) return 1;
    return 0;
}

void generate_data(struct article lib[], unsigned char N){
    time_t today_t=time(NULL);
    short today=define_year(today_t);
    for(unsigned char i=0; i<N; ++i){
        lib[i].type=(unsigned char)random(2);
        generate_name(lib[i].title, 50, 1);
        if(lib[i].type==0) lib[i].dt.year=today-(unsigned char)random(RANGE);
        else lib[i].dt.time=today_t-(time_t)random(RANGE*ONE_YEAR);
        if(lib[i].type==2){
            for(unsigned char j=0; j<6; ++j){
                generate_name(lib[i].athr.council[j].name, 15, 0);
                generate_name(lib[i].athr.council[j].surname, 25, 0);
            }
        }
        else{
            generate_name(lib[i].athr.author.name, 15, 0);
            generate_name(lib[i].athr.author.surname, 25, 0);
        }
        lib[i].volume=(unsigned char)random(250)+1;
    }
}

short define_year(time_t time){
    struct tm *tm_today;
    tm_today=gmtime(&time);
    return (short)(*tm_today).tm_year+1900;
}

double random(int mult){
    return round(((double)rand()/RAND_MAX)*mult);
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

void show(struct article lib[], unsigned char N){
    short year, today=define_year(time(NULL));
    printf("Pozycje z danego roku:\n\n");
    for(unsigned char i=0; i<N; ++i){
        if(lib[i].type==0) year=lib[i].dt.year;
        else year=define_year(lib[i].dt.time);
        if(year==today){
            printf("Pozycja: %s\n", lib[i].title);
            if(lib[i].type==0) printf("Rok wydania: %hd\n", year);
            else printf("Data druku: %s", asctime(gmtime(&lib[i].dt.time)));
            switch(lib[i].type){
            case 0:
                printf("Autor: %s %s\n", lib[i].athr.author.name, lib[i].athr.author.surname);
                break;
            case 1:
                printf("Redaktor naczelny: %s %s\n", lib[i].athr.author.name, lib[i].athr.author.surname);
                break;
            default:
                puts("Sk³ad Rady programowej:");
                for(unsigned char j=0; j<6; ++j){
                    printf("\t%s %s\n", lib[i].athr.council[j].name, lib[i].athr.council[j].surname);
                }
            }
            printf("Objêtoœæ: %hhu s.\n\n", lib[i].volume);
        }
    }
}
