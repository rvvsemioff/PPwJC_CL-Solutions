#include <windows.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100

struct student{
    char name[15];
    char surname[25];
    float marks[5];
};

float std_mean(struct student std[], short id);
float std_all_mean(struct student std[]);

int main(void){
    struct student std[N];
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
        for(short j=1; j<(short)round(((double)rand()/RAND_MAX)*23); ++j){
            std[i].surname[j]=(char)round(((double)rand()/RAND_MAX)*25)+'a';
            l_c=j;
        }
        std[i].surname[l_c+1]='\0';
        for(char j=0; j<5; ++j){
            std[i].marks[j]=roundf(((float)rand()/RAND_MAX)*7)*0.5+2;
            if(std[i].marks[j]==2.5) std[i].marks[j]=2.0;
        }
    }
    for(short i=0; i<N; ++i) printf("%s %s - %0.1f\n", std[i].name, std[i].surname, std_mean(std, i));
    printf("\nŒrednia ocen grupy - %0.1f\n", std_all_mean(std));
    return 0;
}

float std_mean(struct student std[], short id){
    float mean=0.0;
    for(char i=0; i<5; ++i) mean+=std[id].marks[i];
    return mean/5.0;
}

float std_all_mean(struct student std[]){
    float mean=0.0;
    for(short i=0; i<N; ++i) mean+=std_mean(std, i);
    return mean/N;
}
