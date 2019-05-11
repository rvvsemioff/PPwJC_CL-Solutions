#include <stdio.h>
#include <string.h>

int main(void){
    int n, c, i, j, div;
    char num[57], buf_1[58];
    strcpy(num, "");
    for(; ; ){
        printf("Podaj ilosc liczb pierwszych do znalezienia: ");
        scanf("%d", &n);
        if(n<1 || n>20) printf("Niewlasciwe dane!\n");
        else break;
    }
    c=n;
    for(i=2; c; i++){
        div=0;
        for(j=2; j<i; j++){
            if(i%j==0) div=1;
        }
        if(div==0){
            sprintf(buf_1, "%d\n", i);
            strcat(num, buf_1);
            c--;
        }
    }
    strcpy(num, strcat(strcpy(buf_1, "\n"), num));
    printf("%s\nIlosc liczb, ktore okazaly sie nie byc pierwszymi: %d\nKolejnosc odwrotna:\n\n", num, i-n-2);
    n=strlen(num)-1;
    for(i=n-2; i>=0; i--){
        if(num[i]=='\n'){
            for(j=i+1; j<=n; j++){
                printf("%c", num[j]);
            }
            n=i;
        }
    }
    return 0;
}
