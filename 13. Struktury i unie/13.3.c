#include <windows.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
#define N 100

struct vacation{
    char place[25];
    char month;
    char day;
};

union award{
    long payment;
    struct vacation vac;
    char letter[50];
};

struct employee{
    char name[15];
    char surname[25];
    char type;
    union award aw;
};

void feed_data(struct employee employees[]);
void show_awards(struct employee employees[]);

int main(void){
    struct employee employees[N];
    SetConsoleCP(1250);
    SetConsoleOutputCP(1250);
    srand(time(NULL));
    for(int i=0; i<N; ++i){
        int l_c=0;
        employees[i].name[0]=(char)round(((double)rand()/RAND_MAX)*25)+'A';
        for(short j=1; j<=(short)round(((double)rand()/RAND_MAX)*13); ++j){
            employees[i].name[j]=(char)round(((double)rand()/RAND_MAX)*25)+'a';
            l_c=j;
        }
        employees[i].name[l_c+1]='\0';
        employees[i].surname[0]=(char)round(((double)rand()/RAND_MAX)*25)+'A';
        l_c=0;
        for(short j=1; j<=(short)round(((double)rand()/RAND_MAX)*23); ++j){
            employees[i].surname[j]=(char)round(((double)rand()/RAND_MAX)*25)+'a';
            l_c=j;
        }
        employees[i].surname[l_c+1]='\0';
    }
    feed_data(employees);
    show_awards(employees);
    return 0;
}

void feed_data(struct employee employees[]){
    for(int i=0; i<N; ++i){
        int l_c=0;
        employees[i].type=(char)round(((double)rand()/RAND_MAX)*2);
        switch(employees[i].type){
        case 0:
            employees[i].aw.payment=(long)round(((double)rand()/RAND_MAX)*100000);
            break;
        case 1:
            employees[i].aw.vac.place[0]=(char)round(((double)rand()/RAND_MAX)*25)+'A';
            for(short j=1; j<=(short)round(((double)rand()/RAND_MAX)*23); ++j){
                employees[i].aw.vac.place[j]=(char)round(((double)rand()/RAND_MAX)*25)+'a';
                l_c=j;
            }
            employees[i].aw.vac.place[l_c+1]='\0';
            employees[i].aw.vac.month=(char)round(((double)rand()/RAND_MAX)*11)+1;
            employees[i].aw.vac.day=(char)round(((double)rand()/RAND_MAX)*30)+1;
            break;
        case 2:
            employees[i].aw.letter[0]=(char)round(((double)rand()/RAND_MAX)*25)+'A';
            for(short j=1; j<=(short)round(((double)rand()/RAND_MAX)*29)+20; ++j){
                if((char)round(((double)rand()/RAND_MAX)*5)==5) employees[i].aw.letter[j]=' ';
                else employees[i].aw.letter[j]=(char)round(((double)rand()/RAND_MAX)*25)+'a';
                l_c=j;
            }
            employees[i].aw.letter[l_c+1]='\0';
        }
    }
}

void show_awards(struct employee employees[]){
    for(int i=0; i<N; ++i){
        printf("%s %s - ", employees[i].name, employees[i].surname);
        switch(employees[i].type){
        case 0:
            printf("kwota pieniê¿na: %ld\n", employees[i].aw.payment);
            break;
        case 1:
            printf("wycieczka do %s w dniu %d.%d\n", employees[i].aw.vac.place, employees[i].aw.vac.day, employees[i].aw.vac.month);
            break;
        case 2:
            printf("list pochwalny:\n%s\n", employees[i].aw.letter);
        }
    }
}
