#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void salary(void);

int main(void){
    salary();
    return 0;
}

void salary(void){
    unsigned int n, i, start=0, end=0;
    float pr_f, sum=0;
    unsigned long sal;
    char buffer_0[10], buffer_1[10], list[100];
    printf("Podaj ilosc plac: ");
    scanf("%u", &n);
    if(n==0){
        printf("Niewlasciwe dane!");
        return;
    }
    strcpy(list, "");
    for(; n; n--){
        printf("Podaj place: ");
        scanf("%lu", &sal);
        sprintf(buffer_0, "%lu", sal);
        strcat(list, buffer_0);
        strcat(list, " ");
    }
    printf("Lista plac: ");
    for(n=0; n<strlen(list); n++){
        if(list[n]==' '){
            strcpy(buffer_0, "");
            for(i=start; i<end; i++){
                sprintf(buffer_1, "%c", list[i]);
                strcat(buffer_0, buffer_1);
            }
            i=strtol(buffer_0, NULL, 10);
            if(i>5000) pr_f=i+i*0.05;
            else pr_f=i+i*0.1;
            sum+=pr_f;
            printf("%.2f ", pr_f);
            start=end+1;
        }
        end++;
    }
    printf("\nSuma nowych plac: %.2f", sum);
}
