#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100
#define R 5

void new_tab(int tab[], int nt_size, int **nt);

int main(void){
    int tab[N], *nt, nt_size=0, i;
    srand(time(NULL));
    for(i=0; i<N; i++){
        tab[i]=(int)(((double)rand()/RAND_MAX)*R)-R/2;
        if(tab[i]!=0) nt_size++;
    }
    if(nt_size>0){
        new_tab(tab, nt_size, &nt);
        for(i=0; i<nt_size; i++) printf("nt[%d] = %d\n", i, nt[i]);
        free(nt);
        return 0;
    }
    printf("Tablica jest pusta");
    return 0;
}

void new_tab(int tab[], int nt_size, int **nt){
    int i, j=0;
    *nt=malloc(nt_size*sizeof(int));
    for(i=0; i<N; i++){
        if(tab[i]!=0){
            (*nt)[j]=tab[i];
            j++;
        }
    }
}
