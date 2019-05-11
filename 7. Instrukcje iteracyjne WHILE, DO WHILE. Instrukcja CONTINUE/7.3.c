#include <stdio.h>

void credit(float pay, float percent);

int main(void){
    float pay, percent;
    printf("Podaj wplate: ");
    scanf("%f", &pay);
    printf("Podaj oprocentowanie: ");
    scanf("%f", &percent);
    credit(pay, 0.01*percent);
    return 0;
}

void credit(float pay, float percent){
    int i=0;
    float f_pay=pay;
    while(f_pay<2*pay){
        f_pay+=f_pay*percent;
        i++;
    }
    printf("Kwota wplaty zostala podwojona za %d miesiecy i wynosi %0.2f.", i, f_pay);
}
