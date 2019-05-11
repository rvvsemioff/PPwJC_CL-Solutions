#include <stdio.h>

void check(float T[], int N);

int main(void){
    int N, i;
    while(1){
        printf("Podaj ilosc liczb: ");
        scanf("%d", &N);
        if(N>0) break;
        printf("Niewlasciwe dane!\n");
    }
    float T[N];
    for(i=0; i<N; i++){
        printf("Podaj liczbe numer %d: ", i+1);
        scanf("%f", &T[i]);
        if(i!=0 && T[i]<=T[i-1]){
            printf("Niewlasciwe dane!\n");
            i--;
        }
    }
    check(T, N);
    return 0;
}

void check(float T[], int N){
    int i;
    float num, max=T[0], min=T[0];
    for(i=1; i<N; i++){
        if(T[i]>max) max=T[i];
        else if(T[i]<min) min=T[i];
    }
    num=(max+min)/2;
    for(i=0; i<N; i++){
        if(T[i]==num){
            printf("Jest liczba srednia.");
            return;
        }
    }
    printf("Niema liczby sredniej.");
}
