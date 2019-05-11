#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100
#define S 10000

double **select(double **tab, int *size);

int main(void){
    int size, i;
    double **tab_dane=malloc(2*sizeof(double*)), **tab_s;
    tab_dane[0]=(double*)malloc(N*sizeof(double));
    tab_dane[1]=(double*)malloc(N*sizeof(double));
    for(i=0; i<N; i++){
        tab_dane[0][i]=round(((double)rand()/RAND_MAX)*S+1)/100;
        tab_dane[1][i]=round(((double)rand()/RAND_MAX)*S);
    }
    tab_s=select(tab_dane, &size);
    for(i=0; i<size; i++) printf("\nTowar nr. %d:\ncena:\t%0.2lf\nilosc:\t%0.0lf\n", i+1, tab_s[0][i], tab_s[1][i]);
    free(tab_dane[0]);
    free(tab_dane[1]);
    free(tab_dane);
    return 0;
}

double **select(double **tab, int *size){
    double **tab_c=malloc(2*sizeof(double*)), **tab_s=malloc(2*sizeof(double*)), sel;
    tab_c[0]=(double*)malloc(N*sizeof(double));
    tab_c[1]=(double*)malloc(N*sizeof(double));
    while(1){
        printf("Podaj nizsza granice wartosci: ");
        scanf("%lf", &sel);
        if(sel>=0) break;
        printf("Niewlasciwa wartosc!\n");
    }
    *size=0;
    for(int i=0; i<N; i++){
        if(tab[0][i]>sel){
            tab_c[0][*size]=tab[0][i];
            tab_c[1][*size]=tab[1][i];
            (*size)++;
        }
    }
    tab_s[0]=(double*)malloc(*size*sizeof(double));
    tab_s[1]=(double*)malloc(*size*sizeof(double));
    for(int i=0; i<*size; i++){
        tab_s[0][i]=tab_c[0][i];
        tab_s[1][i]=tab_c[1][i];
    }
    free(tab_c[0]);
    free(tab_c[1]);
    free(tab_c);
    return tab_s;
}
