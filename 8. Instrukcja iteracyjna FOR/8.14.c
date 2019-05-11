#include <stdio.h>

int main(void){
    int n, i;
    for(; ; ){
        printf("Podaj ilosc punktow: ");
        scanf("%d", &n);
        if(n>0 && n<11) break;
        else printf("Niewlasciwa wartosc!\n");
    }
    int X[n], Y[n], Z[n];
    for(i=0; i<n; i++){
        printf("Podaj wartosc X[%d]: ", i+1);
        scanf("%d", &X[i]);
        if(X[i]<0){
            printf("Niewlasciwa wartosc!\n");
            i--;
        }
        else{
            if(i==0) Y[i]=X[i];
            else Y[i]=X[i]+X[i-1];
            Z[i]=X[i]+Y[i]*Y[i];
        }
    }
    for(i=n-1; i>=0; i--) printf("%d. X[%d] = %d Y[%d] = %d Z[%d] = %d\n", i+1, i+1, X[i], i+1, Y[i], i+1, Z[i]);
    return 0;
}
