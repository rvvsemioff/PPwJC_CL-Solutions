#include <stdio.h>

int create(int N, float T[], float New[]);

int main(void){
    int N, N_new, i;
    while(1){
        printf("Podaj ilosc liczb: ");
        scanf("%d", &N);
        if(N>0) break;
        printf("Niewlasciwe dane!\n");
    }
    float T[N], New[N];
    for(i=0; i<N; i++){
        printf("Podaj liczbe numer %d: ", i+1);
        scanf("%f", &T[i]);
        if(i!=0 && T[i]<=T[i-1]){
            printf("Niewlasciwe dane!\n");
            i--;
        }
    }
    N_new=create(N, T, New);
    if(N_new==0) printf("Nowa tablica jest pusta.");
    else{
        printf("\nNowa tablica\n\n");
        for(i=0; i<N_new; i++) printf("New[%d] = %f\n", i, New[i]);
    }
    return 0;
}

int create(int N, float T[], float New[]){
    int i, j, N_new=0;
    for(i=0; i<N; i++){
        if(T[i]>100){
            for(j=i; j<N; j++){
                New[N_new]=T[j];
                N_new++;
            }
            break;
        }
    }
    return N_new;
}
