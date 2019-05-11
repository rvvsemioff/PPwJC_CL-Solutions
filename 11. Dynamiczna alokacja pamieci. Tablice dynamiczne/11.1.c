#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    int tab_static[100], A, B, i, j=0, count=0;
    while(1){
        printf("Podaj granice przedzialu <A, B>: ");
        scanf("%d %d", &A, &B);
        if(A>=0 && B<=RAND_MAX && A<B) break;
        printf("Niewlasciwa(e) wartosc(i)\n");
    }
    printf("\n100 elementowa tablica statyczna:\n\n");
    srand(time(NULL));
    for(i=0; i<100; i++){
        tab_static[i]=rand();
        printf("tab_static[%d] = %d\n", i, tab_static[i]);
        if(tab_static[i]>=A && tab_static[i]<=B) count++;
    }
    printf("\nTablica dynamiczna:\n\n");
    int *tab_dynamic=(int *)malloc(count*sizeof(int));
    for(i=0; i<100; i++){
        if(tab_static[i]>=A && tab_static[i]<=B){
            tab_dynamic[j]=tab_static[i];
            printf("tab_dynamic[%d] = %d\n", j, tab_dynamic[j]);
            j++;
        }
    }
    free((void *)tab_dynamic);
    return 0;
}
