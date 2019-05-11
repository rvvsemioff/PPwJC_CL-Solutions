#include <windows.h>
#include <stdio.h>
#include <time.h>
#define SIZE 100

struct worker{
    char name[15];
    char surname[25];
    char hour_count;
    long salary;
    float bonus;
};

void show_payment(struct worker wrk[]);
void show_most_payed(struct worker wrk[]);

int main(void){
    struct worker wrk[SIZE];
    SetConsoleCP(1250);
    SetConsoleOutputCP(1250);
    srand(time(NULL));
    for(int i=0; i<SIZE; ++i){
        int l_c=0;
        wrk[i].name[0]=(char)(((double)rand()/RAND_MAX)*25)+'A';
        for(short j=1; j<=(short)(((double)rand()/RAND_MAX)*13); ++j){
            wrk[i].name[j]=(char)(((double)rand()/RAND_MAX)*25)+'a';
            l_c=j;
        }
        wrk[i].name[l_c+1]='\0';
        wrk[i].surname[0]=(char)(((double)rand()/RAND_MAX)*25)+'A';
        l_c=0;
        for(short j=1; j<=(short)(((double)rand()/RAND_MAX)*23); ++j){
            wrk[i].surname[j]=(char)(((double)rand()/RAND_MAX)*25)+'a';
            l_c=j;
        }
        wrk[i].surname[l_c+1]='\0';
        wrk[i].hour_count=(char)(((double)rand()/RAND_MAX)*12);
        wrk[i].salary=(long)(((double)rand()/RAND_MAX)*100000);
        wrk[i].bonus=(double)rand()/RAND_MAX;
    }
    show_payment(wrk);
    show_most_payed(wrk);
    return 0;
}

void show_payment(struct worker wrk[]){
    long ipay, spay=0;
    for(int i=0; i<SIZE; ++i){
        ipay=wrk[i].hour_count*wrk[i].salary*(1+wrk[i].bonus);
        printf("%s %s - %ld\n", wrk[i].name, wrk[i].surname, ipay);
        spay+=ipay;
    }
    printf("\nSumaryczna kwota - %ld\n", spay);
}

void show_most_payed(struct worker wrk[]){
    char m_pay[5]={0, 0, 0, 0, 0};
    long i_pay[SIZE];
    for(int i=1; i<SIZE; ++i){
        i_pay[i]=wrk[i].hour_count*wrk[i].salary*(1+wrk[i].bonus);
        for(short j=0; j<5; ++j){
            if(i_pay[m_pay[j]]<i_pay[i]){
                m_pay[j]=i;
                j=5;
            }
        }
    }
    puts("");
    puts("Osoby zarabiaj¹ce najwiêcej:");
    puts("");
    for(short i=0; i<5; ++i) printf("%s - %ld\n", wrk[m_pay[i]].surname, i_pay[m_pay[i]]);
}
