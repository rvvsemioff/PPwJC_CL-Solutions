#include <stdio.h>
#define K 2

void modify(float T[][K], int N, int tab_b[]);

int main(void){
    int N, i, j;
    while(1){
        printf("Podaj ilosc wierszy: ");
        scanf("%d", &N);
        if(N>0) break;
        printf("Niewlasciwa wartosc!\n");
    }
    float T[N][K];
    int tab_b[K];
    for(i=0; i<N; i++){
        for(j=0; j<K; j++){
            printf("Podaj liczbe numer [%d:%d]: ", i+1, j+1);
            scanf("%f", &T[i][j]);
        }
    }
    modify(T, N, tab_b);
    printf("Numery kolumn, w ktorych dokonano operacji zerowania elementow: ");
    for(i=0; tab_b[i]!=0; i++) printf("%d ", tab_b[i]);
    printf("\n\nNowa tablica:\n\n");
    for(i=0; i<N; i++){
        for(j=0; j<K; j++){
            printf("[%d:%d] = %f\t", i+1, j+1, T[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void modify(float T[][K], int N, int tab_b[]){
    int j, i, zero_count, n_b=0;
    for(j=0; j<K; j++){
        zero_count=0;
        for(i=0; i<N; i++) if(T[i][j]==0) zero_count++;
        if(zero_count>N/2){
            for(i=0; i<N; i++) T[i][j]=0;
            tab_b[n_b]=j+1;
            n_b++;
        }
    }
    tab_b[n_b]=0;
}
