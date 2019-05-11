#include <stdio.h>
#define K 3

short zero_check(float T[][K], int N);

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
    switch(zero_check(T, N)){
    case 0:
        printf("W podanej tablicy nie ma liczby 0.");
        break;
    case 1:
        printf("W podanej tablicy jest liczba 0.");
    }
    return 0;
}

short zero_check(float T[][K], int N){
    for(int i=0; i<N; i++) for(int j=0; j<K; j++) if(T[i][j]==0) return 1;
    return 0;
}
