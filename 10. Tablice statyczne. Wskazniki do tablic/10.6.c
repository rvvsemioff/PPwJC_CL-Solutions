#include <stdio.h>
#define K 4

void swap(float T[][K], int N);

int main(void){
    int N, i, j;
    while(1){
        printf("Podaj ilosc wierszy: ");
        scanf("%d", &N);
        if(N>0) break;
        printf("Niewlasciwa wartosc!\n");
    }
    float T[N][K];
    for(i=0; i<N; i++){
        for(j=0; j<K; j++){
            printf("Podaj liczbe numer %d:%d : ", i+1, j+1);
            scanf("%f", &T[i][j]);
        }
    }
    swap(T, N);
    for(i=0; i<N; i++){
        for(j=0; j<K; j++){
            printf("[%d:%d] = %f\t", i+1, j+1, T[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void swap(float T[][K], int N){
    int i;
    float buffer;
    if(K>1){
        for(i=0; i<N; i++){
            buffer=T[i][0];
            T[i][0]=T[i][K-1];
            T[i][K-1]=buffer;
        }
    }
}
