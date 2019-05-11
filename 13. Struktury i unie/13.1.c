#include <windows.h>
#include <stdio.h>

struct worker{
    char name[15];
    char surname[25];
    char hour_count;
    int salary;
    float bonus;
};

struct worker read(void);
void p_read(struct worker *wrk);
float count(struct worker wrk);
float p_count(struct worker *wrk);
void write(struct worker wrk);
void p_write(struct worker *wrk);

int main(void){
    struct worker wrk1, wrk2;
    SetConsoleCP(1250);
    SetConsoleOutputCP(1250);
    wrk1=read();
    printf("P³aca pierwszego pracownika: %.2f\n", count(wrk1));
    write(wrk1);
    p_read(&wrk2);
    printf("P³aca drugiego pracownika: %f.2\n", p_count(&wrk2));
    p_write(&wrk2);
    return 0;
}

struct worker read(void){
    struct worker wrk;
    printf("WprowadŸ imie pracownika: ");
    scanf("%s", &wrk.name);
    printf("WprowadŸ nazwisko pracownika: ");
    scanf("%s", &wrk.surname);
    printf("WprowadŸ liczbê godzin pracownika: ");
    scanf("%d", &wrk.hour_count);
    printf("WprowadŸ stawkê pracownika: ");
    scanf("%d", &wrk.salary);
    printf("WprowadŸ premiê pracownika: ");
    scanf("%f", &wrk.bonus);
    return wrk;
}

void p_read(struct worker *wrk){
    printf("WprowadŸ imie pracownika: ");
    scanf("%s", wrk->name);
    printf("WprowadŸ nazwisko pracownika: ");
    scanf("%s", wrk->surname);
    printf("WprowadŸ liczbê godzin pracownika: ");
    scanf("%d", &wrk->hour_count);
    printf("WprowadŸ stawkê pracownika: ");
    scanf("%d", &wrk->salary);
    printf("WprowadŸ premiê pracownika: ");
    scanf("%f", &wrk->bonus);
}

float count(struct worker wrk){
    return wrk.hour_count*wrk.salary*(1+wrk.bonus);
}

float p_count(struct worker *wrk){
    return wrk->hour_count*wrk->salary*(1+wrk->bonus);
}

void write(struct worker wrk){
    puts("Dane pracownika:");
    printf("\timie: %s\n\tnazwisko: %s\n\tliczba godzin: %d\n\tstawka: %d\n\tpremia: %.2f\n", wrk.name, wrk.surname, wrk.hour_count, wrk.salary, wrk.bonus);
}

void p_write(struct worker *wrk){
    puts("Dane pracownika:");
    printf("\timie: %s\n\tnazwisko: %s\n\tliczba godzin: %d\n\tstawka: %d\n\tpremia: %.2f\n", wrk->name, wrk->surname, wrk->hour_count, wrk->salary, wrk->bonus);
}
