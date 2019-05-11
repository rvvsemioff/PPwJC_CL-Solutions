#include <stdio.h>
#define K 3

int split(float T[][K], int N, float tab_d[], float tab_u[]);

int main(void){
    int N, i, j;
    while(1){
        printf("Podaj ilosc wierszy: ");
        scanf("%d", &N);
        if(N>0) break;
        printf("Niewlasciwa wartosc!\n");
    }
    float T[N][K], tab_d[N*K], tab_u[N*K];
    for(i=0; i<N; i++){
        for(j=0; j<K; j++){
            printf("Podaj liczbe numer %d:%d :", i+1, j+1);
            scanf("%f", &T[i][j]);
        }
    }
    printf("Liczba elementow rownych 0: %d.\n\ntab_d:\n\n", split(T, N, tab_d, tab_u));
    for(i=0; tab_d[i]!=0; i++) printf("[%d] = %f\t", i+1, tab_d[i]);
    printf("\n\ntab_u:\n\n");
    for(i=0; tab_u[i]!=0; i++) printf("[%d] = %f\t", i+1, tab_u[i]);
    return 0;
}

int split(float T[][K], int N, float tab_d[], float tab_u[]){
    int i, j, n_d=0, n_u=0, n_0=0;
    for(i=0; i<N; i++){
        for(j=0; j<K; j++){
            if(T[i][j]>0){
                tab_d[n_d]=T[i][j];
                n_d++;
            }
            else if(T[i][j]<0){
                tab_u[n_u]=T[i][j];
                n_u++;
            }
            else n_0++;
        }
    }
    tab_d[n_d]=0;
    tab_u[n_u]=0;
    return n_0;
}
