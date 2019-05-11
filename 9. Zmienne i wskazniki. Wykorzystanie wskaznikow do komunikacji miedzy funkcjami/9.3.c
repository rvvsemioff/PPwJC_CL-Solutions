#include <stdio.h>

void account(float X, float *p1, float *p2);

int main(void){
    float X, p1, p2;
    while(1){
        printf("Podaj wplate w zlotych: ");
        scanf("%f", &X);
        if(X>0) break;
        printf("Niewlasciwe dane!\n");
    }
    account(X, &p1, &p2);
    printf("Wyplata polroczna oprocentowana na 1%% - %0.2f\nWyplata roczna oprocentowana na 2%% - %0.2f", p1, p2);
}

void account(float X, float *p1, float *p2){
    *p1=X*1.0201;
    *p2=X*1.02;
}
