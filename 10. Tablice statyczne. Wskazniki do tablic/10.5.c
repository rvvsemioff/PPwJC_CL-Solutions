#include <stdio.h>
#define K 3

float sum(float T[][K], int N, int j);

int main(void){
    int N, i, j;
    while(1){
        printf("Podaj liczbe wierszy: ");
        scanf("%d", &N);
        if(N>0) break;
        printf("Niewlasciwa wartosc!\n");
    }
    float T[N][K];
    for(i=0; i<N; i++){
        for(j=0; j<K; j++){
            printf("Podaj liczbe numer %d:%d :", i+1, j+1);
            scanf("%f", &T[i][j]);
        }
    }
    while(1){
        printf("Wybierz kolumne: ");
        scanf("%d", &j);
        if(j>0) break;
        printf("Niewlasciwy numer kolumny!\n");
    }
    printf("Suma elementow w kolumnie numer %d: %f.", j, sum(T, N, j-1));
    return 0;
}

float sum(float T[][K], int N, int j){
    int i, sum=0;
    for(i=0; i<N; i++) sum+=T[i][j];
    return sum;
}
