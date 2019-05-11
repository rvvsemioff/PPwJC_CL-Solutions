#include <windows.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100

int main(void){
    struct student{
        char name[15];
        char surname[25];
        short lucky_number;
    };
    struct student std[N];
    short c;
    int mid=0;
    SetConsoleCP(1250);
    SetConsoleOutputCP(1250);
    srand(time(NULL));
    for(short i=0; i<N; ++i){
        char l_c=0;
        std[i].name[0]=(char)round(((double)rand()/RAND_MAX)*25)+'A';
        for(short j=1; j<(short)round(((double)rand()/RAND_MAX)*13); ++j){
            std[i].name[j]=(char)round(((double)rand()/RAND_MAX)*25)+'a';
            l_c=j;
        }
        std[i].name[l_c+1]='\0';
        l_c=0;
        std[i].surname[0]=(char)round(((double)rand()/RAND_MAX)*25)+'A';
        for(short j=1; j<(short)round(((double)rand()/RAND_MAX)*13); ++j){
            std[i].surname[j]=(char)round(((double)rand()/RAND_MAX)*25)+'a';
            l_c=j;
        }
        std[i].surname[l_c+1]='\0';
        std[i].lucky_number=(short)round(((double)rand()/RAND_MAX)*1000);
    }
    for(int i=0; i<N; ++i) printf("%s %s - %hd\n", std[i].name, std[i].surname, std[i].lucky_number);
    puts("");
    puts("Osoba/osoby z najwiêkszym numerkiem:");
    puts("");
    c=std[0].lucky_number;
    for(short i=1; i<N; ++i) if(std[i].lucky_number>c) c=std[i].lucky_number;
    for(short i=0; i<N; ++i) if(std[i].lucky_number==c) printf("%s %s - %hd\n", std[i].name, std[i].surname, c);
    puts("");
    puts("Osoba/osoby, której numerek jest najbli¿szy œredniej wylosowanych liczb:");
    puts("");
    for(short i=0; i<N; ++i) mid+=std[i].lucky_number;
    mid/=N;
    c=abs(mid-std[0].lucky_number);
    for(short i=1; i<N; ++i) if(abs(mid-std[i].lucky_number)<c) c=abs(mid-std[i].lucky_number);
    for(short i=0; i<N; ++i) if(abs(mid-std[i].lucky_number)==c) printf("%s %s - %hd\n", std[i].name, std[i].surname, std[i].lucky_number);
    return 0;
}
