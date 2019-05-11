#include <windows.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ONE_YEAR 31536000
#define TM_AND_POSIX_YEAR_DIFF 70
#define N 100

struct sweet{
    char vendor[50];
    char name[25];
    float price;
    int count;
    time_t m_date;
    time_t bb_date;
};

void select_info(struct sweet sw[]);
void select_expired(struct sweet sw[]);

int main(void){
    struct sweet sw[N];
    struct tm *tm_today;
    time_t today=86400;
    if(strcmp(asctime(gmtime(&today)), "Fri Jan 02 00:00:00 1970\n")!=0) return 1;
    today=time(NULL);
    tm_today=gmtime(&today);
    SetConsoleCP(1250);
    SetConsoleOutputCP(1250);
    srand(time(NULL));
    for(short i=0; i<N; ++i){
        int l_c=0;
        sw[i].vendor[0]=(char)round(((double)rand()/RAND_MAX)*25)+'A';
        for(char j=1; j<=(char)round(((double)rand()/RAND_MAX)*48); ++j){
            if((char)round(((double)rand()/RAND_MAX)*5)==5 && sw[i].vendor[j-1]!=' ') sw[i].vendor[j]=' ';
            else sw[i].vendor[j]=(char)round(((double)rand()/RAND_MAX)*25)+'a';
            l_c=j;
        }
        sw[i].vendor[l_c+1]='\0';
        l_c=0;
        sw[i].name[0]=(char)round(((double)rand()/RAND_MAX)*25)+'A';
        for(char j=1; j<=(char)round(((double)rand()/RAND_MAX)*23); ++j){
            if((char)round(((double)rand()/RAND_MAX)*5)==5 && sw[i].name[j-1]!=' ') sw[i].name[j]=' ';
            else sw[i].name[j]=(char)round(((double)rand()/RAND_MAX)*25)+'a';
            l_c=j;
        }
        sw[i].name[l_c+1]='\0';
        sw[i].price=roundf(((float)rand()/RAND_MAX)*29.99)+0.01;
        sw[i].count=(int)round(((double)rand()/RAND_MAX)*50000);
        sw[i].m_date=(time_t)round(((double)rand()/RAND_MAX)*ONE_YEAR)+ONE_YEAR*((*tm_today).tm_year-TM_AND_POSIX_YEAR_DIFF);
        sw[i].bb_date=(time_t)round(((double)rand()/RAND_MAX)*ONE_YEAR/(((char)round((double)rand()/RAND_MAX)*9)+1))+sw[i].m_date;
    }
    select_info(sw);
    select_expired(sw);
    return 0;
}

void select_info(struct sweet sw[]){
    float pr_s, pr_e;
    char sel_vendor[50], cmp[51], av=1;
    while(1){
        puts("Wybierz cene od 0.01 do 30.00");
        scanf("%f %f", &pr_s, &pr_e);
        if(pr_s>=0.01f && pr_s<=pr_e && pr_e<=30.0f) break;
        puts("Niew³aœciwe wartoœci!");
    }
    puts("Lista producentów:");
    for(short i=0; i<N; ++i){
        printf("\"%s\"", sw[i].vendor);
        if(i<N-1) printf(", ");
        else printf(".\n");
    }
    puts("Wybierz producenta:");
    fflush(stdin);
    fgets(sel_vendor, 50, stdin);
    puts("");
    for(short i=0; i<N; ++i){
        strcpy(cmp, sw[i].vendor);
        strcat(cmp, "\n");
        if(strcmp(sel_vendor, cmp)==0 && sw[i].price>=pr_s && sw[i].price<=pr_e){
            av=0;
            printf("%s - %0.2f, %d\ndata produkcji: %s", sw[i].name, sw[i].price, sw[i].count, asctime(gmtime(&sw[i].m_date)));
            printf("data przydatnoœci do spo¿ycia: %s\n", asctime(gmtime(&sw[i].bb_date)));
        }
    }
    if(av) puts("Nie znaleziono cukierków wybranego producenta z podan¹ cen¹.");
}

void select_expired(struct sweet sw[]){
    printf("Cukierki, którym skoñczy³ siê termin przydatnoœci do spo¿ycia:\n\n");
    for(short i=0; i<N; ++i) if(sw[i].bb_date<time(NULL)) printf("%s - %d\n", sw[i].name, sw[i].count);
}
