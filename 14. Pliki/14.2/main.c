#include <windows.h>
#include <limits.h>
#include <math.h>
#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define COUNT 5

struct worker{
    char name[10];
    char surname[20];
    unsigned char hour_count;
    long salary;
    float premium;
    long payment;
};

long input(char str[], unsigned char bottom, long top);
void generate_data(struct worker wrk[], unsigned char N);
void generate_name(char name[], unsigned char N);
double random(long mult);
void print_data(struct worker wrk[], unsigned char N);
void save_data(struct worker wrk[], unsigned char N);
void print_selected_data(struct worker wrk[], unsigned char N);

int main(void){
    struct worker wrk[COUNT];
    unsigned char is_gen=0;
    SetConsoleCP(1250);
    SetConsoleOutputCP(1250);
    while(1){
        switch(input("Wygeneruj (1), zapisz (2) lub odczytaj (3) dane, wyœwietl dane pracowników o podanej kwocie (4) lub wyjdŸ (5)", 0, 6)){
        case 1:
            generate_data(wrk, COUNT);
            is_gen=1;
            puts("Wygenerowano dane:\n");
            print_data(wrk, COUNT);
            break;
        case 2:
            if(is_gen){
                save_data(wrk, COUNT);
                puts("Dane zapisane do pliku");
            }
            else puts("Nie wygenerowano danych do zapisu!");
            break;
        case 3:
            read_data(wrk, COUNT);
            puts("Dane odczytane z pliku:\n");
            print_data(wrk, COUNT);
            break;
        case 4:
            if(is_gen) print_selected_data(wrk, COUNT);
            else puts("Nie ma danych do wyœwietlania!");
            break;
        default:
            return 0;
        }
    }
}

long input(char str[], unsigned char bottom, long top){
    long input_val;
    while(1){
        printf("%s: ", str);
        fflush(stdin);
        scanf("%ld", &input_val);
        if(input_val>bottom && input_val<top) return input_val;
        puts("Niew³aœciwa wartoœæ!");
    }
}

void generate_data(struct worker wrk[], unsigned char N){
    srand(time(NULL));
    for(unsigned char i=0; i<N; ++i){
        generate_name(wrk[i].name, 10);
        generate_name(wrk[i].surname, 20);
        wrk[i].hour_count=(unsigned char)random(11)+1;
        wrk[i].salary=(long)random(300000)+1;
        wrk[i].premium=random(100)/100;
        wrk[i].payment=wrk[i].salary*(1+wrk[i].premium);
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

double random(long mult){
    return round(((double)rand()/RAND_MAX)*mult);
}

void print_data(struct worker wrk[], unsigned char N){
    for(unsigned char i=0; i<N; ++i){
        printf("pracownik: %s %s\n"
               "\tliczba godzin: %hhu\n"
               "\tstawka: %ld\n"
               "\tpremia: %0.0f\%\n"
               "\tdo wyp³aty: %ld\n",
               wrk[i].name, wrk[i].surname,
               wrk[i].hour_count, wrk[i].salary, 100*wrk[i].premium, wrk[i].payment);
    }
    puts("");
}

void save_data(struct worker wrk[], unsigned char N){
    FILE *f_p=fopen("data.txt", "w");
    if(f_p==NULL) return 2;
    fwrite(wrk, sizeof(struct worker), N, f_p);
    if(fclose(f_p)==EOF) return 3;
}

void read_data(struct worker wrk[], unsigned char N){
    FILE *f_p=fopen("data.txt", "r");
    if(f_p==NULL) return 2;
    fread(wrk, sizeof(struct worker), N, f_p);
    if(fclose(f_p)==EOF) return 3;
}

void print_selected_data(struct worker wrk[], unsigned char N){
    unsigned char is_av=0;
    long sel_v=input("WprowadŸ graniczn¹ wartoœæ kwoty do wyp³aty", 0, LONG_MAX);
    for(unsigned char i=0; i<N; ++i){
        if(wrk[i].payment>sel_v){
            if(is_av==0){
                is_av=1;
                puts("Dane pracowników, których kwota do wyp³aty przekracza podan¹ wartoœæ:\n");
            }
            printf("pracownik: %s %s\n"
               "\tliczba godzin: %hhu\n"
               "\tstawka: %ld\n"
               "\tpremia: %0.0f\%\n"
               "\tdo wyp³aty: %ld\n",
               wrk[i].name, wrk[i].surname,
               wrk[i].hour_count, wrk[i].salary, 100*wrk[i].premium, wrk[i].payment);
        }
    }
    if(is_av){
        puts("");
        return;
    }
    puts("Nie znaleziono pracowników, których kwota do wyp³aty przekracza podan¹ wartoœæ.");
}
