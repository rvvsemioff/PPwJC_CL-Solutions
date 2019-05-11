#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

enum figures{kwadrat,prostokat,kolo,trojkat};
enum colors{czerwony,pomaranczowy,zolty,zielony,niebieski,blekitny,fioletowy};

void show(enum figures f, enum colors c);
double square(double a);
double rectangle(double a, double b);
double circle(double r);
double triangle(double a, double h);

int main(void){
    int f,c;
    printf("Wybierz figure:\n0 kwadrat\n1 prostokat\n2 kolo\n3 trojkat\n");
    scanf("%d",&f);
    printf("Wybierz kolor:\n0 czerwony\n1 pomaranczowy\n2 zolty\n3 zielony\n4 niebieski\n5 blekitny\n6 fioletowy\n");
    scanf("%d",&c);
    show(f,c);
    return 0;
}

void show(enum figures f, enum colors c){
    char name[10];
    char color[13];
    double a, area;
    switch(f){
        case kwadrat: strcpy(name,"kwadrat");
            printf("Podaj strone kwadratu: ");
            scanf("%lf",&a);
            area=square(a);
            break;
        case prostokat: strcpy(name,"prostokat");
            double b;
            printf("Podaj dwie strony prostokata: ");
            scanf("%lf%lf",&a,&b);
            area=rectangle(a,b);
            break;
        case kolo: strcpy(name,"kolo");
            printf("Podaj radius kola: ");
            scanf("%lf",&a);
            area=circle(a);
            break;
        case trojkat: strcpy(name,"trojkat");
            double h;
            printf("Podaj strone i wysokosc trojkata: ");
            scanf("%lf%lf",&a,&h);
            area=triangle(a,h);
            break;
    }
    switch(c){
        case czerwony: strcpy(color,"czerwony");
            break;
        case pomaranczowy: strcpy(color,"pomaranczowy");
            break;
        case zolty: strcpy(color,"zolty");
            break;
        case zielony: strcpy(color,"zielony");
            break;
        case niebieski: strcpy(color,"niebieski");
            break;
        case blekitny: strcpy(color,"blekitny");
            break;
        case fioletowy: strcpy(color,"fioletowy");
            break;
    }
    printf("Wybrales: %s, kolor: %s, pole: %lf", name, color, area);
}

double square(double a){
    return a*a;
}

double rectangle(double a, double b){
    return a*b;
}

double circle(double r){
    return M_PI*pow(r,2);
}

double triangle(double a, double h){
    return 0.5*a*h;
}
