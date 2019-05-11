#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

short menu(void);
void swapmaxmin(float T[], int N);
void swap(float T[], int N);
void power(float T[], float tab_y[], float tab_z[], int N);

int main(void){
    int N, i, j;
    while(1){
        printf("Podaj ilosc roznych liczb: ");
        scanf("%d", &N);
        if(N>0) break;
        printf("Niewlasciwa wartosc!\n");
    }
    float T[N], tab_y[N], tab_z[N];
    for(i=0; i<N; i++){
        printf("Podaj liczbe: ");
        scanf("%f", &T[i]);
        for(j=0; j<i; j++){
            if(T[j]==T[i]){
                printf("Niewlasciwa wartosc!\n");
                i--;
                break;
            }
        }
    }
    switch(menu()){
    case 1:
        swapmaxmin(T, N);
        for(i=0; i<N; i++) printf("T[%d] = %f\n", i, T[i]);
        break;
    case 2:
        swap(T, N);
        for(i=0; i<N; i++) printf("T[%d] = %f\n", i, T[i]);
        break;
    case 3:
        power(T, tab_y, tab_z, N);
        for(i=0; i<N; i++) printf("T[%d] = %f\ntab_y[%d] = %f\ntab_z[%d] = %f\n\n", i, T[i], i, tab_y[i], i, tab_z[i]);
    }

    return 0;
}

short menu(void){
    short num;
    system("@cls||clear");
    while(1){
        printf("1. zamiana miejscami elementu maksymalnego i minimalnego\n2. zapisanie elementow tablicy w odwrotnej kolejnosci\n3. utworzenie tablicy zawierajacej kwadraty danych liczb i tablicy zawierajacej szesciany danych liczb\n\n:");
        scanf("%hd", &num);
        printf("\n");
        if(num>0 && num<4) return num;
        system("@cls||clear");
    }
}

void swapmaxmin(float T[], int N){
    int i, max=0, min=0;
    float swap;
    for(i=1; i<N; i++){
        if(T[i]>T[max]) max=i;
        else if(T[i]<T[min]) min=i;
    }
    swap=T[min];
    T[min]=T[max];
    T[max]=swap;
}

void swap(float T[], int N){
    int i;
    float T_c[N];
    memcpy(T_c, T, sizeof T_c);
    for(i=0; i<N; i++) T[i]=T_c[N-1-i];
}

void power(float T[], float tab_y[], float tab_z[], int N){
    int i;
    for(i=0; i<N; i++){
        tab_y[i]=powf(T[i], 2);
        tab_z[i]=powf(T[i], 3);
    }
}
