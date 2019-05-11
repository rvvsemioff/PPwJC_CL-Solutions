#include <windows.h>
#include <math.h>
#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define S_COUNT 30
#define M_COUNT 3

struct student{
    char name[15];
    char surname[25];
    float marks[M_COUNT];
};

void generate_data(struct student std[], unsigned char S_N, unsigned char M_N);
void generate_name(char name[], unsigned char N);
double random(unsigned char mult);
void student_list(struct student std[], unsigned char S_N, unsigned char M_N);
void premium_grant(struct student std[], unsigned char S_N, unsigned char M_N);
void grant(struct student std[], unsigned char S_N, unsigned char M_N, char text[], unsigned char check);
unsigned char check_grant(float marks[], unsigned char M_N);

int main(void){
    struct student std[S_COUNT];
    SetConsoleCP(1250);
    SetConsoleOutputCP(1250);
    srand(time(NULL));
    generate_data(std, S_COUNT, M_COUNT);
    student_list(std, S_COUNT, M_COUNT);
    grant(std, S_COUNT, M_COUNT, " podwy¿szon", 2);
    grant(std, S_COUNT, M_COUNT, "e zwyk³", 1);
    return 0;
}

void generate_data(struct student std[], unsigned char S_N, unsigned char M_N){
    for(unsigned char i=0; i<S_N; ++i){
        generate_name(std[i].name, 15);
        generate_name(std[i].surname, 25);
        for(unsigned char j=0; j<M_N; ++j){
            std[i].marks[j]=0.5f*(float)random(6)+2.0f;
            if(std[i].marks[j]==2.5f) std[i].marks[j]=2.0f;
        }
    }
}

void generate_name(char name[], unsigned char N){
    unsigned char l_c=1;
    name[0]=(char)random(25)+'A';
    for(unsigned char i=1; i<(unsigned char)random(N-2); ++i){
        name[i]=(char)random(25)+'a';
        ++l_c;
    }
    name[l_c]='\0';
}

double random(unsigned char mult){
    return round(((double)rand()/RAND_MAX)*mult);
}

void student_list(struct student std[], unsigned char S_N, unsigned char M_N){
    float m_mark;
    printf("Lista studentów:\n\n");
    for(unsigned char i=0; i<S_N; ++i){
        printf("%s %s:\n", std[i].name, std[i].surname);
        m_mark=0;
        for(unsigned char j=0; j<M_N; ++j){
            printf("%0.1f\t", std[i].marks[j]);
            m_mark+=std[i].marks[j];
        }
        printf("\nŒrednia: %0.1f\n\n", m_mark/M_N);
    }
}

void grant(struct student std[], unsigned char S_N, unsigned char M_N, char text[], unsigned char check){
    printf("Lista studentów z%sym stypendium:\n\n", text);
    for(unsigned char i=0; i<S_N; ++i) if(check_grant(std[i].marks, M_N)==check) printf("%s %s\n", std[i].name, std[i].surname);
    puts("");
}

unsigned char check_grant(float marks[], unsigned char M_N){
    unsigned char grant=2;
    for(unsigned char i=0; i<M_N; ++i){
        if(marks[i]<4.0f) return 0;
        else if(marks[i]<5.0f) grant=1;
    }
    return grant;
}
