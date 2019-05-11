#include <stdio.h>
#define K 4

void symmetry(void);

int main(void){
    symmetry();
    return 0;
}

void symmetry(void){
    int N, i, j;
    while(1){
        printf("Podaj ilosc wierszy: ");
        scanf("%d", &N);
        if(N>0) break;
        printf("Niewlasciwa wartosc!");
    }
    float T[N][K];
    for(i=0; i<N; i++){
        for(j=0; j<K; j++){
            printf("Podaj liczbe numer [%d:%d]: ", i+1, j+1);
            scanf("%f", &T[i][j]);
        }
    }
    for(i=0; i<N; i++){
        for(j=0; j<K/2; j++){
            if(T[i][j]!=T[i][K-j-1]){
                printf("Tablica nie jest symetryczna.");
                return;
            }
        }
    }
    printf("Tablica jest symetryczna.");
}
