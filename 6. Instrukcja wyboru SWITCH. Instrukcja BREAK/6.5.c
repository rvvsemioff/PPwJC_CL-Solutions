#include <stdio.h>

enum tydzien{poniedzialek,wtorek,sroda,czwartek,piatek,sobota,niedziela};

void plan(enum tydzien d);

int main(void){
    int d;
    printf("Podaj numer dnia tygodnia: ");
    scanf("%d",&d);
    d--;
    plan(d);
    return 0;
}

void plan(enum tydzien d){
    switch(d){
        case poniedzialek: printf("Poniedzialek - zakup okien.");
            return;
        case wtorek: printf("Wtorek - mycie okien.");
            return;
        case sroda: printf("Sroda - budowanie scian.");
            return;
        case czwartek: printf("Czwartek - ustawienie drzwi.");
            return;
        case piatek: printf("Piatek - mycie psow.");
            return;
        case sobota: printf("Sobota - wyczieczki z psami.");
            return;
        case niedziela: printf("Niedziela - praca od switu do zmierzchu.");
            return;
        default: printf("Niewlasciwy wybor.");
    }
}
