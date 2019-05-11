#include <windows.h>
#include <limits.h>
#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#define BIGGER(x,y) (x>y)?x:y

int main(void){
    unsigned char N;
    int bigest=INT_MIN;
    SetConsoleOutputCP(1250);
    while(1){
        printf("WprowadŸ iloœæ liczb do porównania: ");
        scanf("%hhu", &N);
        if(N>0) break;
        puts("Niew³aœciwa wartoœæ!");
    }
    int array[N];
    for(unsigned char i=0; i<N; ++i){
        printf("Wprowad¿ wartoœæ liczby %hhu: ", i);
        scanf("%d", &array[i]);
    }
    for(unsigned char i=0; i<N; ++i) bigest=BIGGER(bigest, array[i]);
    printf("Najwiêksza liczba - %d", bigest);
    return EXIT_SUCCESS;
}
