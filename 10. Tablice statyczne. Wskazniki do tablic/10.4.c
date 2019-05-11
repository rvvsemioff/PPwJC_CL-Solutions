#include <stdio.h>
#define N 3

float multiply(float T[N][N]);
float add(float T[N][N]);

int main(void){
    int i, j;
    float T[N][N];
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            printf("Podaj liczbe [%d][%d]: ", i, j);
            scanf("%f", &T[i][j]);
        }
    }
    printf("Iloczyn elementow na glownej przekatnej - %f.\nSuma elementow nad glowna przekatna - %f.", multiply(T), add(T));
    return 0;
}

float multiply(float T[N][N]){
    int i;
    float result=1;
    for(i=0; i<N; i++) result*=T[i][i];
    return result;
}

float add(float T[N][N]){
    int i;
    float result=0;
    for(i=0; i<N-1; i++) result+=T[i][i+1];
    return result;
}
