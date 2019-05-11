#include <windows.h>
#include <math.h>
#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct worker{
    char name[15];
    char surname[25];
    unsigned char age;
    short year;
    int salary;
    unsigned char department;
};

unsigned char check_posix(void);
int input(char str[], int bottom, int top);
void data_input(struct worker corp[], unsigned char N);
short define_year(time_t time);
void generate_data(struct worker corp[], unsigned char N);
void generate_name(char name[], unsigned char N);
double random(int mult);
void problem_a(struct worker corp[], unsigned char N, int *la_i, int *ma_i, int *le_i, int *me_i);
void problem_a_check(int pos, int *l_pos, int *m_pos, unsigned char i, int *l_i, int *m_i);
void problem_b(struct worker corp[], unsigned char N);
void problem_c(struct worker corp[], unsigned char N, int *la_i, int *ma_i, int *le_i, int *me_i);
void problem_d(struct worker corp[], unsigned char N);

int main(void){
    unsigned char N, ch;
    int la_i, ma_i, le_i, me_i;
    if(check_posix()) return 1;
    SetConsoleCP(1250);
    SetConsoleOutputCP(1250);
    N=(unsigned char)input("WprowadŸ liczbê pracowników", 0, 256);
    struct worker corp[N];
    ch=(unsigned char)input("WprowadŸ dane rêcznie (1) lub uruchom generator danych (2)", 0, 3);
    if(ch==1) data_input(corp, N);
    else generate_data(corp, N);
    problem_a(corp, N, &la_i, &ma_i, &le_i, &me_i);
    problem_b(corp, N);
    problem_a(corp, N, &la_i, &ma_i, &le_i, &me_i);
    problem_c(corp, N, &la_i, &ma_i, &le_i, &me_i);
    problem_d(corp, N);
    return 0;
}

unsigned char check_posix(void){
    time_t today=86400;
    if(strcmp(asctime(gmtime(&today)), "Fri Jan 02 00:00:00 1970\n")!=0) return 1;
    return 0;
}

int input(char str[], int bottom, int top){
    int input_val;
    while(1){
        printf("%s: ", str);
        fflush(stdin);
        scanf("%d", &input_val);
        if(input_val>bottom && input_val<top) return input_val;
        puts("Niew³aœciwa wartoœæ!");
    }
}

void data_input(struct worker corp[], unsigned char N){
    short t_year=define_year(time(NULL))+1, w_year;
    for(unsigned char i=0; i<N; ++i){
        printf("WprowadŸ imiê: ");
        fflush(stdin);
        scanf("%s", &corp[i].name);
        printf("WprowadŸ nazwisko: ");
        fflush(stdin);
        scanf("%s", &corp[i].surname);
        corp[i].age=(unsigned char)input("WprowadŸ wiek", 17, 121);
        w_year=t_year-corp[i].age+16;
        corp[i].year=(short)input("WprowadŸ rok zatrudnienia", w_year, t_year);
        corp[i].salary=input("WprowadŸ wysokoœæ pensji netto", 0, 1000001);
        corp[i].department=(unsigned char)input("WprowadŸ numer dzia³u firmy (1-3)", 0, 4);
        puts("");
    }
}

short define_year(time_t time){
    struct tm *tm_today;
    tm_today=gmtime(&time);
    return (short)(*tm_today).tm_year+1900;
}

void generate_data(struct worker corp[], unsigned char N){
    short t_year=define_year(time(NULL)), w_year;
    srand(time(NULL));
    for(unsigned char i=0; i<N; ++i){
        generate_name(corp[i].name, 15);
        generate_name(corp[i].surname, 25);
        corp[i].age=(unsigned char)random(102)+18;
        w_year=t_year-corp[i].age+18;
        corp[i].year=(short)random(t_year-w_year)+w_year;
        corp[i].salary=random(999999)+1;
        corp[i].department=(unsigned char)random(2)+1;
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

double random(int mult){
    return round(((double)rand()/RAND_MAX)*mult);
}

void problem_a(struct worker corp[], unsigned char N, int *la_i, int *ma_i, int *le_i, int *me_i){
    int l_age=120, m_age=18, l_empl=1951, m_empl=define_year(time(NULL)), l_salary=1000000, m_salary=1, ls_i, ms_i;
    for(unsigned char i=0; i<N; ++i){
        problem_a_check(corp[i].age, &l_age, &m_age, i, la_i, ma_i);
        problem_a_check(corp[i].year, &m_empl, &l_empl, i, me_i, le_i);
        problem_a_check(corp[i].salary, &l_salary, &m_salary, i, &ls_i, &ms_i);
    }
    printf("Zagadnienie A:\n\n"
           "%s %s ma najni¿sz¹ pensjê.\n"
           "%s %s ma najwy¿sz¹ pensjê.\n"
           "%s %s jest zatrudniony najd³u¿ej.\n"
           "%s %s jest zatrudniony najkrócej.\n"
           "%s %s jest najstarszy.\n"
           "%s %s jest najm³odszy.\n\n"
           , corp[ls_i].name, corp[ls_i].surname
           , corp[ms_i].name, corp[ms_i].surname
           , corp[*me_i].name, corp[*me_i].surname
           , corp[*le_i].name, corp[*le_i].surname
           , corp[*ma_i].name, corp[*ma_i].surname
           , corp[*la_i].name, corp[*la_i].surname);
}

void problem_a_check(int pos, int *l_pos, int *m_pos, unsigned char i, int *l_i, int *m_i){
    if(pos<*l_pos){
        *l_pos=pos;
        *l_i=i;
    }
    if(pos>*m_pos){
        *m_pos=pos;
        *m_i=i;
    }
}

void problem_b(struct worker corp[], unsigned char N){
    short t_year=define_year(time(NULL)), w_years;
    printf("Zagadnienie B;\n\n");
    for(unsigned char i=0; i<N; ++i){
        w_years=t_year-corp[i].year;
        if(w_years>=5){
            if(w_years<10) corp[i].salary*=1.1;
            else if(w_years<20) corp[i].salary*=1.2;
            else corp[i].salary*=1.25;
        }
    }
}

void problem_c(struct worker corp[], unsigned char N, int *la_i, int *ma_i, int *le_i, int *me_i){
    printf("Zagadnienie C:\n\n"
           "Najm³odszy pracownik ");
    if(*la_i!=*me_i) printf("nie ");
    printf("jest zatrudniony najd³u¿ej.\n"
           "Najstarszy pracownik ");
    if(*ma_i!=*le_i) printf("nie ");
    puts("jest zatrudniony najkrócej.\n");
}

void problem_d(struct worker corp[], unsigned char N){
    unsigned char count[3]={0, 0, 0};
    short a_age[3]={0, 0, 0}, a_empl[3]={0, 0, 0}, t_year=define_year(time(NULL));
    long a_salary[4]={0, 0, 0, 0};
    char dep[3][13]={"Ksiêgowoœæ", "Produkcja", "Kierownictwo"};
    for(unsigned char i=0; i<3; ++i){
        for(unsigned char j=0; j<N; ++j){
            if(corp[j].department==i+1){
                a_age[i]+=corp[j].age;
                a_empl[i]+=t_year-corp[j].year;
                a_salary[i]+=corp[j].salary;
                ++count[i];
            }
        }
        if(count[i]!=0){
            a_age[i]/=count[i];
            a_empl[i]/=count[i];
            a_salary[i]/=count[i];
        }
    }
    a_salary[3]=(a_salary[0]+a_salary[1]+a_salary[2])/3;
    puts("Zagadnienie D:\n\n"
         "Œredni wiek pracowników w dzia³e:");
    for(unsigned char i=0; i<3; ++i) printf("\t%s - %hd\n", dep[i], a_age[i]);
    puts("Œredni sta¿ pracowników w dzia³e:");
    for(unsigned char i=0; i<3; ++i) printf("\t%s - %hd\n", dep[i], a_empl[i]);
    puts("Iloœæ pracowników w dzia³e:");
    for(unsigned char i=0; i<3; ++i) printf("\t%s - %hhu\n", dep[i], count[i]);
    puts("Wielkoœæ œredniej pensji w dzia³e:");
    for(unsigned char i=0; i<3; ++i) printf("\t%s - %ld\n", dep[i], a_salary[i]);
    printf("Wielkoœæ œredniej pensji w ca³ej firmie - %ld", a_salary[3]);
}
