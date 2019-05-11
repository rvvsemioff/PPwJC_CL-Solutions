#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
#define K 10
#define S 100000

double *f_1(double tab[K][N], int *c_d);
double *f_2(double tab[K][N], int *c_u);

int main(void){
    int *c_d=malloc(sizeof(int)), *c_u=malloc(sizeof(int)), i, j;
    double tab[K][N], *tab_d, *tab_u;
    *c_d=0;
    *c_u=0;
    srand(time(NULL));
    for(i=0; i<K; i++){
        for(j=0; j<N; j++){
            tab[i][j]=(((double)rand()/RAND_MAX)*S)-S/2;
            if(tab[i][j]>0) ++*c_d;
            else if(tab[i][j]<0) ++*c_u;
        }
    }
    tab_d=f_1(tab, c_d);
    printf("Tablica tab_d:\n\n");
    for(i=0; i<*c_d; i++) printf("tab_d[%d] = %lf\n", i, tab_d[i]);
    free(tab_d);
    tab_u=f_2(tab, c_u);
    printf("\nTablica tab_u:\n\n");
    for(i=0; i<*c_u; i++) printf("tab_u[%d] = %lf\n", i, tab_u[i]);
    free(tab_u);
    return 0;
}

double *f_1(double tab[K][N], int *c_d){
    int i, j, k=0;
    double *tab_d=malloc(*c_d*sizeof(double));
    for(i=0; i<K; i++){
        for(j=0; j<N; j++){
            if(tab[i][j]>0){
                tab_d[k]=tab[i][j];
                k++;
            }
        }
    }
    return tab_d;
}

double *f_2(double tab[K][N], int *c_u){
    int i, j, k=0;
    double *tab_u=malloc(*c_u*sizeof(double));
    for(i=0; i<K; i++){
        for(j=0; j<N; j++){
            if(tab[i][j]<0){
                tab_u[k]=tab[i][j];
                k++;
            }
        }
    }
    return tab_u;
}
