#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    short N;
    int *part_time, i, min=RAND_MAX;
    srand(time(NULL));
    N=(int)(((double)rand()/RAND_MAX)*300);
    part_time=malloc(N*sizeof(int));
    for(i=0; i<N; i++){
        part_time[i]=rand();
        if(part_time[i]<min) min=part_time[i];
    }
    for(i=0; i<N; i++) if(part_time[i]==min) printf("Numer %d: czas %d sekund(y)\n", i+1, part_time[i]);
    free(part_time);
    return 0;
}
