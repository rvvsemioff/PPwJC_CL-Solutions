#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
#define S 100

float *length(float **tab_punkty);

int main(void){
    float **tab_punkty, *tab_odleg;
    while(1){
        tab_punkty=malloc(2*sizeof(float));
        if(tab_punkty!=NULL) break;
    }
    while(1){
        tab_punkty[0]=malloc(N*sizeof(float));
        if(tab_punkty[0]!=NULL) break;
    }
    while(1){
        tab_punkty[1]=malloc(N*sizeof(float));
        if(tab_punkty[1]!=NULL) break;
    }
    srand(time(NULL));
    printf("Tablica wspolrzednych %d punktow na plaszczyznie:\n\n", N);
    for(int i=0; i<N; i++){
        tab_punkty[0][i]=((float)rand()/RAND_MAX)*S-2/S;
        tab_punkty[1][i]=((float)rand()/RAND_MAX)*S-2/S;
        printf("Punkt %d:\nx = %f\ny = %f\n\n", i+1, tab_punkty[0][i], tab_punkty[1][i]);
    }
    tab_odleg=length(tab_punkty);
    free(tab_punkty[0]);
    free(tab_punkty[1]);
    free(tab_punkty);
    printf("Tablica odleglosci punktow od poczatku ukladu wspolrzednych:\n\n");
    for(int i=0; i<N; i++) printf("Odleglosc %d = %f\n", i+1, tab_odleg[i]);
    free(tab_odleg);
    return 0;
}

float *length(float **tab_punkty){
    float *tab_odleg;
    while(1){
        tab_odleg=malloc(N*sizeof(float));
        if(tab_odleg!=NULL) break;
    }
    for(int i=0; i<N; i++) tab_odleg[i]=sqrtf(powf(tab_punkty[0][i], 2)+powf(tab_punkty[1][i], 2));
    return tab_odleg;
}
