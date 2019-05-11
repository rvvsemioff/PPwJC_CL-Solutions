#include <stdio.h>

void means(void);

int main(void){
    means();
    return 0;
}

void means(void){
    int i, e=0, o=0, even_mean=0, odd_mean=0;
    do{
        printf("Podaj liczbe: ");
        scanf("%d", &i);
        if(i==0) continue;
        if(i%2==0){
            even_mean+=i;
            e++;
        }
        else{
            odd_mean+=i;
            o++;
        }
    } while(i!=0);
    printf("Srednia liczb parzystych: %d.\nSrednia liczb nieparzystych: %d.", (e==0)?0:even_mean/e, (o==0)?0:odd_mean/o);
}
