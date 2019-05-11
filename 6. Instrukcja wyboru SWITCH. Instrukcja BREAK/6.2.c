#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float fun(int w);

int main(void){
    int w;
    printf("Podaj w: ");
    scanf("%d",&w);
    float res=fun(w);
    if(res==0) printf("Brak rozwiazan.");
    else printf("w = %0.2f", res);
    return 0;
}

float fun(int w){
    switch(w){
        case 2: return powf(1.5+2,2);
        case 4: return 1.5+2/2+4*4;
        case 8: return 1.5-1.5*8;
        default: return 0;
    }
}
